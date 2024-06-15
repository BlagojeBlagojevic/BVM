#define BVM_IMPLEMENTATION
#include "bvm.h"
#ifndef BVMASM_H
#define BVMASM_H
#include<string.h>


//static inline BvmAsm



static inline void asmRemoveComents(char* line);
static inline void asmChangeConstExpresions(const char* str[]);

#define MAX_LABEL_NAME   30
#define MAX_LABEL_NUMBER 1000  
typedef struct{
	
	u64  labelLineNumber;
	char labelName[MAX_LABEL_NAME];
	
}Label;
static inline void asmChangeLable(char line[100][MAX_SIZE_OF_PROGRAM], u64 counter1);

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




static inline void asmChangeLable(char line[MAX_LINE][MAX_SIZE_OF_PROGRAM], u64 counter1){
	
	
	//SOMTING WITCH WILL BE LIKE HASH MAP BUT IS TWO COMPLEX PROB
	//LETS HAVE 1000 LABELS
	const char label_const[] = "LABEL";  
	Label labels[MAX_LABEL_NUMBER];
	u64 labelCounter = 0;
	//PAUSE();
	//memset(&labels, 0, sizeof(Label)*MAX_LABEL_NUMBER);	
	for(u64 counter = 0; counter < counter1 - 1; counter++){
		PAUSE();
			if(strstr(line[counter], label_const) != NULL){
				labels[labelCounter].labelLineNumber = counter;
				u8 internalCounter = 0;
				while(1){
					if(labels[labelCounter].labelName[internalCounter] == ' '){
						memcpy(labels[labelCounter].labelName, &labels[labelCounter].labelName[internalCounter], 
									MAX_LABEL_NAME - internalCounter);
						LOG("LABEL %s", labels[labelCounter].labelName);
						PAUSE();
						labelCounter++;
						break;
					}
					if(internalCounter == MAX_LABEL_NAME){
						break;
					}
					internalCounter++;
				}
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
		//asmRemoveComents(line[counter - 1]);
		
	}	
	//PAUSE();
	fclose(f);
	//CHANGES
	//asmRemoveComents(str);
	//asmChangeConstExpresions(str); 
	asmChangeLable(line, counter);
	for(u64 coment = 0; coment < counter; coment++){
		asmRemoveComents(line[coment]);
		LOG("%s\n",line[coment]);
	}
	
	//SAVE RAW TEXT ASEBLY;
	FILE *f1 = fopen(nameSave, "wb");
	
	fclose(f1);
	
	
}



#endif


#endif


