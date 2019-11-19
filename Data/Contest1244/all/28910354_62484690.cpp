#include<bits/stdc++.h>

constexpr auto MAXN = 100000+50;

long long cost[3][MAXN];

int order[3];
std::vector<int> G[MAXN];

long long Calc(const int& nowAt, const int& fa=-1, const int currentOrd=0){
    for(const auto& it : G[nowAt])
	if(it != fa) return cost[order[currentOrd]][nowAt] + Calc(it,nowAt,(currentOrd+1)%3);
    return cost[order[currentOrd]][nowAt];
}

int out[MAXN];
void OutPut(const int& nowAt,const int& fa=-1,const int currentOrd=0){
    out[nowAt] = order[currentOrd];
    for(const auto& it : G[nowAt])
	if(it != fa) OutPut(it,nowAt,(currentOrd+1)%3);
}

signed main(void)
{
    int totVertex,st;

    std::cin>>totVertex;
    for(int color=0;color<3;color++)
	std::for_each(cost[color],cost[color]+totVertex,[](auto& it){ std::cin>>it; });

    int fr,to;
    for(int i=1;i<totVertex;i++){
	std::cin>>fr>>to; --fr;--to;
	G[fr].push_back(to); G[to].push_back(fr);
    }

    for(int i=0;i<totVertex;i++){
	if(G[i].size() == 1) st = i;
	if(G[i].size() > 2){
	    puts("-1"); return 0;
	}
    }

    //std::cout<<st<<std::endl;
    long long min = INT64_MAX,ts,od[3];
    for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	    for(int k=0;k<3;k++)
		if(i!=j && i!=k && j!=k){
		    order[0] = i; order[1] = j; order[2] = k;
		    
		    ts = Calc(st);
		    if(ts < min){
			min = ts;
			for(int i=0;i<3;i++) od[i] = order[i];
		    }
		}
    for(int i=0;i<3;i++) order[i] = od[i];
    OutPut(st);

    std::cout<<min<<std::endl;
    std::for_each(out,out+totVertex,[](const auto& it){ std::cout<<it+1<<' '; });
    putchar('\n');
    
    return 0;
}
