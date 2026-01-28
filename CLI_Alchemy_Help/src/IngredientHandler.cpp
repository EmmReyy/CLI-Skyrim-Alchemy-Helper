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
	return eff->getIngredients();	
}

//this one is only to return all the ingredient with two common effects.
//also assume that input con only have max size two since thats how potions work. messy ik
unordered_set<Ingredient, IngredientHash, IngredientEqual> IngredientHandler::ingredientsWithEffect(unordered_set<Effect, EffectHash, EffectEqual> effects) {
	if (effects.size() > 2) {
		return;
	}

	unordered_set<Ingredient, IngredientHash, IngredientEqual> mergedSet;
	auto eff = effects.begin();
	mergedSet.merge(eff->getIngredients());
	eff = effects.end();
	mergedSet.merge(eff->getIngredients());

	return mergedSet;
}


//TODO: should probably just a vector
unordered_set<Effect, EffectHash, EffectEqual> IngredientHandler::commonEffects(Ingredient ingredient) {
	unordered_set<Effect, EffectHash, EffectEqual> commonEffs;

	//for (auto it = ingredient.getEffects().begin(); it != ingredient.getEffects().end(); it++) {
	//	effects.insert(effects.find(it));
	//}
}
vector<Effect> commonEffects(Ingredient ingA, Ingredient ingB) {

}