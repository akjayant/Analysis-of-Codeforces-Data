#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define _IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll N=1e5+9,inf=1e18,mod=1e9+7;

int main()
{
    _IO;
  int t;
  cin>>t;
  while(t--)
  {
      int a,b,c,d,k;
      cin>>a>>b>>c>>d>>k;
      int x=(a+c-1)/c;
      int y=k-x;
      if(y*d>=b)cout<<x<<" "<<y<<"\n";
      else cout<<-1<<"\n";
  }


}
