#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf=1e18,mod=1e9+7,maxn=4e5+100;

int n,m,l,r,x,y,q,ans,res;

string s,t;

int a,b,c;

main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        ans=0;
        cin >> a >> b >> c;
        while(c>=2&&b>=1){ans+=3;c-=2;b--;}
        while(b>=2&&a>=1){ans+=3;b-=2;a--;}
        cout << ans << "\n";
    }



}
