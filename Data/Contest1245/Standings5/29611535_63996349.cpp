#include <bits/stdc++.h>

using namespace std;
#define INF 1000000000
#define DIM 100007
#define pll pair<long long, long long>
#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define mood 1000000007
#define y1 ghjhklkhkyj
#define pi 3.14159265358979323846
typedef  pair< long long, pair<long long, long long> > ppll;

long long  n,m,l,r,h,k,res1,a1,a2,w,a3,z,alln,a4,a5,a6,a7,a8,a9,a10,last,LL,timer,start,finish,flag,step,tests,kilk,curr,shift;
string s,s1,s2;
char t;
ll x,y;




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>tests;
    while(tests--){
        cin>>a1>>a2;
        a3=__gcd(a1,a2);
        if(a3==1)cout<<"Finite"<<endl;
        else cout<<"Infinite"<<endl;
    }


    return 0;
}
