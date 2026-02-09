#include <iostream>
#include <unordered_set>
#include <functional>
#include "Ingredient.h"
#include "Effect.h"

Effect::Effect(std::string name, std::unordered_set<Ingredient, IngredientHash, IngredientEqual> ingredients) {
	this->name = name;
	this->effectIngredients = ingredients;
}

std::string Effect::getEffectName() const {
	return name;
}

void Effect::addEffectIngredient(const Ingredient& ing) const {
	effectIngredients.insert(ing);
}

const std::unordered_set<Ingredient, IngredientHash, IngredientEqual>& Effect::getIngredients() const {
	return effectIngredients;
}

bool Effect::operator==(const Effect& other) const {
	return name == other.name;
}

std::ostream& operator<<(std::ostream& os, const Effect& e) {
	std::string ingredients;
	bool first = true;

	for (auto& ing : e.getIngredients()) {
		if (!first) {
			ingredients += ", ";
		}
		ingredients += ing.getIngredientName();
		first = false;
	}

	os << e.getEffectName() << "{" << ingredients << "}" << std::endl;

	return os;
}
