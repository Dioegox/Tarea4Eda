#include "trees/avl.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main(int nargas, char** vargs){

	std::srand(std::time(0));
    trees::AVL avl;
    int numValuesToInsert = 1000000;

	int values[numValuesToInsert];
    for (int i = 0; i < numValuesToInsert; ++i) {
        int randomValue = std::rand() % 100000000;
		values[i] = randomValue;
    }


    clock_t startInsert = clock();

    for (int i = 0; i < numValuesToInsert; ++i) {
        avl.insert(values[i]);
    }

    clock_t endInsert = clock();
    double elapsedTimeInsert = double(endInsert - startInsert) / (CLOCKS_PER_SEC / 1000);

    std::cout << "Tiempo de inserción: " << elapsedTimeInsert << " segundos" << std::endl;

	
/* 	avl.traverse();

	trees::ABBNode* node = nullptr;
	for (int k = 1; k<= 100; k++ ){
		node = avl.k_element(k);
		if (node != nullptr){
			std::cout << "k = " <<k << " --> "<< node->getData() << std::endl;
		}
	} */


    int numValuesToSearch = numValuesToInsert;
    clock_t startSearch = clock();

    for (int i = 0; i < numValuesToSearch; ++i) {
        avl.find(values[i]);
    }

    clock_t endSearch = clock();
    double elapsedTimeSearch = double(endSearch - startSearch) / (CLOCKS_PER_SEC / 1000);

    std::cout << "Tiempo de búsqueda: " << elapsedTimeSearch << " segundos" << std::endl;

	return 0;
}
