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

let maxn = u64(5+1e5), maxm = u64(5+1e5), emaxn = u64(1e3);
bool isfib[maxn];
u64 fib[maxn], pfib[maxn];
u64 n, m;

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

fn solve() -> void {
    n = q_read(), m = q_read();
    std::vector<edge> e;
    for(u64 i = 1; i <= m; i++) {
        u64 u = q_read(), v = q_read(), w = q_read();
        e.push_back({u, v, w});
    }
    auto cmps = [](edge a, edge b){return std::get<2>(a) < std::get<2>(b);};
    std::sort(e.begin(), e.end(), cmps);
    u64 win = 0, wax = 0, cein = 0, ceax = 0;
    u64 ds[1+n]; for(u64 i = 0; i <= n; i++) ds[i] = i;
    auto dsf = [&ds](u64 cv) { while(cv != ds[cv]) cv = ds[cv] = ds[ds[cv]]; return cv; };
    for(std::vector<edge>::iterator it = e.begin(); it < e.end(); it++) {
        u64 u = std::get<0>(*it), v = std::get<1>(*it), w = std::get<2>(*it);
        u64 dsu = dsf(u), dsv = dsf(v);
        if(dsu == dsv) continue; ds[dsv] = dsu;
        win += w; cein++;
    }
    if(cein != n-1) cein = 0;
    for(u64 i = 0; i <= n; i++) ds[i] = i;
    for(std::vector<edge>::reverse_iterator it = e.rbegin(); it != e.rend(); it++) {
        u64 u = std::get<0>(*it), v = std::get<1>(*it), w = std::get<2>(*it);
        u64 dsu = dsf(u), dsv = dsf(v);
        if(dsu == dsv) continue; ds[dsu] = ds[v];
        wax += w; ceax++;
    }
    if(ceax != n-1) ceax = 0;

    printf("%s\n", ((((pfib[wax] - pfib[win])|((wax==win)?isfib[win]?win:0:0)) > 0)
                && (cein > 0 || ceax > 0)) ? "Yes" : "No");
}

fn main() -> i32 {
    fib[0] = 0, fib[1] = 1; u64 p = 2;
    do {
        fib[p] = fib[p-1] + fib[p-2];
    } while(fib[p++] < maxn); p -= 2;
    for(u64 i = 1; i <= p; i++) isfib[fib[i]] = true; isfib[0] = false;
    for(u64 i = 1; i < maxn; i++) pfib[i] = pfib[i-1] + (isfib[i] ? 1 : 0);
	u64 T = q_read();
    while(T--) solve();

	return 0;
}