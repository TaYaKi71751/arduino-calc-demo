#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>

#ifndef perror
#define perror(str) (Serial.println(str))
#endif

#ifndef __ADD_H__
#define __ADD_H__

#include "./string-number/include/integer_def_calc.h"

typedef struct __HEAP_VARIABLES_STRUCT__ {
  char *__INPUT_A_PTR__;
  char *__INPUT_B_PTR__;
  char *__OUTPUT_R_PTR__;
} __HEAP_VARIABLES_STRUCT__;

void __FREE_INPUT__();
void __FREE_OUTPUT__();
void __FREE_ALL__();

void __INIT_HEAP_VARIABLES__();

void setup();
void loop();

#endif
