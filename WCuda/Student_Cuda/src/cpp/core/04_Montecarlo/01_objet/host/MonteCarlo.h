#pragma once


#include "Grid.h"
#include <curand.h>
#include <curand_kernel.h>


class MonteCarlo
    {


    public:

	MonteCarlo(const Grid& grid, int nbDartsTotal, float m);

	virtual ~MonteCarlo(void);

	void run();

	float getResult();
	uint getMontecarloResult();

    private:

	dim3 dg;
	dim3 db;
	uint nbThread;
	uint nbDartsTotal;
	float m;
	uint nbDarts;

	float result;
	uint montecarloResult;
	uint* ptrDevResult;
	size_t sizeInt;

	curandState* ptrDevGeneratorGM;
	size_t sizeOctetGeneratorGM;

	size_t sizeTabSM;




    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
