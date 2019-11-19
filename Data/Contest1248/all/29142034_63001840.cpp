 #include<bits/stdc++.h>
#define mod 1000000007
#define fr first
#define se second
#define ll long long
#define PI 3.1415926535 
#define pb push_back
#define mpr make_pair
#define INF 1000000009
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define senky_bansal ios_base::sync_with_stdio(false);
#define IIIT_ALLAHABAD    cin.tie(NULL);cout.tie(NULL);
using namespace std;
ll p[100005];
void pre()
{
    p[0]=0;
    p[1]=2;
    p[2]=4;
    for(int i=3;i<100005;i++)
    p[i]=(p[i-1]+p[i-2])%mod;
}
signed main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
      senky_bansal
      IIIT_ALLAHABAD


      pre();
      ll n,m;
      cin>>n>>m;
      if(n==1 || m==1)
      {
          ll p2 = max(n,m);
          cout<<p[p2]<<endl;
          return 0;
      }
      else
      {
          cout<<(p[n]+p[m]-2)%mod<<endl;
      }
      
}








