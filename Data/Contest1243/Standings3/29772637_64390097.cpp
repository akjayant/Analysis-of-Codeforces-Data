#include <stdio.h>
int main()
{
    long long int N,n;
    scanf("%I64d",&N);

    n=N;
    long long int i,prime[10005];
    int w=0;
    for(i=2;i*i<=N;i++)
    {
        if(n%i==0)
        {
            while(n%i==0)n/=i;

            w=1;
            if(n==1)printf("%I64d",i);
            else printf("1");
            break;
        }
    }


    if(w==0) printf("%I64d",N);
    return 0;
}