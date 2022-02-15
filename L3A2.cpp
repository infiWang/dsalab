
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

i64 nums[i64(1 + 3e6 + 1)], n;

fn i_sort(i64 pl, i64 pr) -> void {
    for (int i = pl+1; i <= pr; i++)
        for (int j = i; j > 0 && nums[j] < nums[j-1]; j--)
            swap(nums+j, nums+j-1);
}

fn find_pi(i64 pl, i64 pr) -> i64 {
    if(pl >= pr) return pl;
    i64 p = 0, pn = 0;
    for(p = pl; p < pr - 5; p += 5) {
        i_sort(p, (p+4));
        pn = p - pl;
        swap(nums+pl+(pn/5), nums+p+2);
    }
    i64 lft = pr - p + 1;
    if(lft > 0) {
        i_sort(p, p + lft - 1);
        swap(nums+pl+(pn/5), nums+p+lft/2);
    }
    pn /= 5;
    return pn <= pl ? pl : find_pi(pl, pl+pn);
}

fn q_sort(i64 pl, i64 pr, i64 k) -> i64 {
    if(pl == pr && pl == k) return nums[k];
    // if(pl >= pr) return;
    i64 pu = pl, pv = pr, w = nums[pl];
    while(pu < pv) {
        while(nums[pv] >= w && pu < pv) pv--;
        swap(nums+pu, nums+pv);
        while(nums[pu] <= w && pu < pv) pu++;
        swap(nums+pu, nums+pv);
    }
    nums[pu] = w;
    if(pu == k) return nums[k];
    return pu > k ? q_sort(pl, pu-1, k) : q_sort(pu+1, pr, k);
}

fn main() -> i32 {
    n = q_read(); i64 k = q_read(); for( u64 i = 1; i <= n; i++ ) { nums[i] = q_read(); }
    printf("%lld", q_sort(1, n, k));

    return 0;
}