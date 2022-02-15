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
let maxn = i64(2e2 + 2), maxv = i64(4e4 + 5), maxm = i64(4e4 + 2), mod = i64(998244353);

bool v[maxv];
i64 de[maxv], gap[maxv], pa[maxv];
u64 ecnt;
std::vector<edge> el; std::vector<u64> g[maxv];
std::vector<u64>::iterator ecache[maxv];

bool obs[maxn][maxn];

fn flow(u64 nn) -> void {
    memset(de, 0xff, sizeof(de)), memset(v, false, sizeof(v)), memset(gap, 0, sizeof(gap)); el.clear();
    u64 n = nn*nn+2, s = nn*nn+1, t = nn*nn+2;
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

    printf("%llu\n", [&](){u64 pcnt = 0; for(u64 i = 1; i <= nn; i++) for(u64 j = 1; j <= nn; j++) if(!obs[i][j]) pcnt++; return pcnt;}()-ans);
}

i64 stx[8] = {+1, +2, +2, +1, -1, -2, -2, -1},
    sty[8] = {+2, +1, -1, -2, -2, -1, +1, +2};

fn main() -> i32 {
	u64 n = q_read(), m = q_read();
    for(u64 i = 1; i <= m; i++) obs[q_read()][q_read()] = true;
    for(i64 i = 1; i <= n; i++) for(i64 j = 1; j <= n; j++) {
        if(obs[i][j]) continue;
        if((i+j)%2) {
            el.push_back({n*n+1, n*(i-1)+j, 1, 0}), g[n*n+1].push_back(ecnt++),
            el.push_back({n*(i-1)+j, n*n+1, 0, 0}), g[n*(i-1)+j].push_back(ecnt++);
            for(u64 t = 0; t < 8; t++) {
                i64 nx = i + stx[t], ny = j + sty[t];
                if(nx < 1 || ny < 1 || nx > n || ny > n || obs[nx][ny]) continue;
                el.push_back({n*(i-1)+j, n*(nx-1)+ny, 1, 0}), g[n*(i-1)+j].push_back(ecnt++),
                el.push_back({n*(nx-1)+ny, n*(i-1)+j, 0, 0}), g[n*(nx-1)+ny].push_back(ecnt++);
            }
        } else {
            el.push_back({n*(i-1)+j, n*n+2, 1, 0}), g[n*(i-1)+j].push_back(ecnt++),
            el.push_back({n*n+2, n*(i-1)+j, 0, 0}), g[n*n+2].push_back(ecnt++);
        }
    }
    flow(n);

	return 0;
}