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

let maxs = u64(100 + 2);
u64 T, s, n, m, g, v[maxs][maxs][maxs], ans, a, b, c, d, j, k, l;
using state = std::tuple<u64, u64, u64, u64>;

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
fn gcd(u64 a, u64 b) -> u64 { return (!b) ? a : gcd(b, a%b); }

fn solve() -> void {
    s = q_read(), n = q_read(), m = q_read(), ans = (u64)1<<63;
    g = gcd(s, gcd(n, m)); s /= g, n /= g, m /= g;
    std::queue<state> sq;
    switch(s%2) {
        case 0: {
            memset(v, false, maxs*maxs*maxs*sizeof(u64));
            sq.push({s, 0, 0, 0});
            while(!sq.empty()) {
                state st = sq.front(); sq.pop();
                a = std::get<0>(st), b = std::get<1>(st), c = std::get<2>(st), d = std::get<3>(st);
                l = s - a, j = n - b, k = m - c;
                if(v[a][b][c]) continue; v[a][b][c] = true;
                if((a == b && c == 0) | (b == c && a == 0) | (a == c && b == 0)) { ans = std::min(d, ans); break; }
                if(a > 0) {
                    if(a > j && j > 0) sq.push({a-j, n, c, d+1});
                    if(a > k && k > 0) sq.push({a-k, b, m, d+1});
                    if(a <= j) sq.push({0, a+b, c, d+1});
                    if(a <= k) sq.push({0, b, a+c, d+1});
                }
                if(b > 0) {
                    if(b > l && l > 0) sq.push({s, b-l, c, d+1});
                    if(b > k && k > 0) sq.push({a, b-k, m, d+1});
                    if(b <= l) sq.push({a+b, 0, c, d+1});
                    if(b <= k) sq.push({a, 0, b+c, d+1});
                }
                if(c > 0) {
                    if(c > l && l > 0) sq.push({s, b, c-l, d+1});
                    if(c > j && j > 0) sq.push({a, n, c-j, d+1});
                    if(c <= l) sq.push({a+c, b, 0, d+1});
                    if(c <= j) sq.push({a, b+c, 0, d+1});
                }
            }
            printf("%llu\n", ans);
            break;
        }
        case 1: {
            printf("impossible\n");
            break;
        }
    }
}

fn main() -> i32 {
    T = q_read();
    while(T--) solve();

    return 0;
}