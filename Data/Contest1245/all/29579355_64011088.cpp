#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifdef _DEBUG
    const int N=1e3+10;
#else
    const int N=1e6+10;
#endif
int m,n,t;
int gcd(int x,int y){return !y?x:gcd(y,x%y);}
int main()
{
    // freopen("data.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        if(gcd(m,n)==1)puts("Finite");
        else puts("Infinite");
    }
}