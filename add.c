#include "./add.h"

struct __HEAP_VARIABLES_STRUCT__ *__HEAP_VARIABLES__ = NULL;

void __FREE_INPUT__(){
	if(__HEAP_VARIABLES__){
		if(__HEAP_VARIABLES__ -> __INPUT_A_PTR__){
			free(__HEAP_VARIABLES__ -> __INPUT_A_PTR__);
			__HEAP_VARIABLES__ -> __INPUT_A_PTR__ = NULL;
		}
		if(__HEAP_VARIABLES__ -> __INPUT_B_PTR__){
			free(__HEAP_VARIABLES__ -> __INPUT_B_PTR__);
			__HEAP_VARIABLES__ -> __INPUT_B_PTR__ = NULL;
		}
	}
}

void __FREE_OUTPUT__(){
	if(__HEAP_VARIABLES__){
		if(__HEAP_VARIABLES__ -> __OUTPUT_R_PTR__){
			free(__HEAP_VARIABLES__ -> __OUTPUT_R_PTR__);
			__HEAP_VARIABLES__ -> __OUTPUT_R_PTR__ = NULL;
		}
	}
}

void __FREE_ALL__(){
	if(__HEAP_VARIABLES__){
		__FREE_INPUT__();
		__FREE_OUTPUT__();
	}
}

void __INIT_HEAP_VARIABLES__(){
	__HEAP_VARIABLES__ = (struct __HEAP_VARIABLES_STRUCT__*)calloc(1,sizeof(struct __HEAP_VARIABLES_STRUCT__));
}

char *__READ_STRING__(){
	if (Serial.available() > 0){
		String __STRING_INPUT__ = "";
		size_t __STRING_INPUT_LENGTH__ = 0;
		__STRING_INPUT__ = Serial.readString();
		__STRING_INPUT_LENGTH__ = (__STRING_INPUT__.length());
		char *__STRING_INPUT_CHARP__ = NULL;
		__STRING_INPUT_CHARP__ = (char*)calloc(__STRING_INPUT_LENGTH__ + 1,sizeof(char));
		for(size_t i = 0;i < __STRING_INPUT_LENGTH__;i++){
			(*(__STRING_INPUT_CHARP__ + i)) = __STRING_INPUT__.charAt(i);
		}
		return __STRING_INPUT_CHARP__;
 }
}

void setup(){
	__INIT_HEAP_VARIABLES__();
	Serial.begin(9600);
}

void loop(){
	if(__HEAP_VARIABLES__ && !(__HEAP_VARIABLES__ -> __INPUT_A_PTR__)) \
		(__HEAP_VARIABLES__ -> __INPUT_A_PTR__) = __READ_STRING__();\
	else if(__HEAP_VARIABLES__ && !(__HEAP_VARIABLES__ -> __INPUT_B_PTR__)) \
		(__HEAP_VARIABLES__ -> __INPUT_B_PTR__) = __READ_STRING__();\
	else if((__HEAP_VARIABLES__ -> __INPUT_A_PTR__) && (__HEAP_VARIABLES__ -> __INPUT_B_PTR__)) \
		( \
			(__FREE_OUTPUT__()), \
			((__HEAP_VARIABLES__ -> __OUTPUT_R_PTR__) = ( \
				(__ADD_INTEGER__( \
					(__HEAP_VARIABLES__ -> __INPUT_A_PTR__), \
					(__HEAP_VARIABLES__ -> __INPUT_B_PTR__) \
				)) \
			)), \
			(Serial.println(__HEAP_VARIABLES__ -> __OUTPUT_R_PTR__)), \
			(__FREE_INPUT__()), \
			(__FREE_OUTPUT__()) \
		);
}
