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
#define maxn 100000+10
#define debug cout<<"No Pro"<<'\n';
int A[maxn];
si main()
{
    int n;
    sc(n);
    forn(i,n){
        sc(A[i]);
    }
    sort(A+1,A+n+1);
    int id=n/2;
    int a=0,b=0;
    for(int i=1;i<=id;i++){
        a+=A[i];
    }
    for(int i=id+1;i<=n;i++){
        b+=A[i];
    }
    cout<<(a*a+b*b)<<'\n';
}

