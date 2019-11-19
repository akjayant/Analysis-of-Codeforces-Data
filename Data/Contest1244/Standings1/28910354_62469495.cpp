#include<bits/stdc++.h>

bool ReadBool(void){
    char in;
    do in = getchar(); while(in!='0' && in!='1');
    return in=='1';
}

signed main(void)
{
    int totCases,totLen,lft,rgt;
    bool appear;
    
    std::cin>>totCases;
    while(totCases--){
	std::cin>>totLen;
	lft = INT_MAX; rgt = INT_MIN; appear = false;
	for(int i=0;i<totLen;i++){
	    if(ReadBool()){
		lft = std::min(lft, i);
		rgt = std::max(rgt, i);
		appear = true;
	    }
	}

	if(!appear) std::cout<<totLen<<std::endl;
	else std::cout<<std::max(rgt+1<<1, totLen-lft<<1)<<std::endl;
    }
    
    return 0;
}
