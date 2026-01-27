#pragma once
#include <iostream>
#include <fstream>
#include <set>
#include "Ingredient.h"
#include "Effect.h"
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

class DataReader
{
public:
	DataReader() = default;
	unordered_set<Ingredient, IngredientHash, IngredientEqual> getIngredients();
	unordered_set<Effect, EffectHash, EffectEqual> getEffects();
	bool loadIngredientFile(const string& filename);
	bool parseIngredientFile();
	

private:
	json ingredientFile;
	unordered_set<Ingredient, IngredientHash, IngredientEqual> ingredients;
	unordered_set<Effect, EffectHash, EffectEqual> effects;
};

