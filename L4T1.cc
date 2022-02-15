#include <functional>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>

#define fn auto
#define let const auto
#define mut mutable
#define il inline
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

let maxn = u64(2+1e5), maxm = u64(2+1e5);
u64 n, m, dep[maxn];
std::vector<u64> oe[maxn];
bool v[maxn];

il fn q_read() -> i64 {
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

fn main() -> i32 {
	n = q_read(), m = q_read();
    for(u64 i = 1; i <= m; i++) {
        u64 p = q_read(), q = q_read();
        oe[p].push_back(q); dep[q]++;
    }

    // auto cmp = [](u64 p, u64 q) {
    //     std::string a = std::to_string(p), b = std::to_string(q);
    //     u64 lin = std::min(a.length(), b.length()), lax = std::max(a.length(), b.length());
    //     for(u64 i = 0; i < lin; i++) {
    //         if(a[i] - b[i] > 0) return true;
    //         if(a[i] - b[i] < 0) return false;
    //     }
    //     return a.length() - b.length() < 0 ? true : false;
    // };
    // std::priority_queue<u64, std::vector<u64>, decltype(cmp)> sq(cmp);
    std::priority_queue<u64, std::vector<u64>, std::greater<u64>> sq;
    for(u64 i = 1; i <= n; i++) if(dep[i] < 1) sq.push(i);
    while(!sq.empty()) {
        u64 cur = sq.top(); sq.pop();
        if(v[cur]) continue; v[cur] = true;
        printf("%llu ", cur);
        for(std::vector<u64>::iterator it = oe[cur].begin(); it < oe[cur].end(); it++) {
            dep[(*it)]--;
            if(dep[(*it)] < 1) sq.push(*it);
        }
    }
    printf("\n");

	return 0;
}