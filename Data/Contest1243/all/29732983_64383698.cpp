#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll cnt[30];
int main()
{
    ll a,b,c,d,e,i,j,k,l,n,m,x,y,t,p;
    string st,st2;
    scanf("%lld",&t);
    for(p=1;p<=t;p++)
    {
        scanf("%lld",&n);
        cin>>st>>st2;
        char ch,ch2;
        x=0;
        c=0;
        for(i=0;i<n;i++)
        {
            if(st[i]!=st2[i])
            {
                x++;
                if(x==1)
                {
                    ch=st[i];
                    ch2=st2[i];
                }
                if(x==2)
                {
                    if(ch==st[i] && ch2==st2[i])
                    {
                        c=1;
                    }
                }
            }
        }
        if(x==0 || (x==2 && c==1))
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}
