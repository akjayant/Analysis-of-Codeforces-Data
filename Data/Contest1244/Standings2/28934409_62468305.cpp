#include <bits/stdc++.h>

using namespace std;
long long a,b,w;
char x;
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cin>>a;
   for(int i=0;i<a;i++)
   {
       cin>>b;
       w=b;
       for(long long int z=0;z<b;z++)
       {
           cin>>x;
           if(x=='1')
           {
                w=max(2*max(z+1,b-z),w);
           }
       }
       cout<<w<<"\n";
   }
    return 0;
}
