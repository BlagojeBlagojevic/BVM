#ifndef BVM_H
#define BVM_H
#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define LOG(...)         fprintf(stdout, __VA_ARGS__)
#define ERROR_BREAK(...) fprintf(stderr, __VA_ARGS__); exit(-1)
#define PAUSE()        	 system("pause")

#define DEBUG 1
#define TRUE  1
#define FALSE 0
 
// 


typedef  uint8_t  u8;
typedef  uint16_t u16;
typedef  uint32_t u32;
typedef  uint64_t u64;
typedef  int16_t  i16;
typedef  int32_t  i32;
typedef  int64_t  i64;
typedef  float    f32;
typedef  double   f64;

typedef union{
	
	u64 _asU64;
	i64 _asI64;
	f64 _asF64;
	void *_asP;
	
}Word;

typedef enum{
	PUSH,
	POP,
	PRINT,
	ADD,
	MUL,
	DEC,
	DIV,
	DUP,
	JMP,
	JMPT,
	SETSP,
	COPY,
	END,
	
}InstructionType;

const char* instructionNames[] ={
	
	"PUSH",
	"POP",
	"PRINT",
	"ADD",
	"MUL",
	"DEC",
	"DIV",
	"DUP",
	"JMP",
	"JMPT",
	"SETSP",
	"COPY",
	"END",
	
};

//SIZE OF THE INSTRUCTION IS 8BYTE + 1BYTE
typedef struct{
	InstructionType type;
	Word operand;
	
}Instruction;


#define STACK_CAPACITIY     1024
#define MAX_SIZE_OF_PROGRAM 1024
typedef struct{
	Word stack[STACK_CAPACITIY];
	i64  SP;
}Stack;

static inline void stackPush(Stack *stack,i64 value);
static inline Word stackPop(Stack *stack);

typedef struct{
	
	u8 isRuning;
	Stack stack;
	Instruction instruction[MAX_SIZE_OF_PROGRAM];
	u64 IP;
	
	
	
}Bvm;

static inline Bvm  initBVM(void); 
static inline void executeInstruction(Bvm *bvm);
static inline void loop(Bvm *bvm);


static inline void textToProgram(const char* name, Instruction *instrucion);
static inline void dissasembler(Bvm *bvm);


#define BVM_IMPLEMENTATION


//STACK OPERATIONS
//LETS DEFULT BE u64
static inline void stackPush(Stack *stack,i64 value){
	if(stack->SP > STACK_CAPACITIY){
		ERROR_BREAK("STACK OVERFLOW!!!\n");
	}
	stack->stack[stack->SP++]._asI64 =  value; 	
	//LOG("STACK PUSH %d\n", stack->stack[stack->SP - 1]._asI64);
}
static inline Word stackPop(Stack *stack){
	if(stack->SP < 0){
		ERROR_BREAK("STACK UNDERFLOW!!!\n");
		
	}
	stack->SP--;
	//LOG("STACK POP %d\n", stack->stack[stack->SP]._asI64);
	return stack->stack[stack->SP];
}



static inline Bvm initBVM(void){
	Bvm bvm;
	
	//PROBOBLY DYNAMIC ALLOCATION OF STACK AND INSTRUCTION WHEN FAIL
	//ALL mem FUNCTIONS 
	
	memset(&bvm, 0, sizeof(bvm));
	bvm.isRuning = TRUE; 
	LOG("Init BVM\n");
	LOG("\n SP = %lu\n", bvm.stack.SP);
	LOG("\n IP = %lu\n", bvm.IP);
	
	
	return bvm;
	
	
}

