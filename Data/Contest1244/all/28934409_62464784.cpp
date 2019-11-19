#include <bits/stdc++.h>

using namespace std;
long long a,b,c,d,e,x,w,w1;
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cin>>x;
   for(int i=0;i<x;i++)
   {
        cin>>a>>b>>c>>d>>e;
        w=a/c;
        if(a%c!=0)
        {
            w++;
        }
        w1=b/d;
        if(b%d!=0)
        {
            w1++;
        }
        if(w+w1>e)
        {
            cout<<"-1\n";
        }else
        {

            cout<<w<<" "<<w1<<"\n";
        }
   }
    return 0;
}
