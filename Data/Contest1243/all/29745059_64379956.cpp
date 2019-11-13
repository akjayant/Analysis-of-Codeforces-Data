#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0);\
           cin.tie(0);\
           cout.tie(0);
typedef long long ll;
typedef pair<int,int> pii;
const int mod = 1e9+7;
const int maxn = 1e5 + 5;
const int maxm = 2e6 + 5;
int n,a[maxn],tot;
char s[maxn],t[maxn];
int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in","r",stdin);
#endif
    IO;
    int T;
    cin>>T;
    while (T--) {
        cin>>n;
        cin>>s>>t;
        tot=0;
        for (int i=0;i<n;i++) if (s[i]!=t[i]) a[tot++]=i;
        if (tot>=3||tot==1) printf("No\n");
        else if(tot==0) printf("Yes\n");
        else {
            if (s[a[0]]==s[a[1]] && t[a[0]]==t[a[1]]) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}