#include <bits/stdc++.h>
using namespace std;

int main() {
   
     long long n,i,j,sum=0,count=0,ans=0,y,mx=0,m,k;
      cin>>n;
      vector<long long >v;
      for(i=2;i<=sqrt(n);i++)
      {
          if(n%i==0)
         { v.push_back(i); v.push_back(n/i); count+=2;}
      }
      sort(v.begin(),v.end());
       if(count==0)
       cout<<n<<endl;
       else
       {
          ans=v[0];
          for(i=1;i<v.size();i++)
          {ans=__gcd(ans,v[i]);
           if(ans==1)
           break;
          }
           
           cout<<ans<<endl;
       }
	return 0;
}