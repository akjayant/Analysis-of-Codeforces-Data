#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define PB push_back
#define P push
#define mem(x,y) memset(x,y,sizeof(x))
LL const mod= 1e9+7;

LL bigmod(LL b,LL c)
{
    LL ans=1;
    while(c)
    {
        if(c%2) ans*=b;
        c/=2;
        b*=b;

        ans%=mod;
        b%=mod;
    }
    return ans;
}

int main()
{

      LL i,j,k,s,d,r,m,n;

      cin>>n>>m;

      s=bigmod(2,m);
      s--;
      s=bigmod(s,n);

      cout<<s<<endl;

}

