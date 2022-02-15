#include<functional>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<random>
#include<unistd.h>

#define fn auto
#define let const auto
#define mut mutable
#define il inline
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef float_t f32;
typedef double_t f64;

fn main() -> i32 {
    std::random_device rd;
    usleep(0xdead);
    std::uniform_int_distribution<u64> distu64(0, u64(-1)), dist64(0,63);
    i64 t = (distu64(rd));
    usleep(0xbeef);
    std::cout << (bool(t&(1<<dist64(rd))));
    return 0;
}