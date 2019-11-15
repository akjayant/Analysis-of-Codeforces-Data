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

int main()
{
    int n;
    cin>>n;
    int a[n][n];
    int t = 1;
    for (int i = 0;i<n;i++)
        for (int j = 0;j<n;j++)
        {
            if (i&1)
            {
                a[i][j] = t;
                t++;
            }
            else
            {
                a[i][n-j-1] = t;
                t++;
            }
        }
    for (int i = 0;i<n;i++)
    {
        for (int j = 0;j<n;j++)
            cout<<a[j][i]<<" ";
        cout<<endl;
    }
    return 0;
}
