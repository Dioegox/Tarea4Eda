#include "trees/abb.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main(int nargas, char** vargs){

	std::srand(std::time(0));
    trees::ABB abb;
    int numValuesToInsert = 1000000;

    int values[numValuesToInsert];

    for (int i = 0; i < numValuesToInsert; ++i) {
        int randomValue = std::rand() % 100000000;
		values[i] = randomValue;

    }

    clock_t startInsert = clock();

    for (int i = 0; i < numValuesToInsert; ++i) {
        abb.insert(values[i]);
    }

	abb.updateSize();

    clock_t endInsert = clock();
    double elapsedTimeInsert = double(endInsert - startInsert) / (CLOCKS_PER_SEC / 1000);

    std::cout << "Tiempo de inserción: " << elapsedTimeInsert << " milisegundos" << std::endl;

	
/* 	abb.traverse();

	trees::ABBNode* node = nullptr;
	for (int k = 1; k<= 100; k++ ){
		node = abb.k_element(k);
		if (node != nullptr){
			std::cout << "k = " <<k << " --> "<< node->getData() << std::endl;
		}
	} */


    int numValuesToSearch = numValuesToInsert;
    clock_t startSearch = clock();

    for (int i = 0; i < numValuesToSearch; ++i) {
        abb.find(values[i]);
    }

    clock_t endSearch = clock();
    double elapsedTimeSearch = double(endSearch - startSearch) / (CLOCKS_PER_SEC / 1000);

    std::cout << "Tiempo de búsqueda: " << elapsedTimeSearch << " milisegundos" << std::endl;

	return 0;
}