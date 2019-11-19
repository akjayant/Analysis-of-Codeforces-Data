#include<bits/stdc++.h>
using namespace std;
#define int long long
#define si signed
#define sc(x) scanf("%I64d",&x);
#define rd(A) for(int i=1;i<=n;i++)scanf("%I64d",&A[i]);
#define pb push_back
#define se second
#define fi first
#define P pair<int,int>
#define endl '\n'
#define forn(i,n) for(int i=1;i<=n;i++)
struct Nod{
  int a,b,i;
};
#define maxn 10000+10
#define debug cout<<"No Pro"<<'\n';
int A[maxn];
int B[maxn];
si main()
{
    int t,n,m;
    sc(t);
    while(t--){
        sc(n);
        int a,b,c,d,x,y;
        a=b=c=d=0;
        forn(i,n){sc(x);if(x&1)a++;else b++;}
        sc(m);
        forn(i,m){sc(y);if(y&1)c++;else d++;}
        cout<<a*c+b*d<<'\n';
    }

}

