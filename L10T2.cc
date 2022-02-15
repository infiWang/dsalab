#include <functional>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>

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

using edge = std::tuple<u64, u64, u64>;

let maxn = i64(2e5 + 2), maxm = i64(2e5 + 2), mod = i64(998244353);
u64 n, m, fa[maxn], scnt[maxn];
i64 q[maxn];
auto cmp = [](edge a, edge b){ return std::get<2>(a) != std::get<2>(b) ? std::get<2>(a) > std::get<2>(b) : std::get<0>(a) != std::get<0>(b) ? std::get<0>(a) > std::get<0>(b) : std::get<1>(a) > std::get<1>(b); };
std::priority_queue<edge, std::vector<edge>, decltype(cmp)> he(cmp);

fn swap(i64* u, i64* v) { i64 t = *u; *u = *v; *v = t; }
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

fn dsf(u64 cv) {
    while(cv != fa[cv]) cv = fa[cv] = fa[fa[cv]];
    return cv;
};

fn qu(u64 qi) -> u64 {
    if(q[qi] >= 0) return q[qi];
    u64 ql = qu(qi-1);
    while(!he.empty() && std::get<2>(he.top()) <= qi) {
        edge cure = he.top(); he.pop();
        u64 fu = dsf(std::get<0>(cure)), fv = dsf(std::get<1>(cure));
        fa[fv] = fu;
        ql += scnt[fu]*scnt[fv];
        scnt[fu] += scnt[fv];
    }
    return q[qi] = ql;
}

fn main() -> i32 {
    n = q_read(), m = q_read();
    for(u64 i = 0; i <= n; i++) fa[i] = i, scnt[i] = 1;
    for(u64 i = 0; i < maxn; i++) q[i] = -1; q[0] = 0;
    for(u64 i = 1; i < n; i++) {
        u64 u = q_read(), v = q_read(), w = q_read();
        he.push({min(u, v), max(u, v), w});
    }
    for(u64 i = 1; i <= m; i++) printf("%llu ", qu(q_read()));
    printf("\n");

    return 0;
}