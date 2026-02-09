#pragma once

#include <iostream>
#include <unordered_set>
#include <functional>
#include "Ingredient.h"
#include <string>

class Effect
{
private:
	std::string name;
	mutable std::unordered_set<Ingredient, IngredientHash, IngredientEqual> effectIngredients;
public:
	Effect(std::string name, std::unordered_set<Ingredient, IngredientHash, IngredientEqual> ingredients);

	std::string getEffectName() const;
	const std::unordered_set<Ingredient, IngredientHash, IngredientEqual>& getIngredients() const;
	void addEffectIngredient(const Ingredient& ing) const;

	bool operator==(const Effect& other) const;

	friend std::ostream& operator<<(std::ostream& os, const Effect& i);

};



struct EffectHash {
	using is_transparent = void;

	size_t operator()(const Effect& e) const {
		return std::hash<std::string>{}(e.getEffectName());
	}

	size_t operator()(const std::string& name) const {
		return std::hash<std::string>{}(name);
	}

	size_t operator()(const char* name) const noexcept {
		return std::hash<std::string>{}(std::string(name));
	}
};

struct EffectEqual {
	using is_transparent = void;

	bool operator()(const Effect& setEffect, const Effect& checkEffect) const {
		return setEffect.getEffectName() == checkEffect.getEffectName();
	}

	bool operator()(const std::string& name, const Effect& e) const {
		return name == e.getEffectName();
	}

	bool operator()(const char* name, const Effect& e) const {
		return name == e.getEffectName();
	}

	bool operator()(const Effect& e, const std::string& name) const {
		return name == e.getEffectName();
	}

	bool operator()(const Effect& e, const char* name) const {
		return name == e.getEffectName();
	}
};
