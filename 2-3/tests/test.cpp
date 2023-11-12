#include "trees/23.hpp"
#include <iostream>

#include <ctime>
#include <cstdlib>
using namespace std; 



int main(int nargas, char** vargs){

	std::srand(std::time(0));
    trees::tt tt;
    int numValuesToInsert = 10000;

    int values[numValuesToInsert];

    for (int i = 0; i < numValuesToInsert; ++i) {
        int randomValue = std::rand() % 100000000;
		values[i] = randomValue;
    }

    clock_t startInsert = clock();

    for (int i = 0; i < numValuesToInsert; ++i) {
        tt.insert(values[i]);
    }

    clock_t endInsert = clock();
    double elapsedTimeInsert = double(endInsert - startInsert) / CLOCKS_PER_SEC;

    std::cout << "Tiempo de inserción: " << elapsedTimeInsert << " segundos" << std::endl;

	
/* 	tt.traverse();

	trees::ttNode* node = nullptr;
	for (int k = 1; k<= 100; k++ ){
		node = tt.k_element(k);
		if (node != nullptr){
			std::cout << "k = " <<k << " --> "<< node->getData() << std::endl;
		}
	}
 */

    int numValuesToSearch = numValuesToInsert;
    clock_t startSearch = clock();

    for (int i = 0; i < numValuesToSearch; ++i) {
        tt.find(values[i]);
    }

    clock_t endSearch = clock();
    double elapsedTimeSearch = double(endSearch - startSearch) / CLOCKS_PER_SEC;

    std::cout << "Tiempo de búsqueda: " << elapsedTimeSearch << " segundos" << std::endl;

	return 0;
}
