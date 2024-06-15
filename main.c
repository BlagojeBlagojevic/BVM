#define BVM_IMPLEMENTATION
#include "bvm.h"
#define BVMASM_IMPLEMENTATION
#include "bvmasm.h"
int main(){
	
	
	Bvm bvm = initBVM();
	//executeInstruction(&bvm);
	//stackPush()
	bvm.numOfInstructions =  textToProgram("fibonaci.bvm", bvm.instruction);
	LOG("Num of instruction, %d\n", bvm.numOfInstructions);
	programToBin("program.bin", bvm.instruction, bvm.numOfInstructions);
	//binToProgram("program.bin", bvm.instruction);
	//LOG("%d\n\n", bvm.instruction[0].type);
	
	loop(&bvm);
	return 0;
}














