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

let maxn = u64(5+5e5);
i64 n, pocnt, necnt, ans;
i64 a[maxn];

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
	for(u64 i = 1; i <= n; i++) a[i] = q_read();
    for(u64 i = 1; i <= n; i++) a[i] > 0 ? pocnt++ : false;
    for(u64 i = 1; i <= n; i++) a[i] < 0 ? necnt++ : false;
    if(n <= 1) {
        ans = a[1];
    } else if(n <= 2) {
        ans = std::max(a[1] - a[2], a[2] - a[1]);
    } else {
        std::sort(1+a, 1+a+n);
        for(u64 i = 1; i <= n; i++) ans += std::abs(a[i]);
        if(n <= pocnt) ans -= std::abs(2*a[1]);
        if(n <= necnt) ans -= std::abs(2*a[n]);
    }
    printf("%lli\n", ans);

	return 0;
}