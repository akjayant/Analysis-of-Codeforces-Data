#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

#define Fi first
#define Se second
#define ll long long
#define inf 0x3f3f3f3f
#define lowbit(x) (x&-x)
#define ull unsigned long long
#define mmin(a,b,c) min(a,min(b,c))
#define mmax(a,b,c) max(a,max(b,c))
#define debug(a) cout<<#a<<"="<<a<<endl;
#define debug2(a,b) cout<<#a<<"="<<a<<" "<<#b<<"="<<b<<endl;
#define debug3(a,b,c) cout<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<endl;
#define show_time cout<<"The run time is:"<<(double)clock()/CLOCKS_PER_SEC<<"s"<<endl;
using namespace std;
const int N=3e5+10;

int main()
{
    int T;cin>>T;
    while(T--)
    {
        ll a,b;cin>>a>>b;
        ll gcd=__gcd(a,b);
        if(gcd==1)
        {
            cout<<"Finite\n";
        }
        else
        {
            cout<<"Infinite\n";
        }
    }
    return 0;
}
/*

*/
