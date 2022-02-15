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

let maxn = i64(1e4 + 2), maxm = i64(2e5 + 2);

#define swap std::swap
fn abs(i64 n) -> i64 { return n > 0 ? n : -n; }
fn abs(f64 n) -> f64 { return n > 0 ? n : -n; }
fn min(i64 m, i64 n) -> i64 { return m - n < 0 ? m : n; }
fn min(u64 m, u64 n) -> u64 { return m - n < 0 ? m : n; }
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

std::queue<std::pair<i64, i64>> ela, elv;
std::vector<i64> gf[maxn], gr[maxn], g[maxn];
bool va[maxn], vu[maxn], vi[maxn];

fn main() -> i32 {
    i64 n = q_read(), m = q_read();
    for(i64 i = 1; i <= m; i++) {
        i64 x = q_read(), y = q_read();
        if(!(x^y)) continue;
        ela.push(std::make_pair(x, y));
        gf[x].push_back(y), gr[y].push_back(x);
    }
    i64 s = q_read(), t = q_read();
    std::queue<i64> sq; sq.push(t);
    while(!sq.empty()) {
        i64 cur = sq.front(); sq.pop();
        if(vi[cur]) continue; va[cur] = vi[cur] = true;
        for(std::vector<i64>::iterator it = gr[cur].begin();
            it < gr[cur].end(); it++) sq.push((*it));
    }
    for(i64 i = 1; i <= n; i++) {
        for(std::vector<i64>::iterator it = gf[i].begin();
            it < gf[i].end(); it++)
        if(!va[(*it)]) { vu[i] = true; break; }
    }
    while(!ela.empty()) {
        if(vu[ela.front().first]) { ela.pop(); continue; }
        g[ela.front().first].push_back(ela.front().second);
        ela.pop();
    }
    memset(vi, 0, sizeof(vi));
    std::queue<std::pair<i64, i64>> sqq; sqq.push(std::make_pair(s, 0));
    u64 ans = -1;
    while((!sqq.empty())&&(!vi[t])) {
        std::pair<i64, i64> cur = sqq.front(); sqq.pop();
        if(vi[cur.first]) continue; vi[cur.first] = true;
        if(!(cur.first^t)) ans = min(ans, u64(cur.second));
        for(std::vector<i64>::iterator it = g[cur.first].begin();
            it < g[cur.first].end(); it++) sqq.push(std::make_pair((*it), cur.second+1));
    }

    printf("%li", ans);

    return 0;
}