#include <iostream>
#include <set>
#include <functional>
#include "Ingredient.h"

class Effect
{
private:
	string name;
	unordered_set<Ingredient> ingredients;
public:
	Effect(string name, unordered_set<Ingredient> ingredients);

	string getEffectName() const;
	unordered_set<Ingredient> getIngredients() const;
	
	bool operator==(const Effect& other) const;

	friend ostream& operator<<(ostream& os, const Effect& i);
};

template <>
struct hash<Effect> {
	size_t operator()(const Effect& e) {
		return hash<string>()(e.getEffectName());
	}
};
