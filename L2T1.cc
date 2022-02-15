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

let maxn = i64(2e5 + 2), maxa = i64(2e5 + 2), mod = i64(998244353);
u64 T, n, c, h1, h2, e1[4], e2[4], e3[4], a[maxn], s[maxn], sum;

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

fn solve() -> void {
    memset(e1, 0, 4*sizeof(u64)), memset(e2, 0, 4*sizeof(u64)), memset(e3, 0, 4*sizeof(u64));
    h1  = h2 = 0, sum = 0, c = 0;
    n = q_read(), memset(a, 0, maxa*sizeof(u64)), memset(s, 0, maxn*sizeof(u64));
    for(u64 i = 1; i <= n; i++) a[q_read()]++;
    for(u64 i = 1; i <= maxa; i++) if(a[i]) s[++c] = i;

    for(u64 i = c; i >= 1; i--) {
        if(h1 >= 3 && h2 >= 3) break;

        if(h2 <= 0) {
            if(h2 <= 1 && !(e2[1]%s[i])) e2[++h2] = s[i];
            else if(h2 <= 2 && (e2[1]%s[i]) && (e2[2]%s[i])) e2[++h2] = s[i];
        }

        if(h1 <= 0) e1[++h1] = s[i];
        else if (h1 <= 1) {
            if((!(e1[1]%s[i])) && ((e1[1]/s[i]) == 2)) {
                e2[1] = e1[1], e1[1] = s[i];
                h2 = 1;
            } else if(e1[1]%s[i]) e1[++h1] = s[i];
        } else if((h1 <= 2) && (e1[1]%s[i]) && (e1[2]%s[i])) e1[++h1] = s[i];
    }

    u64 h = 0;
    for(u64 i = 1; i <= c; i++) {
        u8 f = 0, ff[4] = {0};
        for(u64 j = 1; j <= h; j++)
            if((s[i]%e3[j]) < 1) ff[++f] = j;
        if(h < 3) {
            if(f <= 0) e3[++h] = s[i];
            else if(f <= 1) e3[ff[1]] = s[i], std::sort(1+e3, 1+h+e3); 
            else if(e3[1] + e3[2] <= s[i]) e3[1] = s[i], h = 1;
        } else {
            if(f <= 0) e3[1] = s[i], std::sort(1+e3, 1+h+e3);
            else if(f <= 1) e3[ff[1]] = s[i], std::sort(1+e3, 1+h+e3); 
            else {
                sum = 0;
                for(u64 k = 1 ; k <= f; k++) sum += e3[ff[k]];
                if(sum <= s[i]) {
                    if(f >= 3) e3[1] = s[i], h = 1;
                    else if (f >= 2) {
                        for(u64 k = 1 ; k <= f; k++) e3[ff[k]] = 0;
                        std::sort(1+e3, 1+3+e3);
                        e3[1] = s[i], h = 2;
                        std::sort(1+e3, 1+3+e3);
                        e3[1] = e3[2]; e3[2] = e3[3];
                    }
                }
            }
        }
    }

    u64 s3 = 0;
    for(u64 i = 1; i <= h; i++) s3 += e3[i];
    printf("%llu\n", max(max(e1[1]+e1[2]+e1[3], e2[1]+e2[2]+e2[3]), s3));
}

fn main() -> i32 {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	T = q_read();
    while(T--) solve();

	return 0;
}