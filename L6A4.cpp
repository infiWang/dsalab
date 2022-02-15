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
const i64 maxn = 2 + 10e5;

struct node {
    i32 len, lnk;
    std::map<i8, i32> nxt;
} sam[2*maxn]; i32 ssize, last;

fn build(char ch) -> void {
  i32 cur = ssize++;
  sam[cur].len = sam[last].len + 1;
  i32 p = last;
  while (p >= 0 && !sam[p].nxt.count(ch)) {
    sam[p].nxt[ch] = cur;
    p = sam[p].lnk;
  }

  if (p < 0) { sam[cur].lnk = 0; }
  else {
    i32 q = sam[p].nxt[ch];
    if (sam[p].len + 1 == sam[q].len) {
      sam[cur].lnk = q;
    } else {
      i32 r = ssize++;
      sam[r].len = sam[p].len + 1;
      sam[r].nxt = sam[q].nxt;
      sam[r].lnk = sam[q].lnk;
      while (p > 0 && !(sam[p].nxt[ch]^q)) {
        sam[p].nxt[ch] = r;
        p = sam[p].lnk;
      }
      sam[q].lnk = sam[cur].lnk = r;
    }
  }
  last = cur;
}

fn main() -> i32 {
    std::string s1, s2;
    std::cin >> s1 >> s2;
    sam[0].len = 0, sam[0].lnk = -1;
    ssize++, last = 0;
    for(i32 i = 0; i < s2.length(); i++) build(s2[i]);

    i32 v = 0, l = 0, ll = 0;
    for (i32 i = 0; i < s1.length(); i++) {
      while (v && !sam[v].nxt.count(s1[i])) {
        v = sam[v].lnk;
        l = sam[v].len;
      }
      if (sam[v].nxt.count(s1[i])) {
        v = sam[v].nxt[s1[i]];
        l++;
      }
      ll = (l > ll ? l : ll);
    }
    std::cout << ll << std::endl;

    return 0;
}