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
const u64 maxn = 2 + 3e5;

fn swap(i64* u, i64* v) { i64 t = *u; *u = *v; *v = t; }
fn abs(i64 n) -> i64 { return n > 0 ? n : -n; }
fn abs(f64 n) -> f64 { return n > 0 ? n : -n; }
fn min(i64 m, i64 n) -> i64 { return m - n < 0 ? m : n; }
fn max(i64 m, i64 n) -> i64 { return m - n > 0 ? m : n; }
inline fn q_read() -> i64 {
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

struct node {
    u64 x;
} f[maxn];

fn solve() -> void {
    i64 n = q_read(), m = q_read();
    for(u64 i = 1; i <= n; i++) f[i].x = (i+1); f[n].x = 1;
    i64 p = n;
    while(n--) {
        for(u64 i = 1; i < m; i++) { p = f[p].x; }
        printf("%llu ", f[p].x);
        f[p].x = f[f[p].x].x;
    }
    printf("\n");
}

fn main() -> i32 {
    i64 t = q_read();
    while(t--) solve();

    return 0;
}