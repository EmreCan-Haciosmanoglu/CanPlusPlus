#pragma once

#if NEURAL_NETWORK_LAYER_COUNT > 4
#define TEMPLATE template< int L1, int L2, int L3, int L4, int L5>
#elif NEURAL_NETWORK_LAYER_COUNT > 3
#define TEMPLATE template< int L1, int L2, int L3, int L4>
#elif NEURAL_NETWORK_LAYER_COUNT > 2
#define TEMPLATE template< int L1, int L2, int L3>
#else
#define TEMPLATE template< int L1, int L2>
#endif