/*
 * Paths.h
 *
 *  Created on: Feb 17, 2022
 *      Author: iban
 */
#include <filesystem>

namespace fs = std::filesystem;

const auto decks_info_path = fs::current_path()/"Decks"/"Decks_info.json";
