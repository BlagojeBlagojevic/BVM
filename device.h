//TBD interface for device system generates code
#ifndef DEVICE_H
#define DEVICE_H
//#define BVM_IMPLEMENTATION
//#define SDL_DEVICE
#include "bvm_type.h"

typedef enum {
    NUM_OF_DEVICES
}DeviceType;

static const char* device_name[] = {
    
    "NUM_OF_DEVICES",
};

typedef struct device{
    void (*func_pointer)(int);
    int stackSize; 
}Devices;

//ALL STUF ARE PASED AS GLOBAL VARS FOR EXAMPLE WINDOW, RENDERER itd...

//NEKA SA SAD BUDE GLOBALNO 
static Devices devices[NUM_OF_DEVICES];
static inline void initDevices(Stack *stack){
    printf("Devices init non\n");
    
}

#endif


