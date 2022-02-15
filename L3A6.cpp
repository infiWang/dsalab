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
const u64 mod = 1e8 - 3;
const u64 maxn = 1e5 + 2;

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

struct match {
    i64 n, h;
}
l1[maxn], l2[maxn];

u64 ans;
i64 v[maxn], w[maxn];

fn i_sort(match l[], i64 pl, i64 pr) -> void {
    for (int i = pl+1; i <= pr; i++)
        for (int j = i; j > 0 && l[j].h < l[j-1].h; j--)
            std::swap(l[j], l[j-1]);
}

fn q_sort(match l[], i64 pl, i64 pr) -> void {
    if(pl >= pr) return;
    if(pr - pl < 9) { i_sort(l, pl, pr); return; }
    i64 pu = pl, pv = pr, pi = ((pl+pr)>>1), w = l[pi].h;
    while(pu <= pv) {
        while(l[pu].h < w) pu++;
        while(l[pv].h > w) pv--;
        if(pu <= pv) std::swap(l[pu++], l[pv--]);
    }
    q_sort(l, pl, pv); q_sort(l, pu, pr);
}

fn m_sort(i64 x[], i64 y[], i64 pl, i64 pr) -> void {
    if(pl >= pr) return;
    i64 pu = pl, pm = ((pl+pr)>>1), pv = pm + 1, pt = pl;
    m_sort(x, y, pl, pm); m_sort(x, y, pv, pr);
    while(pu <= pm && pv <= pr) {
        if(x[pu] <= x[pv]) { y[pt++] = x[pu++]; }
        else { y[pt++] = x[pv++]; ans += (pm - pu + 1)%mod; ans%=mod; }
    }
    while(pu <= pm) y[pt++] = x[pu++];
    while(pv <= pr) y[pt++] = x[pv++];
    for(u64 i = pl; i <= pr; i++) x[i] = y[i];
}

fn main() -> i32 {
    i64 n = q_read(); for(u64 i = 1; i <= n; i++) { l1[i].n = i, l1[i].h = q_read(); }
                      for(u64 i = 1; i <= n; i++) { l2[i].n = i, l2[i].h = q_read(); }
    q_sort(l1, 1, n), q_sort(l2, 1, n);
    for(u64 i = 1; i <= n; i++) v[l1[i].n] = l2[i].n;
    m_sort(v, w, 1, n);
    printf("%lld", ans);

    return 0;
}