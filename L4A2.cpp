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
const u64 maxn = 2 + 1e5;

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
    i64 v, pre, nxt;
} f[maxn];

fn main() -> i32 {
    u64 n = q_read();
    for(u64 i = 1; i <= n; i++) { f[i].v = i; }
    u64 head = 1; f[head].pre = f[head].nxt = 0;
    for(u64 i = 2; i <= n; i++) {
        u64 k = q_read(), p = q_read();
        if(k == head) { if(p < 1) { head = i, f[i].pre = f[k].pre, f[i].nxt = k, f[f[k].pre].nxt = i, f[0].nxt = 0, f[k].pre = i; }
                             else { f[i].nxt = f[k].nxt, f[i].pre = k, f[f[k].nxt].pre = i, f[0].pre = 0, f[k].nxt = i; } }
        else { if(p < 1) { f[i].pre = f[k].pre, f[i].nxt = k, f[f[k].pre].nxt = i, f[0].nxt = 0, f[k].pre = i; }
                    else { f[i].nxt = f[k].nxt, f[i].pre = k, f[f[k].nxt].pre = i, f[0].pre = 0, f[k].nxt = i; } }
    }
    u64 m = q_read();
    for(u64 i = 1; i <= m; i++) {
        u64 x = q_read();
        if(f[x].pre <= 0 && f[x].nxt <= 0) continue;
        if(x == head) head = f[x].nxt;
        f[f[x].pre].nxt = f[x].nxt, f[0].nxt = 0, f[f[x].nxt].pre = f[x].pre, f[0].pre = 0, f[x].pre = f[x].nxt = 0;
    }
    u64 p = head;
    while(p != 0) {
        printf("%lld ", f[p].v);
        p = f[p].nxt;
    }

    return 0;
}