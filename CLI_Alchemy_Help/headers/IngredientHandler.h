#pragma once
#include <iostream>
#include<vector>
#include "Ingredient.h"
#include "Effect.h"
class IngredientHandler
{
private:
	unordered_set<Ingredient, IngredientHash, IngredientEqual> ingredients;
	unordered_set<Effect, EffectHash, EffectEqual> effects;


public:
	IngredientHandler(unordered_set<Ingredient, IngredientHash, IngredientEqual> ingredients, unordered_set<Effect, EffectHash, EffectEqual> effects);
	vector<Ingredient> ingredientsWithEffect(Effect effect);
	vector<Ingredient> ingredientsWithEffect(Effect effA, Effect effB);
	vector<Effect> commonEffects(Ingredient ingredient);
	vector<Effect> commonEffects(Ingredient ingA, Ingredient ingB);
	
};

