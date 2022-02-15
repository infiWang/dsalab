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

using state = std::tuple<u64, u64>;

let maxn = u64(5+1e4), maxm = u64(5+1e5);
u64 n, m;
u64 a[maxn], b[maxn], dis[maxn];
std::vector<state> oe[maxn];
bool fi[maxn];

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

fn main() -> i32 {
	n = q_read(), m = q_read();
	for(u64 i = 1; i <= m; i++) {
        u64 u = q_read(), v = q_read(), w = q_read();
        oe[u].push_back({v, w});
    }
    for(u64 i = 1; i <= n; i++) a[i] = q_read(), b[i] = q_read();

    memset(fi,false,sizeof(fi));
    for(int i = 1;i <= n;i++) dis[i] = ((1LL<<62)-1)|1LL<<62; dis[0] = dis[1] = 0;
    auto cmp = [](state a, state b){return std::get<1>(a) > std::get<1>(b);};
    std::priority_queue<state, std::vector<state>, decltype(cmp)> sq(cmp);
    sq.push({1, 0});
    while(!sq.empty()) {
        state cst = sq.top(); sq.pop();
        u64 cv = std::get<0>(cst), cw = std::get<1>(cst);
        if(fi[cv]) continue; fi[cv] = true;
        for(std::vector<state>::iterator it = oe[cv].begin(); it < oe[cv].end(); it++) {
            u64 nv = std::get<0>(*it), nw = dis[cv] + std::get<1>(*it);
            if(!fi[nv] && dis[nv] > nw) {
                u64 nwmod = nw%(a[nv]+b[nv]);
                dis[nv] = nw + (a[nv] > 0 ? nwmod < a[nv] ? a[nv] - nwmod
                                                          : 0
                                          : 0);
                sq.push({nv, dis[nv]});
            }
        }
    }

    printf("%llu\n", dis[n]);

	return 0;
}