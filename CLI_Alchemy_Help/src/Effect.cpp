#include <iostream>
#include <set>
#include <functional>
#include "Ingredient.h"
#include "Effect.h"

Effect::Effect(string name, unordered_set<Ingredient, IngredientHash, IngredientEqual> ingredients) {
	this->name = name;
	this->effectIngredients = ingredients;
}

string Effect::getEffectName() const{
	return name;
}

void Effect::addEffectIngredient(const Ingredient& ing) const{
	effectIngredients.insert(ing);
}


unordered_set<Ingredient, IngredientHash, IngredientEqual> Effect::getIngredients() const {
	return effectIngredients;
}

bool Effect::operator==(const Effect& other) const {
	return name == other.name;
}

ostream& operator<<(ostream& os, const Effect& e) {
	string ingredients;
	bool first = true;

	for (auto& ing : e.getIngredients()) {
		if (!first) {
			ingredients += ", ";
		}
		ingredients += ing.getIngredientName();
		first = false;
	}

	os << e.getEffectName() << "{" << ingredients << "}" << endl;

	return os;
}