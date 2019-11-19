#include<bits/stdc++.h>
using namespace std;
#define TRACE
#define M 1000000007
#define oo 1000000000000000007
#define F first
#define S second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pll;
#define pb push_back
#define M6 5000009
#define M5 500009
#define pi 3.14159265
#define epsilon 1e-6
 
ll n,m,A[M5];

int  main()
{
    ios_base::sync_with_stdio (0), cin.tie (0);
    //init();
 
    ll tc=1,t=0,i,j,k,a,b,c,d;
    cin>>tc;
    while(t++<tc){
        cin>>a>>b>>c>>d>>k;
        a = ceil(a*1.0/c);
        b = ceil(b*1.0/d);
        if(a+b<=k) {
            cout<<a<<" "<<b<<"\n";
        }
        else cout<<"-1\n";
    }
    return 0;
}

