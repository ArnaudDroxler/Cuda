#include "Indice1D.h"
#include "reductionADD.h"
#include <curand_kernel.h>



__global__ void montecarlo(curandState* tabDevGeneratorGM, uint nbDarts,uint m, uint* ptrDevNxTotal);


__device__ float f(float x);


__global__ void montecarlo(curandState* tabDevGeneratorGM, uint nbDarts, uint m, uint* ptrDevNxTotal)
    {
    extern __shared__ uint TAB_SM[];

    const int NB_THREAD=Indice1D::nbThread();
    const int TID=Indice1D::tid();
    const int TIDLocal = Indice1D::tidLocal();

    curandState generator = tabDevGeneratorGM[TID];

    int localNx = 0;
    float x;
    float y;

    for(int i = 0; i < nbDarts; i++)
	{
	x = curand_uniform(&generator);
	y = curand_uniform(&generator) * m;

	if ( y  < f(x) )
	    {
	    localNx ++;
	    }
	}

    TAB_SM[TIDLocal] = localNx;

    __syncthreads();

    reductionADD<uint>(TAB_SM, ptrDevNxTotal);
    }




__device__ float f(float x)
    {
    return 4/(1+x*x);
    }
