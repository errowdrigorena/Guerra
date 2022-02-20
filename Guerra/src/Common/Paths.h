/*
 * Paths.h
 *
 *  Created on: Feb 17, 2022
 *      Author: iban
 */
#include <filesystem>

namespace common
{
namespace fs = std::filesystem;

const auto decks_info_path = fs::current_path()/"Decks"/"Decks_info.json";
const auto saves_info_path = fs::current_path()/"Saved"/"Saved_info.json";

void create_file(fs::path route);

void create_directory(fs::path route);

}
