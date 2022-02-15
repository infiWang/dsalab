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
const i64 maxn = 3e5 + 2;

fn swap(i64* u, i64* v) { *u ^= *v; *v ^= *u; *u ^= *v; }
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

i64 a[maxn], s[maxn], e[maxn], l[maxn];

fn i_sort(i64 pl, i64 pr) -> void {
    for (int i = pl+1; i <= pr; i++)
        for (int j = i; j > 0 && s[j] < s[j-1]; j--)
            std::swap(s[j], s[j-1]), std::swap(e[j], e[j-1]);
}

fn q_sort(i64 pl, i64 pr) -> void {
    if(pl >= pr) return;
    // if(pr - pl < 9) { i_sort(pl, pr); return; }
    i64 pu = pl, pv = pr, pi = ((pl+pr)>>1), w = s[pi];
    while(pu <= pv) {
        while(s[pu] < w) pu++; while(s[pv] > w) pv--;
        if(pu <= pv) std::swap(s[pu], s[pv]), std::swap(e[pu++], e[pv--]);
    }
    q_sort(pl,pv); q_sort(pu,pr);
}

fn main() -> i32 {
    // i64 n = q_read(), m = q_read();
    i64 n, m; std::cin >> n >> m;
    for(u64 i = 1; i <= n; i++) { std::cin >> a[i]; }

    for(u64 i = n; i >= 1; i--) { s[i] = s[i+1] + a[i]; e[i] = i; }
    q_sort(2, n);
    for(u64 i = 1; i < m; i++) { l[e[n-i+1]] = 1; } l[1] = 1;
    for(u64 i = 1; i <= n; i++) { l[i] = l[i-1] + l[i]; }
    i64 ans = 0;
    for(u64 i = 1; i <= n; i++) { ans += (a[i]*l[i]); }

    std::cout << ans << std::endl;

    return 0;
}