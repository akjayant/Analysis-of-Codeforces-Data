#include <iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;

int mg[1004];

int main()
{
    int k,i,j,n,u,res,r,a,b;
    string s,t;

    cin>>k;

    while(k--)
    {
        cin>>n;
        cin>>s>>t;

      r=0;
      for(i=0;i<n;i++)
      {
          if(s[i]!=t[i]) r++;
      }

      if(r==1 || r>=3) cout<<"No"<<endl;
      else if(r==0) cout<<"Yes"<<endl;
      else
      {
          r=0;
          for(i=0;i<n;i++)
          {
            if(s[i]!=t[i] && r==0) {a=i; r++;}
            else if(s[i]!=t[i] && r==1) {b=i; r++;}
          }

          if(s[a]==s[b] && t[b]==t[a]) cout<<"Yes"<<endl;
          else cout<<"No"<<endl;
      }


    }

    return 0;
}
