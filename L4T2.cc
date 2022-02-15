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

let maxn = i64(2+2e6), maxw = i64(2+2e6);
i64 n, ans;
i64 w[maxn], ws[maxn], d[maxn];
bool v[maxn];
std::vector<i64> oe[maxn];
using state = std::tuple<i64, i64>;

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

fn dfs(state cst) -> void {
    i64 cstv = std::get<0>(cst), cstd = std::get<1>(cst);
    if(v[cstv]) return; v[cstv] = true, d[cstv] = cstd;
    for(std::vector<i64>::iterator it = oe[cstv].begin(); it < oe[cstv].end(); it++)
        if(!v[*it]) dfs({*it, cstd+1}), ws[cstv] += ws[*it];
}

fn main() -> i32 {
	n = q_read();
    for(i64 i = 1; i <= n; i++) w[i] = q_read();
    memcpy(ws, w, sizeof(w));
    for(i64 i = 1; i <= n-1; i++) {
        i64 p = q_read(), q = q_read();
        oe[p].push_back(q), oe[q].push_back(p);
    }
    
    dfs({1, 0}); for(i64 i = 1; i <= n; i++) ans += d[i] * w[i];
    memset(v, false, sizeof(v));
    std::queue<state> sq; sq.push({1, ans});
    while(!sq.empty()) {
        state cst = sq.front(); sq.pop();
        i64 cstv = std::get<0>(cst), cstb = std::get<1>(cst);
        if(v[cstv]) continue; v[cstv] = true, ans = std::max(ans, cstb);
        for(std::vector<i64>::iterator it = oe[cstv].begin(); it < oe[cstv].end(); it++)
            sq.push({*it, cstb + (ws[1]-ws[*it]) - ws[*it]});
    }

    printf("%llu\n", ans);
	return 0;
}