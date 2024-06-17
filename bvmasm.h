#define BVM_IMPLEMENTATION
//#include "bvm.h"
#ifndef BVMASM_H
#define BVMASM_H
#include<string.h>


//static inline BvmAsm



static inline void asmRemoveComents(char* line);
static inline void asmChangeConstExpresions(const char* str[]);

#define MAX_LABEL_NAME   30
#define MAX_LABEL_NUMBER 1000  
#define MAX_LINE_NUM_BUFFER 10

#ifndef MAX_SIZE_OF_PROGRAM
	#define MAX_SIZE_OF_PROGRAM 10024
#endif

#ifndef MAX_LINE
	#define MAX_LINE 100
#endif

typedef struct{
	
	u64  labelLineNumber;
	char labelName[MAX_LABEL_NAME];
	
}Label;
static inline void asmChangeLable(char line[100][MAX_SIZE_OF_PROGRAM], u64 numOfLine);

static inline void bvmAsmToText(const char* name, const char* nameSave);

#define BVMASM_IMPLEMENTATION
#ifdef BVMASM_IMPLEMENTATION

static inline void asmRemoveComents(char* line){
	u8 doesSet = FALSE;
	for(u8 counter = 0; counter < MAX_LINE; counter++){
		if(line[counter] == '#'){
			memset(&line[counter], '\0', (MAX_LINE - counter));
			break;	
		}
		
	}
}




static inline void asmChangeLable(char line[MAX_LINE][MAX_SIZE_OF_PROGRAM], u64 numOfLine){
		
		const char label_const[] = "LABEL";
		const char jmp_const[] = "JMP";
		Label label[MAX_LABEL_NUMBER]; 
		u64 labelCounter = 0;
		memset(&label, 0, sizeof(Label) * MAX_LABEL_NAME);
		//GET ALL LABELS STORE IN LABEL STRUCT
		for(u64 counter = 0; counter < numOfLine; counter++){
			//IF LABEL EXIST AND JMP DOES NOT
			if(strstr(line[counter], label_const)!= NULL && strstr(line[counter], jmp_const) == NULL){
				LOG("Label Exist %s\n", line[counter]);
				memcpy(label[labelCounter].labelName, line[counter], MAX_LINE * sizeof(char));
				LOG("Copy Label %s\n", label[labelCounter].labelName);
				label[labelCounter].labelLineNumber = counter - 1;
				LOG("label value %lld\n", counter);
				labelCounter++;
			}	
		}	
	//CHANGE ALL LABELS WITH A LABEL COUNTER
	//u64 changeJmpPosition = 
	for(u64 counter = 0; counter < numOfLine; counter++){
		//RET POINTER TO FIRST OF THE 
		if(strstr(line[counter], jmp_const) != NULL){
			LOG("Jmp exist %s\n", &line[counter][4]);
			//memset(line[counter], '\0', MAX_LABEL_NAME);
			//memcpy(line[counter], jmp_const, sizeof(char) * 3);
			for(u64 counterIternal = 0; counterIternal < labelCounter; counterIternal++){
				if(strcmp(&line[counter][3], label[counterIternal].labelName) != NULL){
					char buffer[10];
					snprintf(buffer, 10, "%lld", label[counterIternal].labelLineNumber);
					LOG("Buffer %s\n", buffer);
					memset(&line[counter][4], '\0', sizeof(line[counter][4]));
					memcpy(&line[counter][4], buffer, sizeof(char) * 10);
					LOG("LINE CHANGED %s\n", line[counter]);
				}
			}
			system("pause");
			
		}
		
		
	}
}


static inline void bvmAsmToText(const char* name, const char* nameSave){
	char line[MAX_LINE][MAX_SIZE_OF_PROGRAM];
	FILE *f = fopen(name, "r");
	//READ ENTIRE FILE
	u64 counter = 0;
	while(!feof(f)){
		fgets(line[counter++], MAX_LINE,f);
		asmRemoveComents(line[counter - 1]);
		
	}	
	//PAUSE();
	fclose(f);
	//CHANGES
	//asmRemoveComents(str);
	//asmChangeConstExpresions(str); 
	asmChangeLable(line, counter);
	for(u64 coment = 0; coment < counter; coment++){
		
		LOG("%s\n",line[coment]);
	}
	
	//SAVE RAW TEXT ASEBLY;
	FILE *f1 = fopen(nameSave, "w");
	for(u64 counter1 = 0; counter1 < counter; counter1++){
		LOG("line %s", line[counter1]);
		if(line[counter1][0]!='\n' && line[counter1][0]!='\0')
			fprintf(f1, "%s\n", line[counter1]);
		system("pause");
	}
	fclose(f1);
	
	
}



#endif


#endif


