#include<functional>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<map>
#include<algorithm>

#define fn auto
#define let const auto
typedef char i8;
typedef signed short i16;
typedef signed i32;
typedef signed long long i64;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
typedef unsigned long long u64;

fn main() -> i32 {
    i64 A, B; std::cin >> A >> B;
    u64 D = B - A;
    bool fl = false; u8 lb = 64;
    while(--lb) {
        if(D == (1 << lb)) fl = true;
    }
    if(D <= 1) std::cout << 1 << std::endl;
    else std::cout << (fl ? u64((log2f64x(D))) : u64(log2f64x(D) + 1)) << std::endl;
    return 0;
}