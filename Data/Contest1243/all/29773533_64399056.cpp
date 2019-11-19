#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main()
{
    int t=1;
    //cin>>t;
    while(t--){
      int N;
      cin>>N;
      int gcd = 0;
      int sqrtN = sqrt(N);
      for(int num=1;num<=sqrtN;num++)
      {
          if(N%num==0)
          {
              int bnum = N/num;
              if(num!=1)
              gcd = __gcd(gcd,num);
              gcd = __gcd(gcd,bnum);
          }
      }
      cout<<gcd<<endl;
      }
    }