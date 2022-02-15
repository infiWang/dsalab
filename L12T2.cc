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

let maxn = i64(5e1 + 2), mod = i64(998244353);

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

u64 n, k, s[maxn];
bool dp[2][maxn][maxn];

fn main() -> i32 {
	n = q_read(), k = q_read();
    for(u64 i = 1; i <= n; i++) s[i] = s[i-1] + q_read();

	u64 ans = 0;
	for(u64 bi = 0; bi < 56; bi++) {
		for(u64 i = 0; i < maxn; i++) for(u64 j = 0; j < maxn; j++) dp[bi%2][i][j] = false; dp[bi%2][0][0] = true;
		for(u64 u = 1; u <= n; u++)
			for(u64 v = 1; v <= std::min(u, k); v++)
				for(u64 w = v; w <= u; w++) {
					u64 p = s[u] - s[w-1];
					if((p&(1ULL<<(55-bi))) && (p&ans)==ans && dp[bi%2][w-1][v-1])
						dp[bi%2][u][v] = true;
				}
		ans |= dp[bi%2][n][k] ? 1ULL<<(55-bi) : 0;
	}

    printf("%llu\n", ans);

	return 0;
}