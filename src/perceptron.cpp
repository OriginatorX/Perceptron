# include <random>
# include <iostream>
# include <ctime>

# include "../inc/perceptron.hpp"

Perceptron::Perceptron() 
	: columnsNumber      (4)
	, rowsNumber         (2)  
	, outNeuron          (0)
	, inputNeuronsNumber (2)
	{

	inputNeurons    = new double  [inputNeuronsNumber];
	synapsesWeights = new double  [inputNeuronsNumber];
	learnPattern    = new double* [columnsNumber];
	trueOutValue    = new double  [columnsNumber];

	for (size_t i = 0; i < columnsNumber; i++) 
		learnPattern[i] = new double[rowsNumber];

	std::cout << "Input learnPatterns:\n";

	int32_t placeholder;
	for (size_t i = 0; i < columnsNumber; i++) {
		for (size_t j = 0; j < rowsNumber; j++) {
			std::cin >> placeholder;
			learnPattern[i][j] = placeholder;
		}
	}

	std::cout << "learnPatterns:\n";
	for (size_t i = 0; i < columnsNumber; i++) {
		for (size_t j = 0; j < rowsNumber; j++)
			std::cout << learnPattern[i][j] << " ";
		std::cout << "\n";
	}

	std::cout << "Input right values" <<  std::endl;
	std::cin.clear();

	for (size_t i = 0; i < columnsNumber; i++) {
		std::cin >> placeholder;
		trueOutValue[i] = placeholder;
	}

	std::cout << "trueOutValue:\n";
	for (size_t i = 0; i < columnsNumber; i++)
		std::cout << trueOutValue[i] << " ";	
	std::cout << "\n";

	for (size_t i = 0; i < inputNeuronsNumber; i++) 
		synapsesWeights[i] = getRangeRandom(0, 1) * 0.2 + 0.1;

	std::cout << "Weights:\n";
	for (size_t i = 0; i < inputNeuronsNumber; i++) 
		std::cout << synapsesWeights[i] << "\n";	
	std::cout << " ";
}

Perceptron::~Perceptron() {
	for (size_t i = 0; i < columnsNumber; i++) 
		delete[] learnPattern[i];
	delete[] learnPattern;

	delete[] inputNeurons;
	delete[] synapsesWeights;
	delete[] trueOutValue;
	
	inputNeurons    = nullptr;
	synapsesWeights = nullptr;
	learnPattern    = nullptr;
	trueOutValue    = nullptr; 
}

double Perceptron::getRangeRandom(int min, int max) {
	std::random_device              rand;
	std::default_random_engine      gen(rand());
	std::uniform_int_distribution<> dis(min, max);
	return static_cast<double>      (dis(gen));
}

size_t Perceptron::evolution() {
	double gError = 0;
	size_t count  = 0;

	do {
		gError = 0;
		count++;
		for (size_t i = 0; i < columnsNumber; i++) {
			for (size_t k = 0; k < inputNeuronsNumber; k++)
				inputNeurons[k] = learnPattern[i][k];
			valueOfOutNeuron();

			double error = trueOutValue[i] - outNeuron;
			gError += abs(error);

			for (size_t i = 0; i < inputNeuronsNumber; i++) 
				synapsesWeights[i] += 0.1 * error * inputNeurons[i];
		}
		std::cout << "Out error: " << gError << "\n";
	} while (gError != 0);
	return count;
}

void Perceptron::valueOfOutNeuron() {
	outNeuron    = 0;
	double theta = 0.5;

	for (size_t i = 0; i < inputNeuronsNumber; i++) 
		outNeuron += inputNeurons[i] * synapsesWeights[i];
	
	if (outNeuron > theta) outNeuron = 1;
	else outNeuron = 0;
}

void Perceptron::start() {
	std::cout << "Number of iterations " << evolution() << "\n";
	std::cout << "Result:\n";

	for (size_t i = 0; i < columnsNumber; i++) {
		for (size_t k = 0; k < inputNeuronsNumber; k++)
			inputNeurons[k] = learnPattern[i][k];
		valueOfOutNeuron();
		std::cout << "Out of neuron: " << outNeuron << " ";
	}
	std::cout << "\n";
}
