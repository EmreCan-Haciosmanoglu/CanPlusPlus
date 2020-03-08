#pragma once
#include <string>
#include <vector>
#include "Layer.h"

class Model
{
public:
	Model();
	~Model();

	void Add(int neuronCount, const std::string& activationFunc);
	void Add(Layer layer);

	inline std::vector<Layer>::iterator GetLayers() { return m_Layers.begin(); }
	inline int GetLayerCount() { return m_Layers.size(); }
private:
	std::vector<Layer> m_Layers;
};