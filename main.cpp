#include <iostream>
#include "inc/perceptron.hpp"

int main(int, char** const) {
	Perceptron{}.start();

	Perceptron perc;
	//Perceptron per{std::move(perc)};
	return EXIT_SUCCESS;
}
