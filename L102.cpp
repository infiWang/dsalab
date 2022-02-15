#include<iostream>
#include<cstdio>
#include<cstring>

char cubic[5][5] = {
    {'+','-','+','.','.'},
    {'|','.','|','/','.'},
    {'+','-','+','.','+'},
    {'.','/','.','/','|'},
    {'.','.','+','-','+'}
};
char cache[128][128];

void solve() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    a^=c; c^=a; a^=c;
    int x = 2*a + 1 + 2*b, y = 2*c + 1 + 2*b;
    for(int i = 0; i < x; i++)
        for(int j = 0; j < y; j++)
            cache[i][j] = '.';
    for(int i = 0; i < 2*b; i += 2) {
        int rx = x - i - 1, ry = y - i - 1;
        int lx = rx-2*(a-1), ly = ry-2*(c-1);
        for(int j = 0; j < a; j++) {
            for(int k = 0; k < c; k++) {
                int cx = lx + 2*j, cy = ly + 2*k;
                for(int m = 0; m < 5; m++) {
                    for(int n = 0; n < 5; n++) {
                        if((4-m)+n > 1 && (4-m)+n < 7)
                        cache[cx - m][cy - n] = cubic[4 - m][4 - n];
                    }
                }
            }
        }
    }
    for(int i = x-1; i >= 0; i--) {
        for(int j = 0; j < y; j++) {
            printf("%c",cache[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int T;
    std::cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}