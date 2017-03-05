#pragma once

#include "cudaType_CPU.h"
#include "Variateur_CPU.h"
#include "Animable_I_CPU.h"

#include "math/MandelbrotMathH.h"
using namespace cpu;

using namespace cpu;


class Fractale: public Animable_I<uchar4>
    {

      public:

	    Fractale(uint w, uint h, uint dt,  const DomaineMath& domaineMath);

	    virtual ~Fractale(void);

	    virtual FractaleMath* getFractaleMath() = 0;

	    virtual void processEntrelacementOMP(uchar4* ptrTabPixels, uint w, uint h, const DomaineMath& domaineMath);

	    virtual void processForAutoOMP(uchar4* ptrTabPixels, uint w, uint h, const DomaineMath& domaineMath);

	    virtual void animationStep();

	    void workPixel(uchar4* ptrColorIJ, int i, int j, const DomaineMath& domaineMath);

	    Variateur<int> variateurAnimation;
	    FractaleMath* ptrFractalMath;

    };

