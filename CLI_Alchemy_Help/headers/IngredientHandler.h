#pragma once
#include <iostream>
#include <vector>
#include "Ingredient.h"
#include "Effect.h"
#include <unordered_set>

class IngredientHandler
{
private:
	std::unordered_set<Ingredient, IngredientHash, IngredientEqual> ingredients;
	std::unordered_set<Effect, EffectHash, EffectEqual> effects;

public:
	IngredientHandler(
		std::unordered_set<Ingredient, IngredientHash, IngredientEqual>& ingredients,
		std::unordered_set<Effect, EffectHash, EffectEqual>& effects
	);

	std::unordered_set<Ingredient, IngredientHash, IngredientEqual> ingredientsWithEffect(Effect effect);
	std::unordered_set<Ingredient, IngredientHash, IngredientEqual> ingredientsWithEffect(std::unordered_set<Effect, EffectHash, EffectEqual>& effects);
	std::unordered_set<Ingredient, IngredientHash, IngredientEqual> ingredientsWithEffect(std::vector<Effect> effects);
	std::unordered_set<Effect, EffectHash, EffectEqual> commonEffects(std::vector<Ingredient> inputIngredients);
};
