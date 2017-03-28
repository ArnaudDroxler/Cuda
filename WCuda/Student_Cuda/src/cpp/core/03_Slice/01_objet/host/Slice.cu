#include <iostream>

#include "Device.h"
#include "Slice.h"

using std::cout;
using std::endl;


extern __global__ void slice(float *ptrDevResult,int nbSlice);


Slice::Slice(const Grid& grid)
    {

    this->dg = grid.dg;
    this->db = grid.db;

    this->sizeResultGM = sizeof(float);
    this->sizeTabSM = db.x * sizeof(float);

    result = 0;

    Device::malloc(&ptrDevResult, sizeResultGM);
    cudaMemset(ptrDevResult, 0,sizeResultGM);



    }

Slice::~Slice(void)
    {
    Device::free(ptrDevResult);
    }


void Slice::run()
    {
    Device::lastCudaError("slice (before)"); // temp debug
    slice<<<dg,db, sizeTabSM >>>(ptrDevResult,NB_SLICE); // assynchrone
    Device::lastCudaError("slice (after)"); // temp debug

    //Device::synchronize(); // Temp,debug, only for printf in GPU

    Device::memcpyDToH(&result, ptrDevResult, sizeResultGM); // barriere synchronisation implicite

    }

float Slice::getResult(){
    return result;
}