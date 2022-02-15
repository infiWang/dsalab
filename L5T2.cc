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

using edge = std::tuple<u64, u64>;
using he = std::tuple<edge, i64>;

let maxn = i64(2+2e5);
u64 n, hp, ans;
u64 a[maxn];
bool v[maxn];

// struct cmp {bool operator() (edge a, edge b){return std::get<1>(a) > std::get<1>(b);};};
// auto cmp = [](edge a, edge b){return std::get<1>(a) > std::get<1>(b);};
// std::priority_queue<edge, std::vector<edge>, cmp> oe[maxn];   
std::vector<edge> oe[maxn];

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

fn dfs(edge cst) -> void {
    i64 cstv = std::get<0>(cst), cstc = std::get<1>(cst);
    if(v[cstv]) return; v[cstv] = true, hp += a[cstv];
    auto cmp = [](he a, he b){return std::get<1>(a) < std::get<1>(b);};
    std::priority_queue<he, std::vector<he>, decltype(cmp)> loea(cmp);
    std::priority_queue<he, std::vector<he>, decltype(cmp)> loeb(cmp);
    std::priority_queue<he, std::vector<he>, decltype(cmp)> loec(cmp);
    for(std::vector<edge>::iterator it = oe[cstv].begin(); it < oe[cstv].end(); it++)
    if(i64(a[std::get<0>(*it)]) - 2*i64(std::get<1>(*it)) >= 0) loea.push({*it, i64(a[std::get<0>(*it)]) - 2*i64(std::get<1>(*it))});
    else if(i64(a[std::get<0>(*it)]) - i64(std::get<1>(*it)) >= 0) loeb.push({*it, i64(a[std::get<0>(*it)]) - i64(std::get<1>(*it))});
    else loec.push({*it, -i64(a[std::get<0>(*it)])});
    while(!loea.empty()) {
        he nsthe = loea.top(); loea.pop();
        edge nst = std::get<0>(nsthe);
        u64 nstv = std::get<0>(nst), nstc = std::get<1>(nst);
        if(!v[nstv]) {
            if(hp >= nstc) hp -= nstc;
            else ans += (nstc-hp), hp = 0;
            dfs(nst);
        }
    }
    while(!loeb.empty()) {
        he nsthe = loeb.top(); loeb.pop();
        edge nst = std::get<0>(nsthe);
        u64 nstv = std::get<0>(nst), nstc = std::get<1>(nst);
        if(!v[nstv]) {
            if(hp >= nstc) hp -= nstc;
            else ans += (nstc-hp), hp = 0;
            dfs(nst);
        }
    }
    while(!loec.empty()) {
        he nsthe = loec.top(); loec.pop();
        edge nst = std::get<0>(nsthe);
        u64 nstv = std::get<0>(nst), nstc = std::get<1>(nst);
        if(!v[nstv]) {
            if(hp >= nstc) hp -= nstc;
            else ans += (nstc-hp), hp = 0;
            dfs(nst);
        }
    }
    if(hp >= cstc) hp -= cstc;
    else ans += (cstc-hp), hp = 0;
}

fn main() -> i32 {
	n = q_read();
	for(i64 i = 1; i <= n; i++) a[i] = q_read();
    for(i64 i = 1; i < n; i++) {
        i64 u = q_read(), v = q_read(), w = q_read();
        oe[u].push_back({v, w}), oe[v].push_back({u, w});
    }

    dfs({1, 0});

    printf("%llu\n", ans);

	return 0;
}