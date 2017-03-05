#pragma once

#include "Animable_I_CPU.h"
#include "Provider_I_CPU.h"

using namespace cpu;


class JuliaHProvider: public Provider_I<uchar4>
    {
    public:

	virtual ~JuliaHProvider()
	    {
	    // Rien
	    }

	Animable_I<uchar4>* createAnimable(void);

	Image_I* createImageGL(void);

    };


