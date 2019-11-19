#include<bits/stdc++.h>

signed main(void)
{
    int totCases;
    int a,b,c,d,k,pen,pencil;

    std::cin>>totCases;
    while(totCases--){
	std::cin>>a>>b>>c>>d>>k;
	pen = a/c+(a%c==0 ? 0 : 1); pencil = k-pen;
	if(pencil*d < b) puts("-1");
	else std::cout<<pen<<' '<<pencil<<std::endl;
    }
    
    return 0;
}
