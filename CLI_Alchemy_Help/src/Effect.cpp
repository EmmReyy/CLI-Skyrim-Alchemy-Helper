#include <iostream>
#include <set>
#include <functional>
#include "Ingredient.h"
#include "Effect.h"

Effect::Effect(string name, unordered_set<Ingredient, IngredientHash, IngredientEqual> ingredients) {
	this->name = name;
	this->ingredients = ingredients;
}

string Effect::getEffectName() const{
	return name;
}

unordered_set<Ingredient, IngredientHash, IngredientEqual> Effect::getIngredients() const {
	return ingredients;
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