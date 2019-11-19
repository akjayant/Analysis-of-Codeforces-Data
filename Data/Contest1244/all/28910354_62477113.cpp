#include<bits/stdc++.h>

signed main(void)
{
    long long totGames,totPoints,win,draw,w,d,l,origPt,origGame;

    std::cin>>totGames>>totPoints>>win>>draw;
    origPt = totPoints; origGame = totGames;

    long long lcm = win*draw/std::__gcd(win,draw),lcms;
    lcms = std::max(0LL, totPoints/lcm-1);
    totGames -= (lcm/win)*lcms;
    if(totPoints >= lcm) (totPoints %= lcm) += lcm;

    for(long long i=0;i*win<=totPoints;i++)
	if((totPoints-i*win)%draw==0 && (totPoints-i*win)/draw<=totGames){
	    w = lcms*(lcm/win)+i; d = (totPoints-i*win)/draw; l = origGame-w-d;
	    if(w*win + d*draw != origPt) continue;
	    if(w<0 || d<0 || l<0 || w>origGame || d>origGame || l>origGame) continue;
	    std::cout<<w<<' '<<d<<' '<<l<<std::endl;
	    return 0;
	}
    puts("-1");
    
    return 0;
}
