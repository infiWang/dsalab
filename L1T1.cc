#include<functional>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<algorithm>

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

let maxn = i64(1e3 + 2);
u64 n, curm, curf;
u64 matem[maxn], matef[maxn];
u64 pim[maxn][maxn], pif[maxn][maxn];
std::map<u64, std::string> mapm, mapf;
std::map<std::string, u64> mapj, mapk;
std::string s;
std::queue<u64> sq;

fn swap(i64* u, i64* v) { i64 t = *u; *u = *v; *v = t; }
fn abs(i64 n) -> i64 { return n > 0 ? n : -n; }
fn abs(f64 n) -> f64 { return n > 0 ? n : -n; }
fn min(i64 m, i64 n) -> i64 { return m - n < 0 ? m : n; }
fn max(i64 m, i64 n) -> i64 { return m - n > 0 ? m : n; }
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
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n;
	for(u64 i = 1; i <= n; i++){
		std::cin >> s;
		mapj.insert(std::pair<std::string, u64>(s, i));
		mapm.insert(std::pair<u64, std::string>(i, s));
	}
	for(u64 i = 1; i <= n; i++){
		std::cin >> s;
		mapk.insert(std::pair<std::string, u64>(s, i));
		mapf.insert(std::pair<u64, std::string>(i, s));
	}
	for(u64 i = 1; i <= n; i++){
		for(u64 j = 1; j <= n; j++){
			std::cin >> s;
			pim[i][j] = mapk.find(s)->second;
		}
	}
	for(u64 i = 1; i <= n; i++){
		for(u64 j = 1; j <= n; j++){
			std::cin >> s;
			pif[i][mapj.find(s)->second] = j;
		}
	}

	for(u64 i = 1; i <= n; i++){ sq.push(i); }
	while(!sq.empty()){
		curm = sq.front(), sq.pop();
		for(matem[curm] ? false : matem[curm]++; matem[curm] <= n; matem[curm]++){
			curf = pim[curm][matem[curm]];
			if(matef[curf] < 1) { matef[curf] = curm; break; }
			else if (matef[curf] > 0 && pif[curf][curm] < pif[curf][matef[curf]]){
				sq.push(matef[curf]);
				matem[matef[curf]]++;
				matef[curf] = curm;
				break;
			}
		}
	}
	
	for(u64 i = 1; i <= n; i++){
		// printf("%lu %lu\n", i, matem[i]);
		printf("%s %s\n", mapm.find(i)->second.c_str(), mapf.find(pim[i][matem[i]])->second.c_str());
	}

	return 0;
}