#include <iostream>
#include "Ingredient.h"
#include "Effect.h"
#include "DataReader.h"
#include "IngredientHandler.h"
#include <sstream>
#include <vector>
#include <cctype>      
#include <algorithm>   
#include <string_view>

using namespace std;

//globals
unordered_set<Ingredient, IngredientHash, IngredientEqual> ingredients;
unordered_set<Effect, EffectHash, EffectEqual> effects;
IngredientHandler* handler = nullptr;

bool isEqual(string_view a, string_view b) {
	if (a.size() != b.size()) {
		return false;
	}

	return equal(a.begin(), a.end(), b.begin(),
		[](unsigned char c1, unsigned char c2) {
			return tolower(c1) == tolower(c2);
		});
}

static void effectSetPrinter(const unordered_set<Effect, EffectHash, EffectEqual>& effectsSet) {
	for (const auto& eff : effectsSet) {
		cout << eff << endl;
	}
}

static void ingredientSetPrinter(const unordered_set<Ingredient, IngredientHash, IngredientEqual>& ingredientsSet) {
	for (const auto& eff : ingredientsSet) {
		cout << eff << endl;
	}
}

static void ingredientPotionBuilder(const vector<Ingredient>& inputIngredients) {
	unordered_set<Effect, EffectHash, EffectEqual> commonEffs = handler->commonEffects(inputIngredients);
	cout << "Resulting potion will be: " << endl;
	for (auto item : commonEffs) {
		cout << "    " << item.getEffectName() << endl;
	}
}

static void inputLoop() {
	while (true) {
		string in = "";
		vector<string> words;
		getline(cin, in);
		
		istringstream ss(in);
		string holder;
		while (ss >> holder) {
			words.push_back(holder);
		}

		if (words.empty()) {
			cout << "no command entered" << endl;
			continue;
		}

		if (isEqual(words[0], "exit")) {
			cout << "Closed." << endl;
			break;
		}
		else if (in.empty()) {
			cout << "No command entered." << endl;

		}
		else if (isEqual(words[0], "help")) {
			cout << "list of commands are: \n" << endl;
			cout << "ingredients == lists all ingredients. " << endl;
			cout << "ingredient [ingredient name] [ingredient name] == lists other ingredients needed to build a potion with the ingredients' common effects." << endl;
			cout << "effects == lists all the effects." << endl;
			cout << "effect [effect ame] [effect name] == lists all the possible ingredients needed to build potion with the effect.";
		}
		else if (isEqual(words[0], "ingredients")) {
			ingredientSetPrinter(ingredients);
		}
		else if (isEqual(words[0], "effects")) {
			effectSetPrinter(effects);
		}
		else if (isEqual(words[0], "ingredient")) {
			if (words.size() == 1) {
				cout << "No arguments read" << endl;
				break;
			}
			vector<Ingredient> ingsInput;
			for (int i = 1; i < words.size(); i++) {


				if (ingredients.find(words[i]) != ingredients.end()) {
					auto item = ingredients.find(words[i]);
					ingsInput.push_back(*item);
				}
				else if (i + 1 < words.size() && ingredients.find(string(words[i] + " " + words[i + 1])) != ingredients.end()) {
					auto item = ingredients.find(words[i] + " " + words[i + 1]);
					ingsInput.push_back(*item);
					i++;
				}
				else {
					cout << "unrecognized arguments were read" << endl;
					break;
				}

			}
			ingredientPotionBuilder(ingsInput);
		}
		else {
			cout << "\"" << words[0] << "\"" << "not recoginzed as a command." << endl;
		}
	}
}

int main(int argc, char* argv[]) {
	//set values to declared objects
	DataReader dr;
	dr.loadIngredientFile("C:\\Users\\gobbl\\source\\repos\\CLI_Alchemy_Help\\CLI_Alchemy_Help\\data.json");
	dr.parseIngredientFile();

	ingredients = dr.getIngredients();
	effects = dr.getEffects();
	 IngredientHandler handler(ingredients, effects);
	
	cout << "Welcome to Potion Builder" << endl;
	inputLoop();

	return 0;
}
