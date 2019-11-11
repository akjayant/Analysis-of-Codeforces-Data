/*enjoy karo yaar*/

//CF,CC,AtC,SPOJ: hp1999
//HE: hemant269
//HR: hemant2132

#include<bits/stdc++.h>
using namespace std;

#define     int          long long int
#define     fast()       ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define     all(x)       x.begin(),x.end()
#define     mem(a,b)     memset(a,b,sizeof(a))
#define     gcd(a,b)     (__gcd((a),(b)))
#define     lcm(a,b)     (((a)*(b))/gcd((a),(b)))
#define     pb           push_back
#define     ins          insert
#define     F            first
#define     S            second

const int inf=1e18,M=1e9+7;
const int N=1;

void solve()
{
    int a,b;
    cin>>a>>b;

    int g=gcd(a,b);

    if(g==1)
        cout<<"Finite";
    else
        cout<<"Infinite";
}

int32_t main()
{
    fast();

    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
        cout<<"\n";
    }

    return 0;
}

