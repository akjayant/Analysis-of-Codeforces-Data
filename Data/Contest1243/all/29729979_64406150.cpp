#include<bits/stdc++.h>
using namespace std;
long long n,cnt,divi[2000010];
int main()
{
    scanf("%lld",&n);
    long long t=n;
    while(n>1)
    {
        int kk=0;
        for(long long i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                n/=i;
                if(cnt==0||i!=divi[cnt-1])
                {
                    divi[cnt++]=i;
                }
                kk=1;
                break;
            }
        }
        if(kk==0)
        {
            if((cnt==0||n!=divi[cnt-1])&&n!=t)
            {
                divi[cnt++]=n;
            }
            break;
        }
    }
    if(cnt==1)
    {
        printf("%lld",divi[0]);
    }
    else if(cnt>1)
    {
        printf("1");
    }
    else
    {
        printf("%lld",t);
    }
}