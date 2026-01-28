#pragma once

#include <iostream>
#include <unordered_set>
#include <functional>
#include "Ingredient.h"

class Effect
{
private:
	string name;
	mutable unordered_set<Ingredient, IngredientHash, IngredientEqual> effectIngredients;
public:
	Effect(string name, unordered_set<Ingredient, IngredientHash, IngredientEqual> ingredients);

	string getEffectName() const;
	unordered_set<Ingredient, IngredientHash, IngredientEqual> getIngredients() const;
	void addEffectIngredient(const Ingredient& ing) const;
	
	bool operator==(const Effect& other) const;

	friend ostream& operator<<(ostream& os, const Effect& i);

};

	

struct EffectHash {
	using is_transparent = void;
	size_t operator()(const Effect&e ) const {
		return hash<string>{}(e.getEffectName());
	}

	size_t operator()(const string& name) const {
		return hash<string>{}(name);
	}
};

struct EffectEqual {
	using is_transparent = void;

	bool operator()(const Effect& setEffect, const Effect& checkEffect) const {
		return setEffect.getEffectName() == checkEffect.getEffectName();
	}

	bool operator()(const string& name, const Effect& e) const {
		return name == e.getEffectName();
	}

	bool operator()(const Effect& e, const string& name ) const {
		return name == e.getEffectName();
	}
};