#define BVM_IMPLEMENTATION
#include "bvm.h"

int main(){
	Bvm bvm = initBVM();
	//executeInstruction(&bvm);
	//stackPush()
	textToProgram("program.bvm", bvm.instruction);
	//LOG("%d\n\n", bvm.instruction[0].type);
	loop(&bvm);
	return 0;
}








