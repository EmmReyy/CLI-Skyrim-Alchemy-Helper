#include <iostream>
#include "Ingredient.h"
#include "DataReader.h"

using namespace std;

class Main
{
	

};

int main(int argc, char* argv[]) {
	DataReader dr;
	
	dr.loadIngredientFile("C:\\Users\\gobbl\\source\\repos\\CLI_Alchemy_Help\\CLI_Alchemy_Help\\data.json");
	dr.parseIngredientFile();
	unordered_set<Ingredient> ingredients = dr.getIngredients();

	for (auto& ing : ingredients) {
		cout << ing<< "\n" << endl;
	}

	return 0;
}
