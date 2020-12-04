#pragma once

class Perceptron {
public:
	Perceptron();
	~Perceptron();

	double getRangeRandom(int min, int max);
	void valueOfOutNeuron();	
	size_t evolution();
	void start();
private:	
	size_t columns;
	size_t rows;

	double* inNeurons;
	double outNeuron;	
	double* synapsesWeights;	
	double** learnPattern;	
	double* trueOutValue;
	
	size_t inNeuronsLength;
public:
	Perceptron(const Perceptron&) = delete;
	Perceptron& operator=(const Perceptron&) = delete;
};