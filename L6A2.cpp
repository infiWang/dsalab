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
const u64 maxn = 1e6 + 2;

u64 nxt[maxn], cnt[maxn];

fn main() -> i32 {
    std::string s0;
    std::cin >> s0;
	s0 = " " + s0;
    u64 l0 = s0.length()-1;

	u64 p = 0, c = 0;
	for(u64 i = 2; i <= l0; i++) {
		while(p > 0 && s0[i] != s0[p+1]) p = nxt[p];
		if(s0[i] == s0[p+1]) p++;
		nxt[i] = p;
	}

    for(u64 i = 1; i <= l0; i++) cnt[nxt[i]]++;
    if(nxt[l0] >= l0-1) { printf("%lu\n", l0-2); goto ret; }
    p = nxt[l0], c = 0;
    // while(p > c) p = nxt[p], c++;
    // if(p&1) { for(u64 i = 1; i <= c; i++) printf("%c",s0[i]); goto ret; }
    if(cnt[nxt[l0]] >= 2 && nxt[l0] > 0)
    for(u64 i = 1; i <= nxt[l0]; i++) printf("%c",s0[i]);
    else printf("-1");
    printf("\n");
	
    ret:
	return 0;
}