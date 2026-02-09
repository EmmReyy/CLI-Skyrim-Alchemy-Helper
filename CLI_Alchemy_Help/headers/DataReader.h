#pragma once
#include <iostream>
#include <fstream>
#include <set>
#include <unordered_set>
#include "Ingredient.h"
#include "Effect.h"
#include "json.hpp"

using json = nlohmann::json;

class DataReader
{
public:
	DataReader() = default;
	std::unordered_set<Ingredient, IngredientHash, IngredientEqual> getIngredients();
	std::unordered_set<Effect, EffectHash, EffectEqual> getEffects();
	bool loadIngredientFile(const std::string& filename);
	bool parseIngredientFile();


private:
	json ingredientFile;
	std::unordered_set<Ingredient, IngredientHash, IngredientEqual> ingredients;
	std::unordered_set<Effect, EffectHash, EffectEqual> effects;
};
