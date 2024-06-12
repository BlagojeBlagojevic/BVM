#ifndef UTILS_H
#define UTILS_H
#include<stdint.h>

typedef  uint8_t  u8;
typedef  uint16_t u16;
typedef  uint32_t u32;
typedef  uint64_t u64;
typedef  int16_t  i16;
typedef  int32_t  i32;
typedef  int64_t  i64;
typedef  float    f32;
typedef  double   f64;


typedef union {
    u64 asU64;
    i64 asI64;
    f64 asF64;
    void *asPtr;
} Word;


//BOOL
enum {FALSE, TRUE};


//ERROR HANDLING AND LOGING SYSTEM WILL DEPEND OF STANDDARD LIB
#include<stdio.h>
#include<stdlib.h>

#define ERROR(...)        fprintf(stderr, __VA_ARGS__)
#define ERROR_BREAK(...)  fprintf(stderr, __VA_ARGS__); exit(-1)
#define LOG(...)     			fprintf(stdout, __VA_ARGS__) 
#define PAUSE()           system("pause")
#define LOGSTACK()        LOG("Value %d\n", (i16)vm.stack[SP].asI64);

#include <string.h>  //MEMCPY MEMSET





#endif