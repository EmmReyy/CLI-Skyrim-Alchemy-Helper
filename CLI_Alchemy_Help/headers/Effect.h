#include <iostream>
#include <set>
#include <functional>
#include "Ingredient.h"

class Effect
{
private:
	string name;
	unordered_set<string> ingredients;
public:
	Effect(string name, unordered_set<string> ingredients);

	string getEffect() const;
	unordered_set<string> getIngredients() const;
	
	bool operator==(const Ingredient& other) const;

	friend ostream& operator<<(ostream& os, const Ingredient& i);
};

template <>

struct hash<Effect> {
	size_t operator()(const Effect& e) {
		return hash<string>()(e.getEffect());
	}
};
