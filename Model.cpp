#include "Model.h"

Model::Model()
{
}

Model::~Model()
{
}

void Model::Add(int neuronCount, const std::string & activationFunc)
{
	m_Layers.push_back(Layer(neuronCount, activationFunc));
}

void Model::Add(Layer layer)
{
	m_Layers.push_back(layer);
}
