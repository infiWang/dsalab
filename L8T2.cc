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
u64 n, m, ans;
std::string op;
u64 t;
i32 b0 = 0, b1 = -1;

fn swap(i64* u, i64* v) { i64 t = *u; *u = *v; *v = t; }
fn abs(i64 n) -> i64 { return n > 0 ? n : -n; }
fn abs(f64 n) -> f64 { return n > 0 ? n : -n; }
fn min(i64 m, i64 n) -> i64 { return m - n < 0 ? m : n; }
fn max(i64 m, i64 n) -> i64 { return m - n > 0 ? m : n; }

fn main() -> i32 {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n >> m;
    
    while(n--) {
        std::cin >> op >> t;
        switch(op[0]) {
            case 'A' : {
                b0 &= t, b1 &= t;
                break;
            }
            case 'O' : {
                b0 |= t, b1 |= t;
                break;
            }
            case 'X' : {
                b0 ^= t, b1 ^= t;
                break;
            }
            default: break;
        }
    }
    for(u64 bi = 0; bi <= 29; bi++) {
        if(b0&(1<<bi)) ans += (1<<bi);
        else if((b1&(1<<bi)) && ((1<<bi)<=m)) m -= (1<<bi), ans += (1<<bi);
    }

    printf("%llu\n", ans);

	return 0;
}