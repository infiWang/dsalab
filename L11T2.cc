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

let maxn = i64(1e2 + 2), mod = i64(998244353);
u64 n, dp[maxn][maxn], sum[maxn];

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
	n = q_read();
    for(u64 i = 1; i <= n; i++) for(u64 j = 1; j <= n; j++) dp[i][j] = 0xffffffffffffffffULL;
    for(u64 i = 1; i <= n; i++) sum[i] = sum[i-1] + q_read(), dp[i][i] = 0;
    for(u64 wi = 1; wi < n; wi++)
        for(u64 i = 1; i+wi <= n; i++)
            for(u64 j = i; j+1 <= i+wi; j++)
                dp[i][i+wi] = std::min(dp[i][i+wi], dp[i][j]+dp[j+1][i+wi]+(sum[i+wi]-sum[i-1]));

    printf("%llu\n", dp[1][n]);

	return 0;
}