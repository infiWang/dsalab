
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

fn swap(i64* u, i64* v) { i64 t = *u; *u = *v; *v = t; }
fn abs(i64 n) -> i64 { return n > 0 ? n : -n; }
fn abs(f64 n) -> f64 { return n > 0 ? n : -n; }
fn min(i64 m, i64 n) -> i64 { return m - n < 0 ? m : n; }
fn max(i64 m, i64 n) -> i64 { return m - n > 0 ? m : n; }
inline fn q_read() -> i64 {
    i64 ans = 0;
    char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9'){
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}

i64 nums[i64(1 + 3e6 + 1)];

fn i_sort(i64 pl, i64 pr) -> void {
    for (int i = pl+1; i <= pr; i++)
        for (int j = i; j > 0 && nums[j] < nums[j-1]; j--)
            swap(nums+j, nums+j-1);
}

fn q_sort(i64 pl, i64 pr) -> void {
    if(pl >= pr) return;
    if(pr - pl < 9) { i_sort(pl, pr); return; }
    i64 pu = pl, pv = pr, pi = ((pl+pr)>>1), w = nums[pi];
    while(pu <= pv) {
        while(nums[pu] < w) pu++;
        while(nums[pv] > w) pv--;
        if(pu <= pv) std::swap(nums[pu++], nums[pv--]);
    }
    q_sort(pl,pv); q_sort(pu,pr);
}

fn main() -> i32 {
    i64 n = q_read(); for( u64 i = 1; i <= n; i++ ) { nums[i] = q_read(); }
    q_sort(1, n);
    for( u64 i = 1; i < n; i++ ) { printf("%lld ", nums[i]); } printf("%lld", nums[n]);

    return 0;
}