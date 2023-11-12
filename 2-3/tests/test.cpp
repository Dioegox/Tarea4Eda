#include "trees/23.hpp"
#include <iostream>

using namespace std; 

int main(int nargas, char** vargs){
	trees::tt tt;
	int input;
	while (input != -1){
		cout << "valor a añadir: " << endl;
		cin >> input;
		tt.insert(input);
		tt.traverse();
	}

	tt.traverse();
	return 0;
}
