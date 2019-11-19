#include<bits/stdc++.h>
#define int long long
using namespace std; const int maxn = 1e5+10;
typedef long long ll;
int s[maxn];
main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    sort(s+1,s+1+n);
    int d=0,r=0;
//    int t;
//    if(n%2==0) t=n/2+1;else t=n/2+1;
    for(int i=n/2+1;i<=n;i++){
        r+=s[i];
    }
    for(int i=1;i<=n/2;i++){
        d+=s[i];
    }
    cout<<d*d+r*r<<endl;
    return 0;
}
