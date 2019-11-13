#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#define INF 0x3f3f3f3f
#define ll long long
#define mod 998244353
#define maxx 100005
using namespace std;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int g=gcd(x,y);
        if(g==1)cout<<"Finite"<<endl;
        else cout<<"Infinite"<<endl;
    }
    return 0;
}