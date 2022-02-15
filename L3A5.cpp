
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
const i64 mod = 998244353;
const u64 maxn = 1e5 + 2;

fn swap(i64* u, i64* v) { i64 t = *u; *u = *v; *v = t; }
fn swap(u8* u, u8* v) { u8 t = *u; *u = *v; *v = t; }
fn swap(bool* u, bool* v) { bool t = *u; *u = *v; *v = t; }
fn abs(i64 n) -> i64 { return n > 0 ? n : -n; }
fn abs(f64 n) -> f64 { return n > 0 ? n : -n; }
fn min(i64 m, i64 n) -> i64 { return m - n < 0 ? m : n; }
fn max(i64 m, i64 n) -> i64 { return m - n > 0 ? m : n; }
fn sq(i64 n) -> i64 { return n*n; }
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

i64 pos_x[maxn], pos_y[maxn], d[maxn], dd[maxn];

fn i_sort(i64 pl, i64 pr) -> void {
    for (int i = pl+1; i <= pr; i++)
        for (int j = i; j > 0 && d[j] < d[j-1]; j--)
            swap(d+(j), d+(j-1)), swap(pos_x+(j), pos_x+(j-1)), swap(pos_y+(j), pos_y+(j-1));
}

fn q_sort(i64 pl, i64 pr) -> void {
    if(pl >= pr) return;
    if(pr - pl < 9) { i_sort(pl, pr); return; }
    i64 pu = pl, pv = pr, pi = ((pl+pr)>>1), w = d[pi];
    while(pu <= pv) {
        while(d[pu] < w) pu++; while(d[pv] > w) pv--;
        if(pu <= pv) swap(d+(pu), d+(pv)), swap(pos_x+(pu), pos_x+(pv)), swap(pos_y+(pu++), pos_y+(pv--));
    }
    q_sort(pl,pv); q_sort(pu,pr);
}

fn main() -> i32 {
    i64 x1 = q_read(), y1 = q_read(), x2 = q_read(), y2 = q_read();
    i64 n = q_read(); for(u64 i = 1; i <= n; i++) { pos_x[i] = q_read(), pos_y[i] = q_read(); }
    for(u64 i = 1; i <= n; i++) { d[i] = sq(abs(pos_x[i] - x1)) + sq(abs(pos_y[i] - y1)); }
    q_sort(1, n);
    for(u64 i = 1; i <= n; i++) { dd[i] = sq(abs(pos_x[i] - x2)) + sq(abs(pos_y[i] - y2)); }
    u64 ans = d[n];
    u64 maxdd = dd[n];
    for(u64 i = n; i > 1; i--) {
        maxdd = max(maxdd, dd[i]);
        ans = min(ans, d[i-1]+maxdd);
    }
    std::cout << ans;

    return 0;
}