#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mp make_pair
#define pb push_back
#define mod 1000000007
main()
{
  int n;
  cin>>n;
  int ans=0,gcd=n;
  for(int i=2;i*i<=n;i++){
    if(n%i==0){
      gcd=__gcd(gcd,i);
      gcd=__gcd(gcd,n/i);
    }
  }
  cout<<gcd<<endl;
}
