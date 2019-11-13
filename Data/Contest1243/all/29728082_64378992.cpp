#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const int N = 1e4 + 5, M = 3e5 + 5;

char s[N], t[N];
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d%s%s", &n, &s, &t);
        vector<int> v;
        for(int i = 0 ; i < n ; ++i)
            if(s[i] != t[i])v.emplace_back(i);
        if(v.size() > 2 || v.size() == 1){
            puts("No");
            continue;
        }
        if(v.size() == 0){
            puts("Yes");
            continue;
        }
        if(s[v[0]] == s[v[1]] && t[v[1]] == t[v[0]])
            puts("Yes");
        else puts("No");
    }
}