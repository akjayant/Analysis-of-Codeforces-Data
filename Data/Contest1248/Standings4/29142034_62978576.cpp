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
signed main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
      senky_bansal
      IIIT_ALLAHABAD

      ll t;
      cin>>t;
      while(t--)
      {
          ll n;
          cin>>n;
          ll co_odd=0;
          ll co_eve=0;
          ll eve=0;
          ll odd=0;
          for(int i=0;i<n;i++)
          {
              ll p1;
              cin>>p1;
              if(p1%2==0) co_eve++;
              else co_odd++;
          }
          ll m;
          cin>>m;
          for(int i=0;i<m;i++)
          {
              ll p2;
              cin>>p2;
              if(p2%2==0) eve++;
              else odd++;
          }
          cout<<eve*co_eve+odd*co_odd<<endl;
      }
      
      
      
}








