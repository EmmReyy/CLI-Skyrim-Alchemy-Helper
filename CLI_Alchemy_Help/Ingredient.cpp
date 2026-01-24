#include "Ingredient.h"
#include <iostream>
#include <unordered_set>

using namespace std;

Ingredient::Ingredient(string name, unordered_set<string> effects) {
	this->name = name;
	this->effects = effects;
}

string Ingredient::getName() const {
	return name;
}

unordered_set<string> Ingredient::getEffects() const {
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

	for (auto& effect : i.getEffects()) {
		effects += effect;
		effects += ", ";
	}

	os << i.getName() << " : " << "{" << effects << "}";
	return os;
}