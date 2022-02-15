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

using item = std::tuple<u64, u64>;

let maxn = i64(5e3 + 2), maxm = i64(5e3 + 2), mod = i64(998244353);
u64 n, m, w[maxn], c[maxn], dp[maxm];

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
il fn q_pow(i64 x, i64 y) -> i64 {
    i64 pow = 1;
    while(y != 0) {
        if(y & 1) pow = pow * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return pow;
}

fn main() -> i32 {
	n = q_read(), m = q_read();
    for(u64 i = 1; i <= n; i++) w[i] = q_read();
    for(u64 i = 1; i <= n; i++) c[i] = q_read();

    for(u64 i = 1; i <= n; i++)
        for(u64 j = m; j >= c[i]; j--)
            dp[j] = max(dp[j], w[i] + dp[j-c[i]]);

    printf("%llu\n", dp[m]);

	return 0;
}