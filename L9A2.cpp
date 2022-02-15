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

let maxn = i64(5000 + 2), maxm = i64(2e5 + 2);

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

struct Edge {
    i64 u, v, w;

    Edge(i64 _u = 0, i64 _v = 0, i64 _w = 0) {
        u = _u, v = _v, w = _w;
    }

    bool operator < (const Edge tEdge) const {
        return w < tEdge.w;
    }
}
emptyEdge;

i64 ds[maxn]; Edge el[maxm];

il fn dsf(i64 t) -> i64 {
    while(t != ds[t]) t = ds[t] = ds[ds[t]];
    return t;
}

fn main() -> i32 {
	i64 n, m; std::cin >> n >> m;
    for(i64 i = 1; i <= n; i++) ds[i] = i;
    for(i64 i = 1; i <= m; i++) {
        el[i].u = q_read(), el[i].v = q_read(), el[i].w = q_read();
    }

	std::sort(1+el, 1+el+m);

    i64 ans = 0, cnt = 0;
    for(i64 i = 1; i <= m; i++) {
        i64 dsu = dsf(el[i].u), dsv = dsf(el[i].v);
        if(!(dsu^dsv)) continue;

        ans += el[i].w;
        ds[dsv] = dsu;
        if(++cnt >= n-1) break;
    }

    printf("%li\n", ans);
	return 0;
}