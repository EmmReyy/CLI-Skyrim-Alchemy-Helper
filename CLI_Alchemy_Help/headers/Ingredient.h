#pragma once
#include <iostream>
#include <string>
#include <unordered_set>
#include <functional>

using namespace std;

class Ingredient
{

public:
	Ingredient(string name, unordered_set<string> effects);
	string getIngredientName() const;
	unordered_set<string> getEffects() const;
	bool hasEffect(const string& name);

	bool operator==(const Ingredient& other) const;

	friend ostream& operator<<(ostream& os, const Ingredient& i);


private:
	string name;
	unordered_set<string> effects = {};

};

struct IngredientHash {
	using is_transparent = void;

	size_t operator()(const Ingredient& i) const {
		return hash<string>{}(i.getIngredientName());
	}
	
	size_t operator()(const string& name) const {
		return hash<string>{}(name);
	}
};

struct IngredientEqual {
	using is_transparent = void;

	bool operator()(const Ingredient& setIngredient, const Ingredient& checkIngredient) const {
		return setIngredient.getIngredientName() == checkIngredient.getIngredientName();
	} 

	bool operator()(const string& name, const Ingredient& i) {
		return name == i.getIngredientName();
	}

	bool operator()(const Ingredient& i, const string& name) {
		return name == i.getIngredientName();
	}
};