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

struct Posc {
    u64 x, ymin, ymax;
    Posc() { x = ymax = 0., ymin = 2e9; }
    bool operator < (const Posc& tPc) const { return x < tPc.x; }
};
struct Pos {
    u64 x, y;
    Pos() { x = y = 0; }
    bool operator < (const Pos& tP) const { if(x <= tP.x) { if(x < tP.x) return true; else return y < tP.y; } else return false; }
};

Pos pt[1 + u64(3e5) + 1];
Posc ptn[1 + u64(3e5) + 1];
fn main() -> i32 {
    u32 n; scanf("%ud", &n);
    for(int i = 1; i <= n; i++) { scanf("%llu %llu", &((pt+i)->x), &((pt+i)->y)); }
    std::sort(pt+1, pt+n+1); pt[0].x = pt[0].y = 0.; pt[n+1].x = pt[n+1].y = 5e9;

    u32 t = 1;
    for(u32 i = 1; i <= n; i++) { if(pt[i].x != pt[i+1].x) {ptn[t].x = pt[i].x; ptn[t].ymax = pt[i].y; ptn[++t].x = pt[i+1].x; ptn[t].ymin = pt[i+1].y;} }
    if(ptn[1].x <= 0) { ptn[1].ymin = ptn[1].ymax; } else { ptn[1].ymin = pt[1].y; } t--;
    f64 btm = .0, top = 2e8, e = 1e8;
    while(abs(top - btm) > .01) {
        u8 stat = 0; f64 l, u; l = u = 0.;
        if(ptn[1].x <= 0 && ptn[1].ymin > e) { stat = 3; }
        else for(u64 i = 0; i < t; i++) {
            f64 nl = min(l, ptn[i+1].ymin), nu = max(u, ptn[i+1].ymax);
            if((nu - nl) > (stat > 0 ? 2 : 1)*e) { stat++; l = ptn[i+1].ymin, u = ptn[i+1].ymax; }
            else { l = nl, u = nu; }
        }
        if(stat < 3) { top = e; e = (btm + top)/2.; }
        else         { btm = e; e = (btm + top)/2.; }
    }

    printf("%.1lf", e);

    return 0;
}