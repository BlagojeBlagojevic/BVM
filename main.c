#define BVM_IMPLEMENTATION
#include "bvm.h"


int main(){
	
	Bvm bvm = initBVM();
	bvm.numOfInstructions =  textToProgram("test.bvm", bvm.instruction);
	LOG("Num of instruction, %d\n", bvm.numOfInstructions);
	loop(&bvm);
	return 0;
}














