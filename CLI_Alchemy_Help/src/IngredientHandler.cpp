#include "IngredientHandler.h"
#include <iostream>
#include<vector>
#include "Ingredient.h"
#include "Effect.h"
#include <unordered_set>

using namespace std;

IngredientHandler::IngredientHandler(unordered_set<Ingredient, IngredientHash, IngredientEqual> ingredients, unordered_set<Effect, EffectHash, EffectEqual> effects) {
	this->ingredients = ingredients;
	this->effects = effects;
}

unordered_set<Ingredient, IngredientHash, IngredientEqual> IngredientHandler::ingredientsWithEffect(Effect effect) {
	auto eff = effects.find(effect.getEffectName());
	if (eff == effects.end()) {
		return {};
	}
	return eff->getIngredients();	
}


unordered_set<Ingredient, IngredientHash, IngredientEqual> IngredientHandler::ingredientsWithEffect(unordered_set<Effect, EffectHash, EffectEqual> effects) {
	unordered_set<Ingredient, IngredientHash, IngredientEqual> mergedSet;

	if (effects.size() > 2) {
		return mergedSet;
	}

	auto eff = effects.begin();
	mergedSet.merge(eff->getIngredients());
	eff++;
	mergedSet.merge(eff->getIngredients());

	return mergedSet;
}

//this one is only to return all the ingredient with two common effects.
//also assume that input con only have max size two since thats how potions work. messy ik
//TODO: should probably just a vector
unordered_set<Effect, EffectHash, EffectEqual> IngredientHandler::commonEffects(vector<Ingredient>inputIngredients) {
	unordered_set<Effect, EffectHash, EffectEqual> commonEffs;

	if (inputIngredients.size() > 2 || inputIngredients.size() < 1){
		cout << "Can only have one or two ingredients." << endl;

	}

	if (ingredients.size() == 1) {
		for (auto it = inputIngredients[0].getEffects().begin(); it != inputIngredients[0].getEffects().end(); it++) {
			auto effectThis = effects.find(*it);

			if (effectThis != effects.end()) {
				commonEffs.insert(*effectThis);
			}
		}
	}

	else if (ingredients.size() == 2) {
		bool hasCommon = false;

		for (auto query : inputIngredients[0].getEffects()) {
			if (inputIngredients[1].getEffects().find(query) != inputIngredients[1].getEffects().end()) {
				auto effectThis = effects.find(query);
				commonEffs.insert(*effectThis);
			}
		}
	}

	return commonEffs;
}
