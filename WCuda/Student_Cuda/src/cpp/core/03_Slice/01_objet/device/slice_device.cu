
#include "Indice1D.h"
#include "cudaTools.h"
#include "../nbSlice.h"
#include <stdio.h>
#include "reductionADD.h"

static __device__ void reductionInterThread(float* ptrDevResult, int nbSlice);
static __device__ float fpi(float x);

__global__ void slice(float* ptrDevResult, int nbSlice)
    {
    extern __shared__ float tab_SM[];
    reductionInterThread(tab_SM, nbSlice);
    __syncthreads();
    reductionADD<float>(tab_SM, ptrDevResult);
    }

__device__
void reductionInterThread(float* tab_SM, int nbSlice)
    {
    const int TID_LOCAL = Indice1D::tidLocal();
    const int TID_GLOBAL = Indice1D::tid();
    const int NB_THREAD = Indice1D::nbThread();

    int s = TID_GLOBAL;
    float DX = 1 / (float)nbSlice;
    float sum = 0;

    while (s < nbSlice)
    {
	float xs = s * DX;
	sum += fpi(xs);
	s += NB_THREAD;
    }
    tab_SM[TID_LOCAL] = sum *DX;
    }

__device__
float fpi(float x)
    {
    return 4 / (1 + x * x);
    }
