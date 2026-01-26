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
	string getName() const;
	unordered_set<string> getEffects() const;
	bool hasEffect(const string& name);

	bool operator==(const Ingredient& other) const;

	friend ostream& operator<<(ostream& os, const Ingredient& i);


private:
	string name;
	unordered_set<string> effects = {};

};

template<>
struct hash<Ingredient> {
	size_t operator()(const Ingredient& i) const {
		return hash<string>()(i.getName());
	}
};