static inline void executeInstruction(Bvm *bvm){
	
	
	
	switch(bvm->instruction[bvm->IP].type){
		case PUSH:{
			stackPush(&bvm->stack, bvm->instruction[bvm->IP].operand._asI64);
			bvm->IP++;
			break;
		}	
		case POP:{
			stackPop(&bvm->stack);
			bvm->IP++;
			break;
		}
		case ADD:{
			Word a = stackPop(&bvm->stack);
			Word b = stackPop(&bvm->stack);
			stackPush(&bvm->stack, (a._asI64 + b._asI64)); 
			bvm->IP++;
			break;
			
		}	
		case PRINT:{
			
			LOG("PRINT %d\n\n", bvm->stack.stack[bvm->stack.SP - 1]._asI64);
			bvm->IP++; 
			break;
		}
		
	
	case MUL:{
		
		Word a = stackPop(&bvm->stack);
		Word b = stackPop(&bvm->stack);
		stackPush(&bvm->stack, (a._asI64 * b._asI64)); 
		bvm->IP++;
		
		
		break;
	}

	case DEC:{
		Word a = stackPop(&bvm->stack);
		Word b = stackPop(&bvm->stack);
		stackPush(&bvm->stack, (a._asI64 - b._asI64)); 
		bvm->IP++;
		break;
	}
	case DIV:{
		Word a = stackPop(&bvm->stack);
		Word b = stackPop(&bvm->stack);
		if(b._asI64 == 0){
			ERROR_BREAK("ERROR DIVISION BY 0 !!!\n");
		}
		stackPush(&bvm->stack, (a._asI64 / b._asI64));
		bvm->IP++; 
		break;
	}
	case DUP:{
		Word a = stackPop(&bvm->stack);
		stackPush(&bvm->stack, a._asI64);
		stackPush(&bvm->stack, a._asI64);
		bvm->IP++;
		break;
	}
	case JMP:{
		Word a = bvm->instruction[bvm->IP].operand;
		bvm->IP = a._asU64;
		break;
	}
	case JMPT:{
		Word a = stackPop(&bvm->stack);
		if(a._asU64 > 0){
			bvm->IP = a._asU64;
		}
		break;
	}
	case SETSP:{
		Word a = bvm->instruction[bvm->IP].operand;
		if(a._asU64 > STACK_CAPACITIY){
			ERROR_BREAK("STACK OVERFLOW ACCES!!!\n");
		}
		bvm->stack.SP = a._asI64; 
		bvm->IP++;
		break;
	}
	case COPY:{
		Word a = stackPop(&bvm->stack);
		Word b = bvm->instruction[bvm->IP].operand;
		stackPush(&bvm->stack, a._asI64);
		if(b._asU64 > STACK_CAPACITIY){
			ERROR_BREAK("STACK OVERFLOW ACCES!!!\n");
		}
		bvm->stack.stack[b._asU64] = a;
		bvm->IP++;
		break;
	}
		
		default:{
			LOG("Instruction is not implemeted\n");
			bvm->IP++;
			break;
		}
		
	}
	
	
	//return bvm;
}

static inline loop(Bvm *bvm){
	
	while(bvm->isRuning){
		executeInstruction(bvm);
		PAUSE();
	}
	
	
}


//PARSER WORD BY WORD

static inline void textToProgram(const char* name, Instruction *instrucion){
	
	LOG("%s\n\n", name);
	FILE *f = fopen(name, "rb");
	u64 counterInstruction = 0;	
	//if(f == NULL)
	//	ERROR_BREAK("FILE NOT EXISTING!!!\n");
	while(!feof(f)){
		char instructionText[60];
		char token[60], textOperand[10];
		memset(textOperand, 0, sizeof(char)*10);
		u8 counter = 0, counterOperand = 0;
		
		fgets(instructionText, 60, f);
		//sprintf()
		//GET WORD BY WORD
	
		while(instructionText[counter] != ' ' && counter < 59  ){
			token[counter] = instructionText[counter];
			counter++;
		}
		token[counter] = '\0';
		LOG("Instruction %s\n", token);
		counter++;
		while(instructionText[counter] != ' '  && counter < 59 
			 && instructionText[counter] != '\0' &&  counterOperand < 10){
			textOperand[counterOperand] = instructionText[counter];
			counter++;
			counterOperand++;
		}
		//LOG("Operand %s \n", textOperand);
	
		//INSTRUCTION HANDLING BETHER PARSER
		for(InstructionType inst = PUSH; inst <= END; inst++){
			if(!strcmp(instructionNames[inst], token)){
				instrucion[counterInstruction].type = inst;
				instrucion[counterInstruction].operand._asI64 = (i64)atoi(textOperand);
				LOG("operand %d\n", instrucion[counterInstruction].operand._asI64);
				counterInstruction++;
				//LOG("counterInstruction %u", counterInstruction);
				break;
			}
			
		}
		
	}	
	
	fclose(f);
}

static inline void dissasembler(Bvm *bvm){
	
}



#endif