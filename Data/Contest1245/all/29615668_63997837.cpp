#include <bits/stdc++.h>
int T;
main(){
	scanf("%d\n",&T);
	while(T--){
		int a,b;
    scanf("%d %d",&a,&b);
    if(std::__gcd(a,b)==1)
      puts("Finite");
    else
      puts("Infinite");
	}
	return 0;
}