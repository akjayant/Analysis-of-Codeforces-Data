#include <bits/stdc++.h>
int T;
int len;
int a,b,c;
int d,e,f;
char s[1000001];
char ans[1000001];
main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d %d",&len,&a,&b,&c);
	  scanf("%s",s+1);
	  d=e=f=0;
	  for(int i=1;i<=len;++i){
	  	if(s[i]=='R')
	  	  ++d;
	  	if(s[i]=='P')
	  	 ++e;
	  	if(s[i]=='S')
	  	  ++f;
	  }
	  int max=std::min(a,f)+std::min(b,d)+std::min(c,e);
	  if(max>=(len+1)/2){
	  	puts("YES");
	  	for(int i=1;i<=len;++i){
	  	  if(s[i]=='R')
	  	    if(b)
	  	      --b,ans[i]='P';
	  	    else
	  	      ans[i]='K';
	  	  if(s[i]=='P')
	  	    if(c)
	  	      --c,ans[i]='S';
	  	    else
	  	      ans[i]='K';
	  	  if(s[i]=='S')
	  	    if(a)
	  	      --a,ans[i]='R';
	  	    else
	  	      ans[i]='K';
	  	}
	  	for(int i=1;i<=len;++i)
	  	  if(ans[i]!='K')
	  	    std::cout<<ans[i];
	  	  else{
	  	  	if(a)
	  	  	  --a,std::cout<<'R';
	  	    else 
					  if(b)
	  	        --b,std::cout<<'P';
	  	    else
	  	      if(c)
	  	        --c,std::cout<<'S';
	  	  }
	  	puts("");
		}
	  else
	    puts("NO");
	}
	return 0;
}