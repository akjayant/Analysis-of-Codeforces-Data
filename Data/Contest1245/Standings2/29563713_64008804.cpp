#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ara[100005],mod=(1e9)+7;

char ch[100005];

int main()
{
    ll n,m,i,j,k,a,b,c,x,y,z;
    ara[0]=1;
    ara[1]=1;
    for(i=2;i<=1e5;i++)
    {
        ara[i]=(ara[i-1]+ara[i-2])%mod;
    }
    scanf("%s", ch);
    x=0,y=0;
    z=1;
    for(i=0;ch[i]!='\0';i++)
    {
        if(ch[i]=='m'||ch[i]=='w')
        {
            z=0;
            break;
        }
        if(ch[i]=='u')
        {
            if(x==1)
            {
                y++;
            }
            else{
                if(y>0)
                {
                    z*=ara[y];
                    z%=mod;
                    y=0;
                }
                x=1;
                y=1;
            }
        }
        else if(ch[i]=='n')
        {
            if(x==2)
            {
                y++;
            }
            else{
                if(y>0)
                {
                    z*=ara[y];
                    z%=mod;
                    y=0;
                }
                x=2;
                y=1;
            }
        }
        else
        {
            if(y>0)
            {
                z*=ara[y];
                z%=mod;
                y=0;
            }
        }
    }
    if(y>0)
    {
        z*=ara[y];
        z%=mod;
        y=0;
    }
    cout<<z%mod<<endl;
}
