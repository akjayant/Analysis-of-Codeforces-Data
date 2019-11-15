#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;
const int N = 10010;
char s[N], t[N];
int pos[N];
inline int cmp(const int &a, const int &b) {return a > b;}
int main()
{
    int n, T;
    cin>>T;
    while(T--){
        int cnt = 0;
        scanf("%d", &n);
        scanf("%s", s + 1);
        scanf("%s", t + 1);
        for (int i = 1; i <= n; ++i){
            if (s[i] != t[i]) pos[++cnt] = i;     
        }    
        if (cnt == 0 || (cnt == 2 && s[pos[1]] == s[pos[2]] && t[pos[1]] == t[pos[2]])) printf("Yes\n");
        else printf("No\n");
    }    
    // system("pause");
}