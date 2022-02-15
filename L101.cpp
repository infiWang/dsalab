#include<iostream>
#include<string>

struct num {
    bool sign;
    std::string n;
    num() {
        sign = false;
        n = "0";
    };
    num(std::string nn) {
        sign = (nn[0] == '-' ? true : false);
        n = [](std::string s) -> std::string {
            while(s.length() > 1){
                if(s.at(0) != '0') return s;
                else s.erase(0,1);
            }
            return s;
        }(nn[0] == '-' ? nn.erase(0,1) : nn);
    };
    num(bool si, std::string nn) {
        sign = si;
        n = nn;
    };
    // num add(num a, num b) {
    //     int la = a.n.length() - 1, lb = b.n.length() - 1, l = std::max(la, lb);
    //     char aa[1 + l], bb[1 + l]; aa[0] = bb[0] = '0';
    //     for(int i = 1; i <= l; i++) {
    //         if (i > la) { aa[i] = '0'; } else { aa[i] = a.n.at(i); }
    //         if (i > lb) { bb[i] = '0'; } else { bb[i] = b.n.at(i); }
    //     }
    //     char s[1 + l + 1]; for(int i = 0; i <= l + 1; i++) s[i] = '0';
    //     for(int i = l; i >= 1; i--) {
    //         int t = s[i] + aa[i] + bb[i] - 3*'0';
    //         s[i] = t%10 + '0'; s[i - 1] = t/10 + '0';
    //     }
    //     return num(a.sign xor b.sign, std::string(s));
    // } 假掉了，仅供参考
};

num add_p(num a, num b) {
        int la = a.n.length(), lb = b.n.length(), l = std::max(la, lb);
        char aa[l + 1], bb[l + 1]; aa[l] = bb[l] = '\0';
        for(int i = 0; i < l; i++) {
            aa[l-1-i] = (i > la - 1 ? '0' : a.n.at(la-1-i));
            bb[l-1-i] = (i > lb - 1 ? '0' : b.n.at(lb-1-i));
        }
        char s[l + 1 + 1]; for(int i = 0; i < l + 1; i++) s[i] = '0'; s[l + 1] = '\0';
        for(int i = 0; i < l; i++) {
            int t = s[l-i] + aa[l-i-1] + bb[l-i-1] - 3*'0';
            s[l-i] = t%10 + '0'; s[l-i-1] = t/10 + '0';
        }
        std::string ss = std::string(s);
        return num(a.sign xor b.sign, std::string(s).erase(0,s[0] == '0' ? 1 : 0));
}

num mul_s(num a, unsigned int b) {
    int l = a.n.length(); char aa[l + 1], s[1 + l + 1]; aa[0] = s[l] = '0'; aa[l] = s[l+1] = '\0';
    for(int i = 0; i < l; i++) { aa[i] = a.n.at(i); s[i] = '0'; }
    for(int i = 0; i < l; i++) {
        int t = (s[l-i] - '0') + (aa[l-i-1] - '0')*b;
        s[l-i] = t%10 + '0'; s[l-i-1] = t/10 + '0';
    }
    return num(a.sign, std::string(s).erase(0,s[0] == '0' ? 1 : 0));
}

num mul(num a, num b) {
    int la = a.n.length(), lb = b.n.length();
    num s = num();
    s.sign = a.sign xor b.sign;
    for(int i = lb - 1; i >= 0; i--) {
        std::string t = mul_s(a, b.n.at(i) - '0').n;
        for(int j = lb-1-i; j > 0; j--) t+='0';
        s.n = add_p(s.n,t).n;
    }
    return s;
}

int main() {
    std::string x, y;
    std::cin >> x >> y;
    ::num a = num(x), b = num(y);
    // std::cout << mul_s(a, 5).n;
    // ::num s = add_p(a, b);
    ::num s = mul(a, b);
    bool f = false;
    for(int i = 0; i < s.n.length(); i++) {
        if(s.n.at(i) != '0') f = true;
    }
    if(!f) {std::cout << "0" << std::endl; return 0;}
    std::cout << (s.sign ? s.n.at(0) != '0' ? "-" : "" : "") << s.n << std::endl;
    // std::cout << s.n << std::endl;
    // ::num ans = mul(a, b);
    return 0;
}