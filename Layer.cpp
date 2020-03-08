#include "Layer.h"


Layer::Layer(int neuronCount, const std::string & activationFunc)
	: m_NeuronCount(neuronCount)
	, m_ActivationFunction(activationFunc)
{

}

Layer::~Layer()
{
}
