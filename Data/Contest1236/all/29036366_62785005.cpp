#include <bits/stdc++.h>
#include <map>
#define ll long long
#define MAXN 100010
#define MAXE 300010
#define MOD 1000000007
using namespace std;

int main()
{
   //freopen("testdata.in.txt","r",stdin);
   int T;
   cin>>T;
   for(int t=1;t<=T;t++){
    int a,b,c;
    cin>>a>>b>>c;
    int ans=0;
    while(b>=1&&c>=2){
        b--;
        c-=2;
        ans+=3;
    }
    while(a>=1&&b>=2){
     a--;
     b-=2;
     ans+=3;
    }
    cout<<ans<<endl;
   }


   return 0;
}

