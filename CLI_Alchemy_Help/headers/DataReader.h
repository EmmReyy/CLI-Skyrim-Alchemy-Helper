#pragma once
#include <iostream>
#include <fstream>
#include <set>
#include "Ingredient.h"
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

class DataReader
{
public:
	DataReader() = default;
	unordered_set<Ingredient> getIngredients();
	bool loadIngredientFile(const string& filename);
	bool parseIngredientFile();

private:
	json ingredientFile;
	unordered_set<Ingredient> ingredients;
};

