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

let maxn = u64(2+2e5), maxm = u64(2+2e5), maxk = u64(2+2e5);
u64 n, m, k, t, ans;
i64 p[maxn], h[maxm], hh[maxm];

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
	n = q_read(), m = q_read(), k = q_read(), t = q_read();
    for(u64 i = 1; i <= n; i++) p[i] = q_read(); std::sort(1+p, 1+p+n);
    for(u64 i = 1; i <= m; i++) h[i] = q_read(); std::sort(1+h, 1+h+m);
    u64 pp = 1, ph = 1;
    while(pp <= n && ph <= m) {
        i64 d = p[pp] - h[ph], absd = std::abs(d);
        if(absd <= t) {
            hh[ph]++; pp++, ans++;
            if(hh[ph] >= k) ph++;
        } else {
            if(d < 0) pp++;
            if(d > 0) ph++;
        }
    }
    printf("%llu\n", ans);

	return 0;
}