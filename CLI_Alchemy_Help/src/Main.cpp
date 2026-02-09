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

//globals
std::unordered_set<Ingredient, IngredientHash, IngredientEqual> ingredients;
std::unordered_set<Effect, EffectHash, EffectEqual> effects;
IngredientHandler* handler = nullptr;

bool isEqual(std::string_view a, std::string_view b) {
	if (a.size() != b.size()) {
		return false;
	}

	return std::equal(a.begin(), a.end(), b.begin(),
		[](unsigned char c1, unsigned char c2) {
			return std::tolower(c1) == std::tolower(c2);
		});
}

static void effectSetPrinter(const std::unordered_set<Effect, EffectHash, EffectEqual>& effectsSet) {
	for (const auto& eff : effectsSet) {
		std::cout << eff << std::endl;
	}
}

static void ingredientSetPrinter(const std::unordered_set<Ingredient, IngredientHash, IngredientEqual>& ingredientsSet) {
	for (const auto& eff : ingredientsSet) {
		std::cout << eff << std::endl;
	}
}

static void ingredientPotionBuilder(const std::vector<Ingredient>& inputIngredients) {
	std::unordered_set<Effect, EffectHash, EffectEqual> commonEffs = handler->commonEffects(inputIngredients);
	std::cout << "Resulting potion will be: " << std::endl;
	for (auto item : commonEffs) {
		std::cout << "    " << item.getEffectName() << std::endl;
	}
}

static void effectsPotionBuilder(const std::vector<Effect> effsInput) {
	std::unordered_set<Ingredient, IngredientHash, IngredientEqual> ingsWithEffs = handler->ingredientsWithEffect(effsInput);
	std::cout << "Possible ingredients are: " << std::endl;
	for (auto item : ingsWithEffs) {
		std::cout << "    " << item.getIngredientName() << std::endl;
	}
}

static void inputLoop() {
	while (true) {
		std::string in = "";
		std::vector<std::string> words;
		std::getline(std::cin, in);

		std::istringstream ss(in);
		std::string holder;
		while (ss >> holder) {
			if (holder != "to")holder[0] = static_cast<char>(std::toupper(static_cast<unsigned char>(holder[0])));
			words.push_back(holder);
		}

		if (words.empty()) {
			std::cout << "no command entered" << std::endl;
			continue;
		}

		if (isEqual(words[0], "exit")) {
			std::cout << "Closed." << std::endl;
			break;
		}
		else if (in.empty()) {
			std::cout << "No command entered." << std::endl;

		}
		else if (isEqual(words[0], "help")) {
			std::cout << "list of commands are: \n" << std::endl;
			std::cout << "ingredients == lists all ingredients. " << std::endl;
			std::cout << "ingredient [ingredient name] [ingredient name] == lists other ingredients needed to build a potion with the ingredients' common effects." << std::endl;
			std::cout << "effects == lists all the effects." << std::endl;
			std::cout << "effect [effect ame] [effect name] == lists all the possible ingredients needed to build potion with the effect.";
		}
		else if (isEqual(words[0], "ingredients")) {
			ingredientSetPrinter(ingredients);
		}
		else if (isEqual(words[0], "effects")) {
			effectSetPrinter(effects);
		}
		else if (isEqual(words[0], "ingredient")) {
			if (words.size() == 1) {
				std::cout << "No arguments read" << std::endl;
				break;
			}
			std::vector<Ingredient> ingsInput;
			std::string line = "";
			for (int i = 1; i < words.size(); i++) {

				if (line != "")line += " ";
				line += words[i];

				if (ingredients.find(line) != ingredients.end()) {
					auto item = ingredients.find(line);
					ingsInput.push_back(*item);
					line = "";
				}

			}
			if (!ingsInput.empty())ingredientPotionBuilder(ingsInput);
			else std::cout << "unrecognized arguments" << std::endl;
		}
		else if (isEqual(words[0], "effect")) {
			if (words.size() == 1) {
				std::cout << "no arguments read" << std::endl;
				continue;
			}

			std::vector<Effect> effsInput;
			std::string line = "";

			for (int i = 1; i < words.size(); i++) {
				if (line != "")line += " ";
				line += words[i];

				if (effects.find(line) != effects.end()) {

					auto item = effects.find(line);
					effsInput.push_back(*item);
					line = "";
				}
			}

			if (!effsInput.empty())effectsPotionBuilder(effsInput);
			else std::cout << "unrecognized arguments" << std::endl;
		}
		else {
			std::cout << "\"" << words[0] << "\"" << "not recoginzed as a command." << std::endl;
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
	handler = new IngredientHandler(ingredients, effects);

	std::cout << "Welcome to Potion Builder" << std::endl;
	inputLoop();
	std::vector<Effect> effsA;
	auto effA = effects.find("Weakness to Frost");
	auto effB = effects.find("Invisibility");
	effsA.push_back(*effA);
	effsA.push_back(*effB);

	//ingredientSetPrinter(handler->ingredientsWithEffect(effsA));
	delete handler;
	handler = nullptr;
	return 0;
}
