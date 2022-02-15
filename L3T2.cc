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

using state = std::tuple<char, u64>;

let maxs = u64(1e4 + 2);
let deC = i64('a'-'A'), enC = i64('A'-'a');
u64 T;
u64 cc, sc;
i64 gstr[maxs][maxs], sum[2+(1<<8)];
char cs[2+26], chs[maxs][2];
bool owe[2+(1<<8)], v[2+(1<<8)], e[2+(1<<8)][2+(1<<8)], cu[2+(1<<8)];
std::string str;

fn dfs(u64 cst) -> void {
    if (cst > cc) {
        sc = std::max(sc, [](){
            u64 s = 0;
            for (u64 i = 1; i <= cc; i++)
                if (v[cs[i]]) s += sum[cs[i]];
            return s;
        }());
    } else {
        if (v[cs[cst]]) dfs(cst+1);
        else {
            v[cs[cst]] = true;
            for (int i = 0; i <= cc; i++)
                if (!v[cs[i]] && cs[cst]!=cs[i])
                    sum[cs[i]] -= gstr[cs[cst]][cs[i]];
            dfs(cst+1);
            for (int i = 0; i <= cc; i++)
                if (!v[cs[i]] && cs[cst]!=cs[i])
                    sum[cs[i]] += gstr[cs[cst]][cs[i]];
            v[cs[cst]] = false;
            dfs(cst+1);
        }
    }
}

fn solve() -> void {
    memset(gstr, 0, sizeof(gstr)), memset(v, false, sizeof(v)), memset(e, false, sizeof(e));
    sc = cc = 0;
    std::cin >> str;
    u64 lstr = str.length();
    for(u64 i = 1; i < lstr; i++) {
        char lch = str[i-1], rch = str[i]; cu[rch] = true;
        if(!owe[lch] && !owe[rch]) gstr[lch][rch]++; gstr[rch][lch]++;
    }
    cu[str[0]] = true;
    for(char i = 'b'; i <= 'z'; i++) {
        gstr[i][i] = 0;
        if(cu[i]) cs[cc++] = i;
    }
    for(char i = 0; i < cc; i++)
        for(char j = 0; j < cc; j++)
            sum[cs[i]] += gstr[cs[i]][cs[j]];

    dfs(0);

    printf("%llu\n", sc);
}

fn main() -> i32 {
    std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
    owe['a'] = owe['e'] = owe['i'] = owe['o'] = owe['u'] = true;
	std::cin >> T;
	while(T--) solve();

	return 0;
}