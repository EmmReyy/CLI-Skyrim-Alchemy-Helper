
#include "DataReader.h"
#include "Ingredient.h"
#include "Effect.h"
#include <unordered_set>
#include <fstream>
#include "json.hpp"
#include <iostream>

using namespace std;

bool DataReader::loadIngredientFile(const string& filename) {
	ifstream file(filename);

	if (!file.is_open()) {
		cerr << "Error! Couldn't open file" << endl;
		return false;
	}
	else {
		file >> ingredientFile;
	}

	return true;
}

bool DataReader::parseIngredientFile() {

	if (ingredientFile.is_null()) {
		cerr << "Error! the json file is empty" << endl;
	}

	for (const auto& item : ingredientFile) {
		string name = item["name"];
		unordered_set<string> ingredientEffects = {};

		for (string effect : item["effects"]) {

			if (effect.find('(') != string::npos && effect.find(')') != string::npos) {
				size_t start = effect.find('(');
				size_t end = effect.find(')');

				effect.erase(start, (end - start + 1));
			}


			ingredientEffects.insert(effect);
			if (effects.find(Effect("this", {})) != effects.end()) {

			}
		}

		ingredients.insert(Ingredient(name, ingredientEffects));
	}
	return true;
}

unordered_set<Ingredient, IngredientHash, IngredientEqual> DataReader::getIngredients()
{
	return ingredients;
}

