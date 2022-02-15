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

using edge = std::tuple<u64, u64, i64, i64>;
let maxn = i64(15 + 2), maxm = i64(1e3 + 2), mod = i64(998244353);
bool v[maxn];
i64 de[maxn], gap[maxn], pa[maxn];
std::vector<edge> el; std::vector<u64> g[maxn];
std::vector<u64>::iterator ecache[maxn];

fn solve() -> void {
    memset(de, 0xff, sizeof(de)), memset(v, false, sizeof(v)), memset(gap, 0, sizeof(gap)); el.clear();
    u64 n = q_read(), m = q_read(), s = 1, t = n, ecnt = 0;
    for(u64 i = 1; i <= n; i++) g[i].clear();
    for(u64 i = 1; i <= m; i++) {
        u64 x = q_read(), y = q_read(), c = q_read();
        el.push_back({x, y, c, 0}), g[x].push_back(ecnt++);
        el.push_back({y, x, 0, 0}), g[y].push_back(ecnt++);
    }
    for(u64 i = 1; i <= n; i++) de[i] = n, ecache[i] = g[i].begin();

    std::queue<u64> sq; sq.push(t); v[t] = true, de[t] = 0;
    while(!sq.empty()) {
        u64 cur = sq.front(); sq.pop();
        for(std::vector<u64>::iterator it = g[cur].begin(); it < g[cur].end(); it++) {
            edge e = el[(*it)];
            u64 nxt = std::get<1>(e); i64 cap = std::get<2>(e), flow = std::get<3>(e);
            if(v[nxt] || (cap|flow)) continue;
            v[nxt] = true, de[nxt] = de[cur] + 1; sq.push(nxt); 
        }
    }
    for (u64 i = 1; i <= n; i++) gap[de[i]]++;

    u64 curdfs = s, ans = 0;
    while(de[s] < n) {
        if(curdfs == t) {
           u64 curaug = t; i64 rc = 0x3fffffffffffffffULL;
           while(curaug != s) {
               edge e = el[pa[curaug]];
               u64 pre = std::get<0>(e); i64 cap = std::get<2>(e), flow = std::get<3>(e);
               rc = std::min(rc, cap - flow);
               curaug = pre;
           }
           curaug = t;
           while(curaug != s) {
               edge &ef = el[pa[curaug]], &er = el[pa[curaug]^1];
               std::get<3>(ef) += rc, std::get<3>(er) -= rc;
               curaug = std::get<0>(ef);
           }
           ans += rc, curdfs = s;
        }
        bool pd = false;
        for(std::vector<u64>::iterator it = ecache[curdfs]; it < g[curdfs].end(); it++) {
            edge e = el[(*it)];
            u64 nxt = std::get<1>(e); i64 cap = std::get<2>(e), flow = std::get<3>(e);
            if(de[nxt] + 1 == de[curdfs] && cap > flow) {
                pd = true;
                pa[nxt] = (*it), ecache[curdfs] = it, curdfs = nxt;
                break;
            }
        }
        if(!pd) {
            i64 md = n-1;
            for(std::vector<u64>::iterator it = g[curdfs].begin(); it < g[curdfs].end(); it++) {
                edge e = el[(*it)];
                u64 nxt = std::get<1>(e); i64 cap = std::get<2>(e), flow = std::get<3>(e);
                if(cap > flow) md = std::min(md, de[nxt]);
            }
            if(!(--gap[de[curdfs]])) break; gap[de[curdfs] = md+1]++;
            ecache[curdfs] = g[curdfs].begin();
            if(curdfs != s) curdfs = std::get<0>(el[pa[curdfs]]);
        }
    }

    printf("%llu\n", ans);
}

fn main() -> i32 {
	u64 t = q_read();
    for(u64 i = 1; i <= t; i++)
        printf("Case %llu: ", i), solve();

	return 0;
}