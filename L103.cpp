#include<iostream>
#include<cstdio>
#include<algorithm>

void solve() {
    long long int n, k, ans = 0, scnt = 0;
    scanf("%lld %lld", &n, &k);
    long long int s[1 + n], w[1 + k];
    for(int i = 1; i <= n; i++) scanf("%lld", s+i);
    for(int i = 1; i <= k; i++) scanf("%lld", w+i);
    for(int i = 1; i <= k; i++) if(w[i] <= 1) scnt++;
    std::sort(s+1, s+n+1); std::sort(w+1, w+k+1);
    for(long long int i = 1, c = scnt; i <= k; i++) ans+=(s[n-i+1]*((c-->0) ? 2 : 1));
    for(long long int i = 1, p = 1; i <= k-scnt; i++) {
        ans+=s[p];
        p+=(w[k-i+1]-1);
    }
    std::cout << ans << std::endl;
}

int main() {
    int T;
    std::cin >> T;
    while(T--){solve();}
    return 0;
}