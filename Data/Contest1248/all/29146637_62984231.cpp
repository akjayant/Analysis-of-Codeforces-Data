#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))

constexpr auto MAXN = 100050;

long long val[MAXN];

signed main(void)
{
    int totNums;

    std::cin>>totNums;
    for(int i=0;i<totNums;i++) std::cin>>val[i];
    std::sort(val,val+totNums,[](const int& a,const int& comp){ return a>comp; });

    long long a=0,b=0;
    int fr=0,bk=totNums-1;
    while(fr<=bk){
        a += val[fr++];
        if(fr<=bk) b += val[bk--];
    }

    std::cout<<sqr(a)+sqr(b)<<std::endl;

    return 0;
}
