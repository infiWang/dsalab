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

using state = std::tuple<u64, u64, u64>;

let maxn = u64(5+5e3);
u64 n, ans;
state task[maxn];
u64 d[maxn], v[maxn];

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

fn matchmake(u64 cp, u64 cpm) -> bool {
	if(d[cpm] > std::get<1>(task[cp])) return false;
	if(v[cpm] < 1) return v[cpm] = cp, true;
	if(std::get<1>(task[cp]) < std::get<1>(task[v[cpm]])) {
		if(matchmake(v[cpm], cpm+1)) return v[cpm] = cp, true;
	} else {
		return matchmake(cp, cpm+1);
	}
	return false;
}

fn main() -> i32 {
	n = q_read();
	for(u64 i = 1; i <= n; i++) task[i] = {q_read(), q_read(), q_read()};

    auto cmples = [](state a, state b){ return std::get<0>(a) < std::get<0>(b); };
    std::sort(1+task, 1+task+n, cmples);
    for(u64 i = 1; i <= n; i++) d[i] = std::max(d[i-1]+1, std::get<0>(task[i]));
    auto cmpbev = [](state a, state b){ return std::get<2>(a) > std::get<2>(b); };
    std::sort(1+task, 1+task+n, cmpbev);
	for(u64 i = 1; i <= n; i++) {
		u64 pm = 1;
		while(d[pm] < std::get<0>(task[i])) pm++;
		if(matchmake(i, pm)) ans += std::get<2>(task[i]);
	}

	printf("%llu\n", ans);

	return 0;
}