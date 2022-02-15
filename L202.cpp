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

u64 A[1 + u64(3e5) + 1];
fn main() -> i32 {
    u64 N, M; scanf("%llu %llu", &N, &M);
    for(u64 i = 1; i <= 3e5; i++) A[i] = 2e18;
    for(u64 i = 1; i <= N; i++) scanf("%llu", A+i);
    for(u64 i = 1; i <= M; i++) {
        u64 K, btm = 1, mid = 15e4, top = 3e5;
        scanf("%llu", &K);
        while(btm < top) {
            if(A[mid] < K) btm = mid + 1, mid = u64((btm+top)/2);
            else top = mid, mid = u64((btm+top)/2);
        }
        printf("%s\n", A[mid] == K ? "YES" : "NO");
    }
    return 0;
}