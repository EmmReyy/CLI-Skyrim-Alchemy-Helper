#include <iostream>
#include "Ingredient.h"
#include "Effect.h"
#include "DataReader.h"
#include "IngredientHandler.h"
#include <vector>

using namespace std;

class Main
{
	

};

void effectSetPrinter(unordered_set<Effect, EffectHash, EffectEqual> effectsSet) {
	for (const auto& eff : effectsSet) {
		cout << eff << endl;
	}
}

void ingredientSetPrinter(unordered_set<Ingredient, IngredientHash, IngredientEqual> ingredientsSet) {
	for (const auto& eff : ingredientsSet) {
		cout << eff << endl;
	}
}

int main(int argc, char* argv[]) {
	DataReader dr;
	
	dr.loadIngredientFile("C:\\Users\\gobbl\\source\\repos\\CLI_Alchemy_Help\\CLI_Alchemy_Help\\data.json");
	dr.parseIngredientFile();
	unordered_set<Ingredient, IngredientHash, IngredientEqual> ingredients = dr.getIngredients();
	unordered_set<Effect, EffectHash, EffectEqual> effects = dr.getEffects();

	//for (auto& ing : effects) {
	//	cout << ing<< "\n" << endl;
	//}
	unordered_set<string> effectsA = { "Weakness to Frost", "Fortify Sneak", "Weakness to Poison", "Fortify Restoration" };
	unordered_set<string> effectsB = { "Restore Health", "Fortify Light Armor", "Resist Shock", "Weakness to Frost" };
	Ingredient ingA = Ingredient("Abecean Longfin", effectsA);
	Ingredient ingB = Ingredient("Ash Hopper Jelly", effectsB);

	auto it = effects.find("Weakness to Frost");
	Effect effA = Effect("Weakness to Frost", it->getIngredients());

	IngredientHandler ingHandler = IngredientHandler(ingredients, effects);
	vector<Ingredient>ings = { ingA, ingB };
	effectSetPrinter(ingHandler.commonEffects(ings));
	//ingredientSetPrinter(ingHandler.ingredientsWithEffect(effA));

	return 0;
}
