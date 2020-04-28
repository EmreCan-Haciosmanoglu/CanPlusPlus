#pragma once
#if NEURAL_NETWORK_LAYER_COUNT > 4
#define WEIGHTS_MATS \
mat<L2, L1> w1;\
mat<L3, L2> w2;\
mat<L4, L3> w3;\
mat<L5, L4> w4;
#elif NEURAL_NETWORK_LAYER_COUNT > 3
#define WEIGHTS_MATS \
mat<L2, L1> w1;\
mat<L3, L2> w2;\
mat<L4, L3> w3;
#elif NEURAL_NETWORK_LAYER_COUNT > 2
#define WEIGHTS_MATS \
mat<L2, L1> w1;\
mat<L3, L2> w2;
#else
#define WEIGHTS_MATS \
mat<L2, L1> w1;
#endif
