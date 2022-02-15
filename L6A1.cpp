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
const u64 maxn = 1e6 + 2;

u64 nxt[maxn];

fn main() -> i32 {
    std::string s1, s2;
    std::cin >> s1 >> s2;
    u64 l1 = s1.length(), l2 = s2.length();
    for(u64 i = 1; i < l2; i++) {
        u64 t = nxt[i-1];
        while(t > 0 && s2[i] != s2[t]) t = nxt[t-1];
        nxt[i] = (s1[i] == s2[t] ? t+1 : t);
    }
    u64 p = 0;
    for(u64 i = 0; i < l1; i++) {
        while(p > 0 && s1[i] != s2[p]) p = nxt[p - 1];
        if(s1[i] == s2[p]) p++;
        if(p == l2) printf("%lu ", i - l2 + 2);
    } printf("\n");
    for(u64 i = 0; i < l2; i++) printf("%lu ", nxt[i]);

    return 0;
}