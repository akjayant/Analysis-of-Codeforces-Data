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

      ll n;
      cin>>n;
      ll a[n];
      for(int i=0;i<n;i++)
      cin>>a[i];
      sort(a,a+n);
      ll sum1=0;
      ll sum2=0;
      for(int i=0;i<n/2;i++) sum1+=a[i];
      for(int i=n/2;i<n;i++) sum2+=a[i];
      cout<<sum1*sum1+sum2*sum2<<endl;
      
      
}








