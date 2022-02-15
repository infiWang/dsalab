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

let maxn = i64(2e5 + 2);

#define swap std::swap
fn abs(i64 n) -> i64 { return n > 0 ? n : -n; }
fn abs(f64 n) -> f64 { return n > 0 ? n : -n; }
fn min(i64 m, i64 n) -> i64 { return m - n < 0 ? m : n; }
fn max(i64 m, i64 n) -> i64 { return m - n > 0 ? m : n; }
il fn q_read() -> i64 {
    bool sign = false; i64 ans = 0;
    char ch = getchar();
    while((ch < '0' || ch > '9') && ch != '-' ) ch = getchar();
    if(ch == '-') { sign = true; ch = getchar(); }
    while(ch >= '0' && ch <= '9'){
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return sign ? -ans : ans ;
}

i64 nx[maxn], mrk[maxn], val[maxn];

fn main() -> i32{
    i64 n = q_read(), s = n;
    for(i64 i = 1 ; i <= n ; i++) nx[i] = q_read();

    for(i64 i = 1 ; i <= n ; i++) {
        val[i] = 1;
        i64 p = i, pp = nx[p];
        while(mrk[pp] != i) {
            if(0 < mrk[pp]) break;
            val[pp] = val[p]+1, mrk[p] = i;
            p = pp , pp = nx[p];
        }
        if(mrk[pp] == i && s > val[p]+1 - val[pp]) s = val[p]+1 - val[pp];
    }

    printf("%li" , s);

    return 0;
}