#include <bits/stdc++.h>
#define rest 1000000007
using namespace std;
int a,b,c,i,n,nr,k,val;

unsigned long long put (unsigned long long a,unsigned long long b)
{
   unsigned long long x;
    if(b==0)
        return 1;
        else
            if(b==1)
            return a%rest;
    if(b%2==0)
      x=put(a*a%rest,b/2);
      else
        x=a*put(a*a%rest,(b-1)/2)%rest;
    return x;

}
int main()
{
   cin>>n;
   cin>>k;
   val=put(2,k)-1;
   if(val<0)
      val+=rest;
   cout<<put(val,n);

}
