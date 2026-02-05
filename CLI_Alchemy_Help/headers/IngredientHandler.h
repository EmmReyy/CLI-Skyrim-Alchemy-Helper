#pragma once
#include <iostream>
#include<vector>
#include "Ingredient.h"
#include "Effect.h"
#include <unordered_set>


using namespace std;

class IngredientHandler
{
private:
	unordered_set<Ingredient, IngredientHash, IngredientEqual> ingredients;
	unordered_set<Effect, EffectHash, EffectEqual> effects;


public:
	IngredientHandler(unordered_set<Ingredient, IngredientHash, IngredientEqual>& ingredients, unordered_set<Effect, EffectHash, EffectEqual>& effects);
	unordered_set<Ingredient, IngredientHash, IngredientEqual> ingredientsWithEffect(Effect effect);
	unordered_set<Ingredient, IngredientHash, IngredientEqual> ingredientsWithEffect(unordered_set<Effect, EffectHash, EffectEqual>& effects);
	unordered_set<Ingredient, IngredientHash, IngredientEqual> ingredientsWithEffect(vector<Effect>& effects);
	unordered_set<Effect, EffectHash, EffectEqual> commonEffects(vector<Ingredient> inputIngredients);
	
	
};

