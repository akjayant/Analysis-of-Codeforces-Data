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
int n;
int a[maxn];
int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in","r",stdin);
#endif
    IO;
    int T;
    cin>>T;
    while (T--) {
        cin>>n;
        for (int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+1+n,greater<int>());
        int i;
        for (i=1;i<=n&&a[i]>=i;i++);
        cout<<i-1<<endl;
    }
    return 0;
}