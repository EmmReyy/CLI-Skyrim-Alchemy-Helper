#include <iostream>
#include "Ingredient.h"
#include "Effect.h"
#include "DataReader.h"

using namespace std;

class Main
{
	

};

int main(int argc, char* argv[]) {
	DataReader dr;
	
	dr.loadIngredientFile("C:\\Users\\gobbl\\source\\repos\\CLI_Alchemy_Help\\CLI_Alchemy_Help\\data.json");
	dr.parseIngredientFile();
	unordered_set<Ingredient, IngredientHash, IngredientEqual> ingredients = dr.getIngredients();
	unordered_set<Effect, EffectHash, EffectEqual> effects = dr.getEffects();

	for (auto& ing : effects) {
		cout << ing<< "\n" << endl;
	}

	return 0;
}
