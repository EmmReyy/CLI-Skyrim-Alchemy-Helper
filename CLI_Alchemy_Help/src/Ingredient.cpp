#include "Ingredient.h"
#include <iostream>
#include <unordered_set>

Ingredient::Ingredient(string name, unordered_set<string> effects) {
	this->name = name;
	this->effects = effects;
}

string Ingredient::getIngredientName() const {
	return name;
}

const unordered_set<string>& Ingredient::getEffects() const {
	return effects;
}

bool Ingredient::hasEffect(const string& effect) {
	return effects.find(effect) != effects.end();
}

bool Ingredient::operator==(const Ingredient& other) const {
	return name == other.name;
}

ostream& operator<<(ostream& os, const Ingredient& i) {

	string effects;
	bool first = true;
	for (auto& effect : i.getEffects()) {
		if (!first) {
			effects += ", ";
		}
		effects += effect;
		first = false;
	}

	os << i.getIngredientName() << " : " << "{" << effects << "}";
	return os;
}