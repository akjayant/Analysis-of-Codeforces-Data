#include <bits/stdc++.h>
using namespace std;


long long n,kq,t[100005],a,b;
int main()
{ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("fuck.inp","r",stdin);
    //freopen("fuck.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;++i) cin>>t[i];
    sort(t+1,t+n+1);
    for (int i=1;2*i<=n;++i) {a+=t[i];b+=t[n-i+1];}
    if (n%2) b+=t[n/2+1];
    cout<<a*a+b*b;

}
