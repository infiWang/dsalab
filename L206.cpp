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
typedef char i8;
typedef signed short i16;
typedef signed i32;
typedef signed long long i64;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;

fn abs(i64 n) -> i64 { return n > 0 ? n : -n; }
fn abs(f64 n) -> f64 { return n > 0 ? n : -n; }
fn min(i64 m, i64 n) -> i64 { return m - n < 0 ? m : n; }
fn max(i64 m, i64 n) -> i64 { return m - n > 0 ? m : n; }

fn main() -> i32 {
    u64 n, m, k, p; scanf("%llu %llu %llu %llu", &n, &m, &k, &p); u64 tot = 0;
    u64 w[1+n+1]; w[0] = w[n+1] = 0; for(u64 i = 1; i <= n; i++) { u64 wi, ai; scanf("%llu %llu", &wi, &ai); w[i] = wi+m*ai; tot += w[i]; }
    if(tot <= k*m*p) { printf("0"); return 0; }
    
    u64 btm = 0, top = 2e18, mid = 1e18;
    while(btm < top) {
        printf("Btm: %llu, Mid: %llu, Top: %llu\n", btm, mid, top);
        if(mid == 18)
        {
            printf("It's a trap!");
            // return 0;
        }
        i64 cu = k*m; bool fl = true;
        for(u32 i = 1; i <= n; i++) {
            i64 t = w[i] - mid;
            if(t >= 0) {
                if(w[i]/p > 0) cu-=(w[i]/p); else fl = false;
            }
        }
        if(cu < 0 && fl) { btm = mid, mid = (btm + top)/2; }
        else             { top = mid - 1, mid = (btm + top)/2; }
    }
    printf("Btm: %llu, Mid: %llu, Top: %llu\n", btm, mid, top);

    return 0;
}