#include<functional>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<map>
#include<algorithm>

#define fn auto
#define let const auto
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

fn swap(i64* u, i64* v) { i64 t = *u; *u = *v; *v = t; }
fn abs(i64 n) -> i64 { return n > 0 ? n : -n; }
fn abs(f64 n) -> f64 { return n > 0 ? n : -n; }
fn min(i64 m, i64 n) -> i64 { return m - n < 0 ? m : n; }
fn max(i64 m, i64 n) -> i64 { return m - n > 0 ? m : n; }
inline fn q_read() -> i64 {
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
let maxn = i64(2 + 1e5);

struct node {
    i64 v;
    std::priority_queue<i64, std::vector<i64>, std::greater<i64>> s;
} tr[maxn];

fn solve() -> void {
    let n = q_read();
    for(i64 i = 2; i <= n; i++) { tr[q_read()].s.push(i); }
    std::queue<i64> sq;
    sq.push(1);
    while(!sq.empty()) {
        i64 stat = sq.front(); sq.pop();
        printf("%li ", stat);
        while(!tr[stat].s.empty()) sq.push(tr[stat].s.top()), tr[stat].s.pop();
    }
    printf("\n");
}

fn main() -> i32 {
    for(i64 i = 1; i <= maxn; i++) tr[i].v = i;
    i64 T = q_read();
    while(T--) solve();

    return 0;
}