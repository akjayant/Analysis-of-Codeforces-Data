#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ii pair < int , int >
#define LS pair < ll , string >

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long double ldbl;
typedef long long ll;
typedef double dbl;

const ldbl E = 2.71828182845904523536;
const ldbl pi = 3.141592653589793238462643383279502884197;
const dbl eps = 1e-9;
const ll mod = 1e9+7;
const ll inf = 1LL<<30;

long long POW_M(long long a,long long p,long long m)
{
    if(p == 0) return 1;
    if(p == 1) return a%m;
    long long x=POW_M(a,p/2,m);
    if( p%2 == 0) return ((x%m)*x)%m;
    return (((x%m) *x%m)*a)%m;
}

///scanf("%d %d",&n,&m);
///printf("%d %d",n,m);
///printf("-1 -1");


/** /////////// ** Code ** /////////// **/

const int N = 1e5+5;
ll n,m;
int main()
{
    cin>>n>>m;
    cout<<POW_M(POW_M(2,m,mod)-1+mod,n,mod)<<endl;
    return 0;
}
