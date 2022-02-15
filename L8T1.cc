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

using state = std::tuple<u64, bool>;

let maxn = i64(1e1 + 2), mod = i64(998244353);
u64 n;

fn swap(i64* u, i64* v) { i64 t = *u; *u = *v; *v = t; }
fn abs(i64 n) -> i64 { return n > 0 ? n : -n; }
fn abs(f64 n) -> f64 { return n > 0 ? n : -n; }
fn min(i64 m, i64 n) -> i64 { return m - n < 0 ? m : n; }
fn max(i64 m, i64 n) -> i64 { return m - n > 0 ? m : n; }

fn main() -> i32 {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n;
    while(n--) {
        std::string s; std::cin >> s;
        u64 l = s.length(), cnt[1<<8] = {0}, schs = 0, ans = 0;
        for(u64 i = 0; i < l; i++) cnt[s[i]]++;
        auto cmp = [](state a, state b){ return std::get<0>(a) > std::get<0>(b); };
        std::priority_queue<state, std::vector<state>, decltype(cmp)> q(cmp);
        for(u64 i = 'a'; i <= 'z'; i++) if(cnt[i]) q.push({cnt[i], false});
        while(q.size() > 1) {
            state x = q.top(); q.pop();
            state y = q.top(); q.pop();
            u64 a = std::get<0>(x), b = std::get<0>(y);
            bool m = std::get<1>(x), n = std::get<1>(y);
            ans += (m ? a : 0) + (n ? b : 0);
            q.push({a+b, true});
        }
        printf("%llu\n", ans + std::get<0>(q.top()));
    }

	return 0;
}