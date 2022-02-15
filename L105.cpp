#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>

// WOW VERY MODERN SO CHROMIUM GOOD LANG
#define i8 char
#define i16 signed short
#define i32 signed
#define i64 signed long long
#define u8 unsigned char
#define u16 unsigned short
#define u32 unsigned
#define u64 unsigned long long
#define fn auto
#define let const auto

#define int long long

u64 D[1 + 1000 + 1][1 + 1000 + 1];
bool V[1 + 1000 + 1][1 + 1000 + 1];

struct Stat{
    u32 x, y; u64 w;
    Stat(u32 nx, u32 ny, u64 nw){ x = nx, y = ny, w = nw; }
    bool operator < (const Stat& tStat) const { return w > tStat.w; }
};

fn abs(i64 n) -> i64 { return n > 0 ? n : -n; }
fn max(i64 n, i64 m) -> i64 { return n - m > 0 ? n : m; }
fn min(i64 n, i64 m) -> i64 { return n - m < 0 ? n : m; }


i64 mx[4] = {1, 0, -1, 0},
    my[4] = {0, 1, 0, -1};

fn main() -> i32 {
    u32 N, M;
    scanf("%u %u", &N, &M);
    // int D[1 + N + 1][1 + M + 1];
    // bool V[1 + N + 1][1 + M + 1];
    // memset(D, 0, sizeof(D));
    // memset(V, false, sizeof(V));
    for(u32 i = 0; i <= M + 1; i++)
        for(u32 j = 0; j <= N + 1; j++){
            D[j][i] = 3e18;
        }
    for(u32 i = 1; i <= N; i++)
        for(u32 j = 1; j <= M; j++){
            scanf("%llu", &D[i][j]);
        }
    u64 ans = 0;
    std::priority_queue<Stat> sQ;
    for(u32 i = 1; i <= M; i++){
        sQ.push(Stat(1, i, 0));
        V[1][i] = true;
    }
    while(!sQ.empty()) {
        Stat cur = sQ.top(); sQ.pop();
        ans = max(ans, cur.w);
        if(cur.x >= N) break;
        for(u32 i = 0; i < 4; i++) {
            u64 nx = cur.x + mx[i], ny = cur.y + my[i];
            if(!V[nx][ny]){
                sQ.push(Stat(nx, ny, D[nx][ny]));
                V[nx][ny] = true;
            }
        }
    }

    printf("%llu\n", ans);

    return 0;
}