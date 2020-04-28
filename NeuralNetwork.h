#pragma once
#ifndef NEURAL_NETWORK_LAYER_COUNT
#define NEURAL_NETWORK_LAYER_COUNT 2
#endif // !NEURAL_NETWORK_LAYER_COUNT

#include "ActivationFunctions.h"
#define ACTIVATION_FUNC SIGMOID
#define D_ACTIVATION_FUNC D_SIGMOID

#include "TemplateParams.h"
#include "TrainFunc.h"
#include "WeightMats.h"

#include <array>
#include "Matrix.h"
#include "Model.h"

typedef float(*func)(float x);
typedef float(*func2)(float x, float y);

namespace canpp
{
	TEMPLATE
	class nn
	{
	public:
		nn(float lr)
			:learningRate(lr)
		{
		}
		TRAIN
	public:
		float learningRate;
		WEIGHTS_MATS
	};
}

class NeuralNetwork
{
public:
	NeuralNetwork() = default;
	NeuralNetwork(int* nodes, int length, float lr);
	NeuralNetwork(Model m);

	~NeuralNetwork();

	Matrix* FeedForward(Matrix* input) const;
	void FeedForward(Matrix** outputs) const;
	void Train(Matrix* inputs, Matrix* targets);

private:
	int* Nodes;
	int Length;

	Matrix** weights;
	Matrix** biases;

	std::vector<Matrix> m_Weights;

	float learning_rate;
};

