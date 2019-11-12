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

///scanf("%d %d",&n,&m);
///printf("%d %d",n,m);
///printf("-1 -1");


/** /////////// ** Code ** /////////// **/

const int N = 1e5+5;
int a,b,c;
ll memo [200][200][200];
ll dp (int x,int y,int z)
{
    //if (x<1 && y <2) return 0;
    //if (y<1 && z <2) return 0;

    ll &ret = memo[x][y][z];
    if (ret != -1) return ret;

    ll path1 = 0,path2 = 0;
    if (x>0 && y>1) path1 = 3 + dp (x-1,y-2,z);
    if (y>0 && z>1) path2 = 3 + dp (x,y-1,z-2);

    return ret = max(path1,path2);

}
int main()
{
    memset(memo,-1,sizeof memo);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        cout<<dp(a,b,c)<<endl;
    }
    return 0;
}
