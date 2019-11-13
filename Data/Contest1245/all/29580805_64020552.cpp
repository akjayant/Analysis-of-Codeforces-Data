#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll fib[100009];
int main()
{
    ll a,b,c,d,e,i,j,k,l,n,m,x,y,t,p;
    fib[1]=1;
    fib[2]=2;
    m=1000000007;
    for(i=3;i<=100001;i++)
    {
        fib[i]=(fib[i-1]+fib[i-2])%m;
    }
    string st;
    cin>>st;
    n=st.size();
    x=1;
    char ch;
    for(i=0;i<n;i++)
    {
        if(st[i]=='w' || st[i]=='m')
        {
            printf("0\n");
            return 0;
        }
        else if(st[i]=='u' || st[i]=='n')
        {
            b=0;
            ch=st[i];
            while(ch==st[i] && i<n)
            {
                b++;
                i++;
            }
            i--;
            x=(x*fib[b])%m;
        }
    }
    printf("%lld\n",x);

}
