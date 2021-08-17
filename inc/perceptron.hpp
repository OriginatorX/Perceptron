#pragma once

#include "Random.hpp"

class Perceptron {
public:
	Perceptron(const Random& rand);
	~Perceptron();
public:
	void   valueOfOutNeuron();	
	size_t evolution();
	void   start();
private:
	Random 		random_;

	size_t 	 	columnsNumber_;
	size_t 		rowsNumber_;

	double*  	inputNeurons_;
	double   	outNeuron_;	
	double*  	synapsesWeights_;	
	double** 	learnPattern_;	
	double*  	trueOutValue_;
	
	size_t 		inputNeuronsNumber_;
public:
	Perceptron(const Perceptron&) = delete;
	Perceptron& operator=(const Perceptron&) = delete;
};
