#include<functional>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<map>
#include<algorithm>

// WOW VERY MODERN SO CHROMIUM GOOD LANG
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

#define int long long

fn abs(i64 n) -> i64 { return n > 0 ? n : -n; }

fn gcd(i64 x, i64 y) -> i64 {
    std::function<i64(i64, i64)> gcdc = [&gcdc](i64 x, i64 y)->i64{ if(y <= 0) return x; else return gcdc(y, x%y); };
    x = abs(x); y = abs(y);
    if(x < y) { x^=y; y^=x; x^=y; }
    return gcdc(x, y);
}

fn main() -> i32 {
    u64 N = [](){ u64 t; std::cin >> t; return t; }(), cAm = 0, cAn = 0, cBm = 0, cBn = 0, cTX = 0, cTY = 0, dC = 0, st = 0;
    u8 m[N + 1], n[N + 1]; memset(m, 0, sizeof(m)); memset(n, 0, sizeof(n));
    std::cin >> m >> n;
    for(u64 i = 0; i < N; i++) { 
        if(m[i] == 'A') cAm++; else cBm++;
        if(n[i] == 'A') cAn++; else cBn++;
        if(m[i] != n[i]) dC++;
    }
    if(cAm!=cAn||cBm!=cBn) { printf("%d", -1); return 0; }
    bool d[dC]; memset(d, 0, sizeof(d));
    for(u32 i = 0, p = 0; i < N; i++) if(m[i] != n[i]) { d[p++] = (m[i] == 'A' ? false : true); }
    for(u32 i = 0; i < dC; i++)
        if(!d[i]){
            if(cTX<=0) st++, cTY++;
            else cTX--, cTY++;
        } else {
            if(cTY<=0) st++, cTX++;
            else cTX++, cTY--;
        }
    printf("%llu", st);
    return 0;
}