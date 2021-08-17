#include <iostream>
#include "inc/perceptron.hpp"
#include "./inc/random.hpp"

int main(int, char** const) {
	Perceptron{ Random{} }.start();

	return EXIT_SUCCESS;
}
