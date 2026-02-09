#pragma once
#include <iostream>
#include <string>
#include <unordered_set>
#include <functional>

class Ingredient
{

public:
	Ingredient(std::string name, std::unordered_set<std::string> effects);
	std::string getIngredientName() const;
	const std::unordered_set<std::string>& getEffects() const;
	bool hasEffect(const std::string& name) const;

	bool operator==(const Ingredient& other) const;

	friend std::ostream& operator<<(std::ostream& os, const Ingredient& i);


private:
	std::string name;
	std::unordered_set<std::string> effects = {};

};

struct IngredientHash {
	using is_transparent = void;

	size_t operator()(const Ingredient& i) const {
		return std::hash<std::string>{}(i.getIngredientName());
	}

	size_t operator()(const std::string& name) const {
		return std::hash<std::string>{}(name);
	}
};

struct IngredientEqual {
	using is_transparent = void;

	bool operator()(const Ingredient& setIngredient, const Ingredient& checkIngredient) const {
		return setIngredient.getIngredientName() == checkIngredient.getIngredientName();
	}

	bool operator()(const std::string& name, const Ingredient& i) const {
		return name == i.getIngredientName();
	}

	bool operator()(const Ingredient& i, const std::string& name) const {
		return name == i.getIngredientName();
	}
};
