#include <iostream>
#include "Device.h"
#include "cudaTools.h"

#include "MontecarloMultiGPU.h"


using std::cout;
using std::endl;

MontecarloMultiGPU::MontecarloMultiGPU(const Grid& grid, int nbDartsTotal, float m)
    {

    this->grid = grid;
    this->nbThread = Device::nbThread(grid);
    this->nbDartsTotal = nbDartsTotal;
    this->m = m;
    this->nbDarts = nbDartsTotal / nbThread;
    this->nbDevice = Device::getDeviceCount();
    this->result = 0.0f;

    }

MontecarloMultiGPU::~MontecarloMultiGPU(void)
    {

    }


void MontecarloMultiGPU::run()
    {
    long somme = 0;
    #pragma omp parallel for reduction(+:somme)
    for (int i = 0; i < nbDevice; i++)
   	{
	Device::setDevice(i);
	MonteCarlo mc(grid, nbDartsTotal/nbDevice, m);
	mc.run();
	somme = mc.getMontecarloResult();
   	}

    result = (double)somme * m / (double) nbDartsTotal;

    }

float MontecarloMultiGPU::getResult(){
    return result;
}