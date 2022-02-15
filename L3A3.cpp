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
const u64 maxn = 2 + 2e5;

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

u64 v[maxn], x[maxn], y[maxn], d[maxn];

fn i_sort(i64 pl, i64 pr) -> void {
    for (int i = pl+1; i <= pr; i++)
        for (int j = i; j > 0 && d[j] < d[j-1]; j--)
            std::swap(d[j], d[j-1]), std::swap(x[j], x[j-1]), std::swap(y[j], y[j-1]);
}

fn q_sort(i64 pl, i64 pr) -> void {
    if(pl >= pr) return;
    if(pr - pl < 4) { i_sort(pl, pr); return; }
    i64 pu = pl, pv = pr, pi = ((pl+pr)>>1), w = d[pi];
    while(pu <= pv) {
        while(d[pu] < w) pu++;
        while(d[pv] > w) pv--;
        if(pu <= pv) std::swap(x[pu], x[pv]), std::swap(y[pu], y[pv]), std::swap(d[pu++], d[pv--]);
    }
    q_sort(pl,pv); q_sort(pu,pr);
}

fn main() -> i32 {
    i64 n = q_read(), a = q_read(), b = q_read();
    for(u64 i = 1; i <= n ; i++) { x[i] = q_read(), y[i] = q_read(); d[i] = x[i] - y[i]; }
    q_sort(1, n);
    u64 ans = 0;
    for(u64 i = 1; i <= n ; i++) { ans+=y[i]; }
    for(u64 i = 1; i <= n; i++) { x[i]<<=a; }
    for(u64 i = 1; i <= n; i++) {
        if(i <= b && d[i] > 0) {
            ans += d[i];
        }
    }

    return 0;
}