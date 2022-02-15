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

let MAXN = i64(2e5 + 2), mod = i64(10007);

#define swap std::swap
fn abs(i64 n) -> i64 { return n > 0 ? n : -n; }
fn abs(f64 n) -> f64 { return n > 0 ? n : -n; }
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

std::queue<std::pair<i64, i64>> q;
i64 w[MAXN], deg[MAXN];
i64 sum[MAXN], maxn[MAXN][2];

fn main() -> i32 {
    i64 n = q_read();
    for(i64 i = 1; i < n; i++) q.push(std::make_pair(q_read(), q_read()));
    for(i64 i = 1; i <= n; i++) w[i] = q_read();

    for(i64 i = 1; i < n; i++) {
        i64 u = q.front().first, v = q.front().second; q.pop();
        sum[u] = (sum[u] + w[v])%mod, sum[v] = (sum[v] + w[u])%mod; deg[u]++, deg[v]++;
        if(w[v] > maxn[u][0]) maxn[u][0] = w[v]; if(maxn[u][0] > maxn[u][1]) swap(maxn[u][0], maxn[u][1]);
        if(w[u] > maxn[v][0]) maxn[v][0] = w[u]; if(maxn[v][0] > maxn[v][1]) swap(maxn[v][0], maxn[v][1]);
    }

    i64 ans = 0, maxm = 0;
    for(i64 i = 1; i <= n; i++) {
        ans = (ans + (sum[i]*sum[i]) - ((deg[i]%mod)*(w[i]*w[i])))%mod;
        maxm = max(maxm, maxn[i][0]*maxn[i][1]);
    }
    if(ans < 0) ans += mod;
    printf("%ld %ld\n", maxm, ans);

    return 0;
}