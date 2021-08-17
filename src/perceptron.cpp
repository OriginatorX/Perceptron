#include <random>
#include <iostream>
#include <ctime>

#include "../inc/perceptron.hpp"

Perceptron::Perceptron(const Random& rand) 
	: random_			  (rand)
	, columnsNumber_      (4)
	, rowsNumber_         (2)  
	, outNeuron_          (0)
	, inputNeuronsNumber_ (2)
	{

	inputNeurons_    = new double  [inputNeuronsNumber_];
	synapsesWeights_ = new double  [inputNeuronsNumber_];
	learnPattern_    = new double* [columnsNumber_];
	trueOutValue_    = new double  [columnsNumber_];

	for (size_t i = 0; i < columnsNumber_; i++) 
		learnPattern_[i] = new double[rowsNumber_];

	std::cout << "Input learnPatterns:\n";

	int32_t placeholder;
	for (size_t i = 0; i < columnsNumber_; i++) {
		for (size_t j = 0; j < rowsNumber_; j++) {
			std::cin >> placeholder;
			learnPattern_[i][j] = placeholder;
		}
	}

	std::cout << "learnPatterns:\n";
	for (size_t i = 0; i < columnsNumber_; i++) {
		for (size_t j = 0; j < rowsNumber_; j++)
			std::cout << learnPattern_[i][j] << " ";
		std::cout << "\n";
	}

	std::cout << "Input right values" <<  std::endl;
	std::cin.clear();

	for (size_t i = 0; i < columnsNumber_; i++) {
		std::cin >> placeholder;
		trueOutValue_[i] = placeholder;
	}

	std::cout << "trueOutValue:\n";
	for (size_t i = 0; i < columnsNumber_; i++)
		std::cout << trueOutValue_[i] << " ";	
	std::cout << "\n";

	for (size_t i = 0; i < inputNeuronsNumber_; i++) 
		synapsesWeights_[i] = random_(0.0, 1.0) * 0.2 + 0.1;

	std::cout << "Weights:\n";
	for (size_t i = 0; i < inputNeuronsNumber_; i++) 
		std::cout << synapsesWeights_[i] << "\n";	
}

Perceptron::~Perceptron() {
	for (size_t i = 0; i < columnsNumber_; i++) 
		delete [] learnPattern_[i];
	delete [] learnPattern_;

	delete [] inputNeurons_;
	delete [] synapsesWeights_;
	delete [] trueOutValue_;
}

size_t Perceptron::evolution() {
	double gError = 0;
	size_t count  = 0;

	do {
		gError = 0;
		count++;
		for (size_t i = 0; i < columnsNumber_; i++) {
			for (size_t k = 0; k < inputNeuronsNumber_; k++)
				inputNeurons_[k] = learnPattern_[i][k];
			valueOfOutNeuron();

			double error = trueOutValue_[i] - outNeuron_;
			gError += abs(error);

			for (size_t i = 0; i < inputNeuronsNumber_; i++) 
				synapsesWeights_[i] += 0.1 * error * inputNeurons_[i];
		}
		std::cout << "Out error: " << gError << "\n";
	} while (gError != 0);
	return count;
}

void Perceptron::valueOfOutNeuron() {
	outNeuron_    = 0;
	double theta = 0.5;

	for (size_t i = 0; i < inputNeuronsNumber_; i++) 
		outNeuron_ += inputNeurons_[i] * synapsesWeights_[i];
	
	if (outNeuron_ > theta) 
		outNeuron_ = 1;
	else 
		outNeuron_ = 0;
}

void Perceptron::start() {
	size_t count = evolution();
	std::cout << "Number of iterations " << count << "\n";
	std::cout << "Result:\n";

	for (size_t i = 0; i < columnsNumber_; i++) {
		for (size_t k = 0; k < inputNeuronsNumber_; k++)
			inputNeurons_[k] = learnPattern_[i][k];
		valueOfOutNeuron();
		std::cout << "Out of neuron: " << outNeuron_ << " ";
	}
	std::cout << std::endl;
}
