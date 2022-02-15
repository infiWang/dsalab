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

fn so(u64 bi, u64 di, bool st) -> u64 {
    u64 mi = 1ULL<<bi;
    return (di <= 0) ? 0
         : (bi <= 0) ? (st?1:0)
         : (di+1 == (mi<<1)) ? mi-(st?0:1)
         : (di < mi) ? so(bi-1, di, true)
         : (di <= mi) ? so(bi-1, di, true)+(st?1:0)
         : (mi>>1)+(st?1:0)+so(bi-1, di-mi, false);
}

fn nol(u64 di) -> u64 {
    if(di <= 1) return di;
    u64 bih = 63; while(((1ULL<<bih) > di)) bih--;
    return so(bih, di, true);
}

fn solve() -> void {
    u64 i = q_read(), j = q_read();
    printf("%llu\n", nol(j) - nol(i-1));
}

fn main() -> i32 {
	u64 n = q_read();
	while(n--) solve();

	return 0;
}