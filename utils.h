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
    u64 as_u64;
    i64 as_i64;
    f64 as_f64;
    void *as_ptr;
} Word;


//BOOL
enum {FALSE, TRUE};


//ERROR HANDLING AND LOGING SYSTEM WILL DEPEND OF STANDDARD LIB
#include<stdio.h>

#define ERROR(...)        fprintf(stderr, __VA_ARGS__)
#define ERROR_BREAK(...)  fprintf(stderr, __VA_ARGS__); exit(-1)
#define LOG(...)     			fprintf(stdout, __VA_ARGS__) 
#define PAUSE()           system("pause")


#include <string.h>  //MEMCPY MEMSET




#endif