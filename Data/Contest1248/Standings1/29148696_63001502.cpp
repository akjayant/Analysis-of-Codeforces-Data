#include <bits/stdc++.h>
using namespace std;

const int N = 300000;
char s[N+10];

int check(int n){
    int ret = 0, cntl = 0, cntr = 0;
    for (int i = 0; i < n; ++i){
        if (s[i] == '(') ++cntl;
        else ++cntr;
    }
    if (cntl != cntr) return ret;
    cntl = 0;
    for (int i = 0; i < n; ++i){
        if (!cntl) ++ret;
        if (s[i] == '(') ++cntl;
        else{
            if (cntl) --cntl;
            else ret = 0;
        }
    }
    return ret;
}

int main(){
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    int ans = 0, l = 1, r = 1;
    for (int i = 0; i < n; ++i){
        for (int j = i; j < n; ++j){
            swap(s[i], s[j]);
            int t = check(n);
            if (t > ans){
                ans = t;
                l = i + 1;
                r = j + 1;
            }
            swap(s[i], s[j]);
        }
    }
    printf("%d\n%d %d\n", ans, l, r);
    return 0;
}