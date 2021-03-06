#pragma once

#include "cudaTools.h"
#include "Grid.h"
#include "../nbSlice.h"



class Slice
    {


    public:

	Slice(const Grid& grid);

	virtual ~Slice(void);

	void run();

	float getResult();

    private:

	dim3 dg;
	dim3 db;
	float* ptrDevResult;
	float result;
	size_t sizeTabSM;
	size_t sizeResultGM;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
