#include "DataReader.h"
#include "Ingredient.h"
#include "Effect.h"
#include <unordered_set>
#include <fstream>
#include "json.hpp"
#include <iostream>

bool DataReader::loadIngredientFile(const std::string& filename) {
	std::ifstream file(filename);

	if (!file.is_open()) {
		std::cerr << "Error! Couldn't open file" << std::endl;
		return false;
	}
	else {
		file >> ingredientFile;
	}

	return true;
}

bool DataReader::parseIngredientFile() {

	if (ingredientFile.is_null()) {
		std::cerr << "Error! the json file is empty" << std::endl;
	}

	for (const auto& item : ingredientFile) {
		std::string name = item["name"];
		std::unordered_set<std::string> ingredientEffects = {};

		for (std::string effect : item["effects"]) {

			if (effect.find('(') != std::string::npos && effect.find(')') != std::string::npos) {
				size_t start = effect.find('(');
				size_t end = effect.find(')');

				effect.erase(start, (end - start + 1));
			}
			ingredientEffects.insert(effect);
			effects.insert(Effect(effect, {}));
		}
		Ingredient ing(Ingredient(name, ingredientEffects));
		ingredients.insert(ing);

		for (auto& effectName : ingredientEffects) {
			effects.insert(Effect(effectName, {}));
			auto it = effects.find(effectName);
			it->addEffectIngredient(ing);
		}
	}
	return true;
}

std::unordered_set<Ingredient, IngredientHash, IngredientEqual> DataReader::getIngredients()
{
	return ingredients;
}

std::unordered_set<Effect, EffectHash, EffectEqual> DataReader::getEffects() {
	return effects;
}
