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

let maxn = i64(1e5 + 2), maxm = i64(5e5 + 2);

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
	while(ch >= '0' && ch <= '9') {
		ans = ans * 10 + ch - '0';
		ch = getchar();
	}
	return sign ? -ans : ans ;
}

std::vector<i64> fg[maxn], rg[maxn]; 
i64 val[maxn], nmax[maxn], vmin[maxn]; bool vi[maxn];

fn dfsf(i64 cur) -> void {
	vi[cur] = true;
	for(i64 i = 0; i < fg[cur].size(); i++){
		i64 nxt = fg[cur][i];
		if(vi[nxt]) continue;
		vmin[nxt] = min(vmin[cur], val[nxt]);
		dfsf(nxt);
	}
}

fn dfsr(i64 cur) -> void {
	vi[cur] = true;
	for(i64 i = 0; i < rg[cur].size(); i++){
		i64 nxt = rg[cur][i];
		if(vi[nxt]) continue;
		nmax[nxt] = max(nmax[cur], val[nxt]);
		dfsr(nxt);
	}
}

fn main() -> i32 {
	i64 n = q_read(), m = q_read();
	for(i64 i = 1; i <= n; i++) val[i] = q_read();
	for(i64 i = 1; i <= m; i++){
		i64 x = q_read(), y = q_read(), z = q_read();
		fg[x].push_back(y), rg[y].push_back(x);
		if(z > 1) fg[y].push_back(x), rg[x].push_back(y);    
	}
	
	memset(vmin, 0x7f, sizeof(vmin)), vmin[1] = val[1];
	dfsf(1);

	memset(vi, false, sizeof(vi));
	dfsr(n);

	i64 ans = 0;
	for(i64 i = 1; i <= n; i++) ans = max(ans, nmax[i] - vmin[i]);
	printf("%ld", ans);

	return 0;
}