#pragma once
#define SIGMOID (func)([](float x) {return 1.0f / (1.0f + exp(-x));})
#define D_SIGMOID (func)([](float y) {return y*(1.0f-y);})
#define LEAKY_RELU (func)([](float x){return std::max(x*0.1f,x);})
#define D_LEAKY_RELU (func)([](float x){return x < 0? -0.1f:1.0f;})
#define RELU (func)([](float x){return std::max(0.0f,x);})
#define D_RELU (func)([](float x){return x <= 0? 0.0f:1.0f;})
#define SOFT_MAX (func2)([](float x, float sum){return x/sum;})