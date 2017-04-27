#pragma once


#include "Grid.h"
#include <curand.h>
#include <curand_kernel.h>
#include "../../04_Montecarlo/01_objet/host/MonteCarlo.h"


class MontecarloMultiGPU
    {


    public:

	MontecarloMultiGPU(const Grid& grid, int nbDartsTotal, float m);

	virtual ~MontecarloMultiGPU(void);

	void run();

	float getResult();

    private:

	Grid grid;
	uint nbThread;
	uint nbDartsTotal;
	float m;
	uint nbDarts;
	uint nbDevice;
	float result;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/