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

fn abs(i64 n) -> i64 { return n > 0 ? n : -n; }
fn min(i64 m, i64 n) -> i64 { return m - n < 0 ? m : n; }
fn max(i64 m, i64 n) -> i64 { return m - n > 0 ? m : n; }

fn sx(char c) -> i64 {
    switch (c)
    {
    case 'L':
        return -1;
        break;
    case 'R':
        return 1;
        break;
    
    default:
        return 0;
        break;
    }
}
fn sy(char c) -> i64 {
    switch (c)
    {
    case 'U':
        return 1;
        break;
    case 'D':
        return -1;
        break;
    
    default:
        return 0;
        break;
    }
}

u64 x[1 + u64(3e4) + 1], y[1 + u64(3e4) + 1];
fn main() -> i32 {
    i64 rx, ry, cx, cy, n; std::cin >> rx >> ry >> cx >> cy >> n; i64 dis = abs(rx-cx) + abs(ry-cy);
    std::string s; std::cin >> s; s = ' ' + s;
    i64 mx[1 + n], my[1 + n], dx = 0, dy = 0; mx[0] = 0, my[0] = 0;
    i64 tx[1 + n], ty[1 + n]; tx[0] = 0, ty[0] = 0;
    for(i64 i = 1; i <= n; i++) mx[i] = sx(s.at(i)), my[i] = sy(s.at(i));
    for(i64 i = 1; i <= n; i++) { tx[i] = tx[i-1]+mx[i], ty[i] = ty[i-1]+my[i]; } tx[0] = tx[n]+mx[1], ty[0] = ty[n]+my[1];
    u64 btm = 0, mid = 5e8, top = 1e9;
    while(btm < top) {
        i64 
    }
}