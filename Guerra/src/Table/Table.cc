/*
 * Table.cc
 *
 *  Created on: Feb 11, 2022
 *      Author: iban
 */

#include "Table.h"
#include "../Common/Paths.h"
#include "../JSON/JSONOperations.h"

#include <random>
#include <chrono>
#include <algorithm>
#include <iostream>

namespace table
{

namespace
{
Round_result determine_result(const std::string& winner);
std::map<std::string, card::Card> arrange_game(
		std::array<Player, number_players> &players, Deck &deck);
std::pair<std::string, card::Card> determine_winner(
		const std::map<std::string, card::Card> &round);

Round_result determine_result(const std::string& winner)
{
	Round_result result{Round_result::Winner };

	if(winner == "NO_WINNER")
	{
		result = Round_result::Draw;
	}

	return result;
}

std::map<std::string, card::Card> arrange_game(
		std::array<Player, number_players> &players, Deck &deck)
{
	std::map<std::string, card::Card> name_card{};

	for (auto& player : players)
	{
		auto played_card = player.play_card();
		name_card[player.get_name()] = played_card;
		deck.push_back(played_card);
	}

	return name_card;
}

std::pair<std::string, card::Card> determine_winner(
		const std::map<std::string, card::Card> &round)
{
	std::pair<std::string, card::Card> winner{};

	for (auto& player_card : round)
	{
		if( player_card.second > winner.second )
		{
			winner = player_card;
		}
		else if( player_card.second == winner.second )
		{
			winner = {"NO_WINNER", winner.second};
		}
	}

	return winner;
}
}

Table::Table(std::vector<std::string> player_names, std::string deck_model) :
		players_{Player{1, player_names[0]}, Player{2, player_names[1]} },
		deck_{json::load_card_deck_from_file(decks_info_path, deck_model) },
		id_colour_{json::load_colour_dictionary_from_file(decks_info_path, deck_model) },
		value_name_{json::load_values_dictionary_from_file(decks_info_path, deck_model) },
		total_card_number_{deck_.size() }
{
	; //do nothing
}

Table::~Table()
{
	; //do nothing
}

void Table::shuffle_deck()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle (deck_.begin(), deck_.end(), std::default_random_engine(seed));
}

void Table::deal_cards()
{
	auto player_number = players_.size();

	auto extra_card_number = total_card_number_ % player_number;
	for (auto& player : players_)
	{
		auto cards_in_players_deck = ( total_card_number_ / player_number );
		auto start_it = deck_.begin() +( (player.get_id()-1) * cards_in_players_deck);

		Deck player_deck{start_it, (start_it + cards_in_players_deck) };

		if( player.get_id() <= extra_card_number )
		{
			auto card_position = (cards_in_players_deck * player_number)
					+ player.get_id();
			player_deck.push_back( deck_.at(card_position) );
		}

		player.provide_cards(player_deck);
	}

	deck_.clear();
	last_round_result_ = "Se han barajado y repartido las cartas";
}

std::string Table::notate_round(const std::map<std::string, card::Card>& round,
						 const std::pair<std::string, card::Card>& winner,
						 const Round_result& result)
{
	std::stringstream round_commented{};

	for( auto& player_card : round )
	{
		round_commented << player_card.first << " ha jugado: " <<
				value_name_[player_card.second.get_value()] << " de " <<
				id_colour_[player_card.second.get_colour()] << "\n";
	}

	if(result == Round_result::Winner)
	{
		round_commented << "El ganador es: " << winner.first << " con su " <<
				value_name_[winner.second.get_value()] << " de " <<
				id_colour_[winner.second.get_colour()] << "\n";

		round_commented << "Se lleva " << deck_.size() << " cartas.";
	}
	else
	{
		round_commented << "La ronda ha acabado en empate.\n";
		round_commented << "Hay " << deck_.size() << " cartas en la mesa.";
	}

	return round_commented.str();
}

void Table::give_regard_to_winner(const std::string& winner)
{
	if(winner == "NO_WINNER")
	{
		return;
	}

	auto winner_it =std::find_if(players_.begin(), players_.end(),
			[&](const Player& player){ return player.get_name() == winner;});

	winner_it->provide_cards(deck_);
	deck_.clear();
}

bool Table::check_if_someone_wins()
{
	auto winner_it =std::find_if(players_.begin(), players_.end(),
			[&](const Player& player){ return player.get_number_cards() == total_card_number_;});

	bool is_winner{winner_it != players_.end()};

	if( is_winner )
	{
		std::stringstream show_winner{};
		show_winner << winner_it->get_name() << " ha ganado esta trepitante partida. \n";
		last_round_result_ = show_winner.str();
	}

	return is_winner;
}

Who_can_play Table::arrange_someone_cant_play()
{
	auto can_play_it =std::find_if(players_.begin(), players_.end(),
			[&](const Player& player){ return player.get_number_cards() > 0;});

	auto cannot_play_it =std::find_if(players_.begin(), players_.end(),
			[&](const Player& player){ return player.get_number_cards() == 0;});

	auto can_play{Who_can_play::Everyone };

	if( cannot_play_it != players_.end() )
	{
		if( can_play_it != players_.end() )
		{
			can_play_it->provide_cards(deck_);
			can_play = Who_can_play::Everyone;
			deck_.clear();
		}
		else
		{
			can_play = Who_can_play::None;
			deal_cards();
		}
	}

	return can_play;
}

void Table::perform_draw()
{
	if(arrange_someone_cant_play() != Who_can_play::Everyone)
	{
		last_round_result_ += ". No se ha podido ejecutar la acción de empate";
		return;
	}

	last_round_result_.clear();
	for(auto& player : players_)
	{
		deck_.push_back( player.play_card() );
		last_round_result_ += player.get_name() + " ha puesto una carta boca abajo \n";
	}

	last_round_result_ += "Hay " + std::to_string(deck_.size() )+ " cartas en la mesa.";
}

Round_result Table::perform_round()
{
	if(arrange_someone_cant_play() == Who_can_play::None )
	{
		return Round_result::Winner; //to continue in this state
	}

	if(check_if_someone_wins() == true)
	{
		return Round_result::Game_over;
	}

	auto round = arrange_game(players_, deck_);

	auto winner = determine_winner(round);

	auto round_result = determine_result(winner.first);

	last_round_result_ = notate_round(round, winner, round_result);

	give_regard_to_winner(winner.first);

	return round_result;
}

std::string Table::get_last_round_result() const
{
	return last_round_result_;
}

}
