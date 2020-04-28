#pragma once
#if NEURAL_NETWORK_LAYER_COUNT > 4
#define TRAIN void Train(mat<L1,1> data, mat<L5,1> label)
#elif NEURAL_NETWORK_LAYER_COUNT > 3
#define TRAIN void Train(mat<L1,1> data, mat<L4,1> label)
#elif NEURAL_NETWORK_LAYER_COUNT > 2
#define TRAIN void Train(mat<L1,1> data, mat<L3,1> label)
#else
#define TRAIN void Train(mat<L1,1> data, mat<L2,1> label)\
{\
	mat<L2,1> out1 = (mat.MatMult(w1, data) + b1).Activate(ACTIVATION_FUNC);\
\
	mat<L2,1> err1 = label - out1;\
\
	mat<L2,1> grad1 = ((mat.Map(out1, D_ACTIVATION_FUNC))*err1)*learninRate;\
	w1+= mat.MatMult(grad1,mat.Transpos(data));\
	b1+=grad1\
}
#endif
