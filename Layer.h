#pragma once
#include <iostream>
#include <string>

class Layer
{
public:
	Layer(int neuronCount, const std::string & activationFunc);
	~Layer();

private:
	int m_NeuronCount;
	std::string m_ActivationFunction;
};

