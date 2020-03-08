#pragma once
#include "Matrix.h"
#include "Model.h"

typedef float(*func)(float x);
typedef float(*func2)(float x, float y);

class NeuralNetwork
{
public:
	NeuralNetwork() = default;
	NeuralNetwork(int* nodes, int length, float lr);
	NeuralNetwork(Model m);

	~NeuralNetwork();

	Matrix* FeedForward(Matrix* input) const;
	void FeedForward(Matrix** outputs) const;
	void Train(Matrix *inputs, Matrix* targets);

private:
	int* Nodes;
	int Length;

	Matrix** weights;
	Matrix** biases;

	std::vector<Matrix> m_Weights;

	float learning_rate;
};

