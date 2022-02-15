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

let maxn = i64(1e5 + 2), mod = i64(998244353);
u64 n, ans;
i64 a[maxn], t[maxn];

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

fn merge(u64 pl, u64 pr) -> void {
    if(pr - pl <= 1) return;
    u64 mid = ((pr+pl)>>1);
    merge(pl, mid); merge(mid, pr);
    u64 pp = pl, pq = mid, pc = pl;
    while(pc < pr) {
        if((pq < pr && a[pp] > a[pq]) || pp >= mid)
             t[pc++] = a[pq++], ans += (mid-pp);
        else t[pc++] = a[pp++];
    }
    for(u64 i = pl; i < pr; i++) a[i] = t[i];
}

fn main() -> i32 {
	n = q_read();
	for(u64 i = 1; i <= n; i++) a[i] = q_read(); // a[n+1] = 1ULL>>63;

	merge(1, n+1);

    std::cout << ans << "\n";

	return 0;
}