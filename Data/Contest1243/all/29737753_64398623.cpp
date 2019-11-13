#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
main()
{
    int q;
    scanf("%d",&q);
    while(q--){
    int n,i,j,cnt=0,a,b,t1=0;
    scanf("%d",&n);
    char s[n+1],t[n+1];
    scanf("%s",s);
    scanf("%s",t);
    map<char,int>mp;
    for(i=0;i<n;i++)
    {
       mp[s[i]]++;
       mp[t[i]]++;
    }
    for(i=0;i<n;i++)
    {
       if(mp[s[i]]%2==1)
       {
          t1=1;
          break;
       }
       if(mp[t[i]]%2==1)
       {
          t1=1;
          break;
       }
    }
    if(t1==1)
    {
        printf("NO\n");
        continue;
    }
    int ans1[100000],ans2[100000],ind=0;
    for(i=0;i<n;i++)
    {
        if(s[i]==t[i])
        {
            continue;
        }
        char c=s[i];
        int temp=-1;
        for(j=i+1;j<n;j++)
        {
            if(s[j]==s[i])
            {
               temp=j;
               break;
            }
        }
        if(temp!=-1)
        {
            ans1[ind]=j+1;
            ans2[ind]=i+1;
            ind++;
            char ch=s[j];
            s[j]=t[i];
            t[i]=ch;
            continue;
        }
        temp=-1;
        for(j=i+1;j<n;j++)
        {
            if(t[j]==s[i])
            {
               temp=j;
               break;
            }
        }
        if(temp!=-1)
        {
          ans1[ind]=j+1;
          ans2[ind]=j+1;
          ind++;
          char ch=s[j];
          s[j]=t[j];
          t[j]=ch;
          ans1[ind]=j+1;
          ans2[ind]=i+1;
          ind++;
          ch=s[j];
          s[j]=t[i];
          t[i]=ch;
        }
    }
    printf("YES\n");
    printf("%d\n",ind);
    for(i=0;i<ind;i++)
    {
        printf("%d %d\n",ans1[i],ans2[i]);
    }
    //printf("\n");
    }
}
