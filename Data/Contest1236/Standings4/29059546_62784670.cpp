#include <iostream>

using namespace std;

int main()
{
   int n,i,a,b,c;
   cin>>n;
   for(i=1;i<=n;i++)
   {
       cin>>a>>b>>c;
       int sol=0;
       sol=min(c/2,b);
       sol+=min((b-sol)/2,a);
       cout<<sol*3<<'\n';
   }
    return 0;
}
