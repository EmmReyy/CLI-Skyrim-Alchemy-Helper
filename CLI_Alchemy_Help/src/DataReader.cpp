
#include "DataReader.h"
#include "Ingredient.h"
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
		unordered_set<string> effects = {};

		for (string effect : item["effects"]) {

			if (effect.find('(') != string::npos && effect.find(')') != string::npos) {
				int start = effect.find('(');
				int end = effect.find(')');

				effect.erase(start, (end - start + 1));
			}

			effects.insert(effect);
		}

		ingredients.insert(Ingredient(name, effects));
	}
	return true;
}

unordered_set<Ingredient> DataReader::getIngredients()
{
	return ingredients;
}

