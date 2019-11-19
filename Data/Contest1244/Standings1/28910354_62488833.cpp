#include<bits/stdc++.h>

constexpr auto MAXN = (int)1e5+50;

long long val[MAXN];

signed main(void)
{
    long long totNums; long long totOptns;
    
    std::cin>>totNums>>totOptns;
    std::for_each(val,val+totNums,[](auto& it){ std::cin>>it; });
    std::sort(val,val+totNums);

    long long cntlft=1,cntrgt=1,gap;
    while(cntlft+cntrgt <= totNums){
	if(cntlft < cntrgt){
	    gap = val[cntlft] - val[cntlft-1];
	    if(totOptns/cntlft < gap){
		val[cntlft-1] += totOptns/cntlft;
		break;
	    }
	    totOptns -= gap*cntlft++;
	} else {
	    gap = val[totNums-cntrgt] - val[totNums-cntrgt-1];
	    if(totOptns/cntrgt < gap){
		val[totNums-cntrgt] -= totOptns/cntrgt;
		break;
	    }
	    totOptns -= gap*cntrgt++;
	}
    }

    std::cout<<val[totNums-cntrgt]-val[cntlft-1]<<std::endl;
    
    return 0;
}
