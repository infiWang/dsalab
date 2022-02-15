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
#define mut mutable
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef float_t f32;
typedef double_t f64;

fn swap(i64* u, i64* v) { i64 t = *u; *u = *v; *v = t; }
fn abs(i64 n) -> i64 { return n > 0 ? n : -n; }
fn abs(f64 n) -> f64 { return n > 0 ? n : -n; }
fn min(i64 m, i64 n) -> i64 { return m - n < 0 ? m : n; }
fn max(i64 m, i64 n) -> i64 { return m - n > 0 ? m : n; }
inline fn q_read() -> i64 {
    bool sign = false; i64 ans = 0;
    char ch = getchar();
    while((ch < '0' || ch > '9') && ch != '-' ) ch = getchar();
    if(ch == '-') { sign = true; ch = getchar(); }
    while(ch >= '0' && ch <= '9'){
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return sign ? -ans : ans ;
}


struct Edge {
    int u, v;

    Edge(int _u = 0, int _v = 0) {
        u = _u, v = _v;
    }
}
emptyEdge;

struct Vertex {
    std::vector<Edge> out;

    Vertex() { out.clear(); }
};

inline int qRead() {
    int ans = 0;
    char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}

inline void addEdge(Vertex* graph, Edge e) {
    graph[e.u].out.push_back(e);
}

let maxn = i64(2 + 1e5);
Vertex graph[maxn];
i64 vis[maxn];

fn dfs(i64 s, i64 mark) -> void {
    if(graph[s].out.empty()) return;
    for(std::vector<Edge>::iterator it = graph[s].out.begin(); it != graph[s].out.end(); it++){
        int v = (*it).v;
        if(vis[v] <= 0) vis[v] = mark, dfs(v, mark);
    }
}

fn solve() -> void {
    let n = i64(q_read()), m = i64(q_read());
    for(i64 i = 1; i <= m; i++) {
        i64 s = q_read(), t = q_read();
        addEdge(graph, Edge(t, s));
    }
    for(i64 i = n; i >= 1; i--) if(vis[i] <= 0) vis[i] = i, dfs(i, i);
    for(i64 i = 1; i <= n; i++) printf("%ld ", vis[i]);
}

fn main() -> i32 {
    i64 T = 1;
    while(T--) solve();

    return 0;
}
