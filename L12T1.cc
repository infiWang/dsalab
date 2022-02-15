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

u64 n, a[maxn], b[maxn], dp[maxn];

fn main() -> i32 {
	n = q_read();
    for(u64 i = 1; i <= n; i++) dp[i] = 0x7fffffffffffffffULL;
    for(u64 i = 1; i <= n; i++) a[i] = q_read();
    for(u64 i = 1; i < n; i++) b[i] = q_read();

    dp[1] = a[1];
    for(u64 i = 2; i <= n; i++)
        dp[i] = std::min(dp[i],
                std::min(dp[i-1] + a[i], dp[i-2] + b[i-1]));

    printf("%llu\n", dp[n]);

	return 0;
}