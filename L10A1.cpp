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

let mod = i64(10007), maxn = i64(1005);

fn swap(i64* u, i64* v) { *u ^= *v; *v ^= *u; *u ^= *v; }
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
inline fn q_pow(i64 x, i64 y) -> i64 {
    i64 pow = 1;
    while(y != 0) {
        if(y & 1) pow = pow * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return pow;
}

i64 a, b, k, n, m, dp[maxn][maxn];

fn main() -> i32 {
    scanf("%ld %ld %ld %ld %ld", &a, &b, &k, &n, &m);
    
    a = q_pow(a, n), b = q_pow(b, m);
    for (i64 i = 1; i <= k; i++) dp[i][0] = 1, dp[i][i] = 1;
    for (i64 i = 2; i<=k; i++) for (i64 j = 1; j <= min(n, m); j++)
        dp[i][j] = (dp[i-1][j] + dp[i-1][j-1])%mod;
    printf("%ld\n",((((a*b)%mod)*dp[k][min(n, m)])%mod));

    return 0;
}