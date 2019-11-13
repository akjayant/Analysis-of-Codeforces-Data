#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<set>
#include<climits>
#include<utility>
using namespace std;
# define pb push_back
# define mp make_pair
# define PI 3.1415926535
# define eps 1e-9
# define p 1000000007
long long power(long long x, long long y)
{
    long long res = 1;

    x = x % p;

    while (y > 0)
    {

        if (y & 1)
            res = (res*x) % p;

        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n,m;
    cin>>n>>m;
    long long ans=power(2,m);
    ans--;
    ans=power(ans,n);
    cout<<ans%p<<endl;






    return 0;
}