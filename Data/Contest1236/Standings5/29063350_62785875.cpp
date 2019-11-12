#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define PB push_back
#define P push
#define mem(x,y) memset(x,y,sizeof(x))

int main()
{
  LL a,b,c,d,e,i,j,k,test,tc,s;

  cin>>test;
  for(tc=1;tc<=test;tc++)
  {
      cin>>a>>b>>c;

      s=0;
      d=c/2;
      s+=(min(d,b)*3);
      b-=min(d,b);
      d=b/2;
      s+=(min(d,a)*3);
      cout<<s<<endl;
  }

}
