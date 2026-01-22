#pragma once
#include <iostream>
#include <unordered_set>

using namespace std;

class Ingredient
{

public:
	Ingredient(string name, unordered_set<string> effects);
	string getName();
	unordered_set<string> getEffects();
	
	
private:
	string name;
	unordered_set<string> effects = {};


};

