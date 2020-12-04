#include "../inc/perceptron.hpp"
#include <random>
#include <iostream>
#include <ctime>

Perceptron::Perceptron() 
	: outNeuron(0)
	, inNeuronsLength(2)
	, columns(4)
	, rows(2) 
	{

	inNeurons = new double[inNeuronsLength];
	synapsesWeights = new double[inNeuronsLength];
	learnPattern = new double* [columns];
	trueOutValue = new double[columns];

	for (size_t item{ 0 }; item < columns; item++) 
		learnPattern[item] = new double[rows];
	

	std::cout << "Input learnPatterns:\n";

	int placeholder;
	for (size_t i{ 0 }; i < columns; i++) {
		for (size_t j{ 0 }; j < rows; j++) {
			std::cin >> placeholder;
			learnPattern[i][j] = placeholder;
		}
	}

	std::cout << "learnPatterns:\n";
	for (size_t i{ 0 }; i < columns; i++) {
		for (size_t j{ 0 }; j < rows; j++) {
			std::cout << learnPattern[i][j] << " ";
		}
		std::cout << "\n";
	}

	std::cout << "Input right values" <<  std::endl;
	std::cin.clear();

	for (size_t item{ 0 }; item < columns; item++) {
		std::cin >> placeholder;
		trueOutValue[item] = placeholder;
	}

	std::cout << "trueOutValue:\n";
	for (size_t item{ 0 }; item < columns; item++) {
		std::cout << trueOutValue[item] << " ";
	}
	std::cout << "\n";

	for (size_t item{ 0 }; item < inNeuronsLength; item++) {
		synapsesWeights[item] = getRangeRandom(0, 1) * 0.2 + 0.1;
	}

	std::cout << "Weights:\n";
	for (size_t item{ 0 }; item < inNeuronsLength; item++) {
		std::cout << synapsesWeights[item] << "\n";
	}
	std::cout << "\n";
}

Perceptron::~Perceptron() {
	delete[] inNeurons;
	inNeurons = nullptr;

	delete[] synapsesWeights;
	synapsesWeights = nullptr;

	for (size_t i{ 0 }; i < columns; i++) 
		delete[] learnPattern[i];
	
	delete[] learnPattern;
	learnPattern = nullptr;

	delete[] trueOutValue;
	trueOutValue = nullptr;
}

double Perceptron::getRangeRandom(int min, int max) {
	
	std::random_device rand;
	std::default_random_engine gen(rand());
	std::uniform_int_distribution<> dis(min, max);
	return static_cast<double>(dis(gen));
}

size_t Perceptron::evolution() {
	double gError{ 0 };
	size_t count{};

	do {
		gError = 0;
		count++;
		for (size_t p{ 0 }; p < columns; p++) {
			for (size_t i{ 0 }; i < inNeuronsLength; i++)
				inNeurons[i] = learnPattern[p][i];
			valueOfOutNeuron();

			double error = trueOutValue[p] - outNeuron;
			gError += abs(error);

			for (size_t item{ 0 }; item < inNeuronsLength; item++) {
				synapsesWeights[item] += 0.1 * error * inNeurons[item];
			}
		}
		std::cout << "Out error: " << gError << "\n";
	} while (gError != 0);

	return count;
}

void Perceptron::valueOfOutNeuron() {
	outNeuron = 0;
	
	double theta{ 0.5 };

	for (size_t item{ 0 }; item < inNeuronsLength; item++) {
		outNeuron += inNeurons[item] * synapsesWeights[item];
	}
	if (outNeuron > theta) outNeuron = 1;
	else outNeuron = 0;
}

void Perceptron::start() {
	std::cout << evolution() << "\n";
	std::cout << "Result:\n";

	for (size_t p{ 0 }; p < columns; p++) {
		for (size_t i{ 0 }; i < inNeuronsLength; i++)
			inNeurons[i] = learnPattern[p][i];
		valueOfOutNeuron();
		std::cout << "Out of neuron: " << outNeuron << ", ";
	}
	std::cout << "\n";
}