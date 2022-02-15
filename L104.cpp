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

#define int long long

fn abs(i64 n) -> i64 { return n > 0 ? n : -n; }

fn gcd(i64 x, i64 y) -> i64 {
    std::function<i64(i64, i64)> gcdc = [&gcdc](i64 x, i64 y)->i64{ if(y <= 0) return x; else return gcdc(y, x%y); };
    x = abs(x); y = abs(y);
    if(x < y){ x^=y; y^=x; x^=y; }
    return gcdc(x, y);
}

fn solve() -> void {
    u32 n, k, ans = 0; std::cin >> n >> k; u32 pk = u32(sqrt(k) + 1.0), ek = u32(sqrt(pk) + 1.0);
    std::set<u32> tP, tF, st;
    [n, &tF](){
        u32 f[1 + 256]; memset(f, 0, sizeof(f)); f[0] = n;
        for(u32 i = 1; i <= n; i++){f[([]()->u32{u8 t; scanf("%c",&t); return u32(t);}())]++;}
        for(u32 i = 1; i <= 256; i++){if(f[i]) tF.insert(f[i]);}
    }();
    [k, pk, ek, &tP](){
        bool t[1 + pk]; memset(t, 0, sizeof(t));
        for(u32 i = 1; (2*i)+1 <= pk; i++){t[(2*i)+1] = true;} t[2] = true;
        for(u32 i = 1; (2*i)+1 <= ek; i++) if(t[(2*i)+1]) for(u32 j = 2; (((2*i)+1)*j) <= pk; j++){t[(((2*i)+1)*j)] = false;}
        for(u32 i = 1; i <= pk; i++) if(t[i] && !bool(k%i)) tP.insert(i);
    }();

    if(n < k) {

    }
    else if(n == k) { ans = n; }
    else if(n > k) {
        std::queue<u32> sQ; bool v[1 + k]; memset(v, 0, sizeof(v));
        st.insert(k); sQ.push(k); v[k] = true;
        while(!sQ.empty()) {
            u32 cur = sQ.front(); sQ.pop();
            for(auto it = tP.begin(); it != tP.end(); it++)
                if(!bool(cur%(*it))&&!v[cur/(*it)]) {
                    u32 nxt = cur/(*it); st.insert(nxt);
                    sQ.push(nxt); v[nxt] = true;
                }
        }
        ans = st.empty() ? 1 : *st.rbegin();
    }
    
    printf("%d\n", ans);
}

fn main() -> i32 {
    i32 T = [](){u64 t; std::cin >> t; return t;}();
    while(T--){solve();}
    return 0;
}