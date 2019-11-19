#include<bits/stdc++.h>

signed main(void)
{
    long long totCases,n,m,val,cnt[2],tot;

    std::cin>>totCases;
    while(totCases--){
        std::cin>>n;
        cnt[0] = cnt[1] = 0;
        tot = 0;
        while(n--){
            std::cin>>val;
            cnt[val&1]++;
        }
        std::cin>>m;
        while(m--){
            std::cin>>val;
            tot += cnt[val&1];
        }
        std::cout<<tot<<std::endl;
    }

    return 0;
}
