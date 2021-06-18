# pragma once

class Perceptron {
public:
	Perceptron();
	~Perceptron();
public:
	double getRangeRandom(int min, int max);
	void   valueOfOutNeuron();	
	size_t evolution();
	void   start();
private:	
	size_t columnsNumber;
	size_t rowsNumber;

	double*  inputNeurons;
	double   outNeuron;	
	double*  synapsesWeights;	
	double** learnPattern;	
	double*  trueOutValue;
	
	size_t inputNeuronsNumber;
public:
	Perceptron(const Perceptron&) = delete;
	Perceptron& operator=(const Perceptron&) = delete;
};
