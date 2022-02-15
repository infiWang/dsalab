#include<functional>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
// #include<unistd.h>

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

fn abs(i64 n) -> i64 { return n > 0 ? n : -n; }
fn min(i64 m, i64 n) -> i64 { return m - n < 0 ? m : n; }
fn max(i64 m, i64 n) -> i64 { return m - n > 0 ? m : n; }

u64 H[1 + u64(3e4) + 1];
fn main() -> i32 {
    u64 N, K, M = 0; scanf("%llu %llu", &N, &K);
    for(u64 i = 1; i <= N; i++) scanf("%llu", H+i);
    for(u64 i = 1; i < N; i++) M = max(H[i]+H[i+1], M);
    u64 btm = 1, top = M, mid = u64((btm+top)/2), ans = 0;
    while(btm < top) {
        u64 h[1 + N + 1]; memcpy(h, H, sizeof(h)); h[N + 1] = 0;
        u64 cur = 0;
        for(u64 i = 1; i <= N; i++) {
            // if(cur >= K) break;
            u64 u = h[i]/mid, v = (h[i]+h[i+1])/mid;
            if(v) {
                if(u<v) {
                    cur+=v;
                    h[i+1] = (h[i]+h[i+1])%mid, h[i] = 0;
                } else {
                    cur+=u;
                    h[i] = h[i]%mid;
                }
            } else {
                // u64 br=h[i]+h[i+1];
                // if(br/mid*mid) {
                //     h[i+1]=br%mid;
                //     cur+=br;
                // }
            }
        }
        if(cur >= K) { btm = mid, mid = u64((btm+top+1)/2); }
        else { top = mid-1, mid = u64((btm+top+1)/2); }
        // printf("Cur: %llu, Btm: %llu, Mid: %llu, Top: %llu\n", cur, btm, mid, top);
        // sleep(1);
    }
    // for(u64 i = 1; i <= N; i++) {
    //     if(cur >= K) break;
    //     u64 u = (h[i]+h[i+1])/mid*mid;//, v = h[i]/mid*mid;
    //     if(u) {
    //         cur += u;
    //         h[i]=0, h[i+1]=u%mid;
    //     } else {
    //         // u64 br=h[i]+h[i+1];
    //         // if(br/mid*mid) {
    //         //     h[i+1]=br%mid;
    //         //     cur+=br;
    //         // }
    //     }
    // }

    printf("%llu\n", mid*K);

    return 0;
}