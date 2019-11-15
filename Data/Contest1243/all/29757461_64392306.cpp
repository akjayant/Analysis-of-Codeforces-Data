#include <iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;

int mg[1004],rrr[1004][3];

int main()
{
    int k,i,j,n,u,res,r,a,b,f;
    string s,t;
    char c;

    cin>>k;

    while(k--)
    {
        cin>>n;
        cin>>s>>t;

      r=0;  res=0;
      for(i=0;i<n;i++)
      {
          if(s[i]!=t[i])
          {
              f=0;
              for(j=i+1;j<n;j++)
              {
                  if(s[j]==s[i])
                    {r++;  rrr[r][1]=j; rrr[r][2]=i;   c=s[j]; s[j]=t[i]; t[i]=c;  f=1; break;}


                  else if(t[j]==s[i]) {r++;  rrr[r][1]=j; rrr[r][2]=j;  c=s[j]; s[j]=t[j]; t[j]=c;
                  r++;  rrr[r][1]=j; rrr[r][2]=i; f=1; c=s[j]; s[j]=t[i]; t[i]=c; break;}
              }

              if(f==0) res=1;

          }
      }

      if(res==1) cout<<"No"<<endl;
      else
      {
          cout<<"Yes"<<endl;
          cout<<r<<endl;
          for(i=1;i<=r;i++)
          {
            cout<<rrr[i][1]+1<<" "<<rrr[i][2]+1<<endl;
          }
      }
    }

    return 0;
}
