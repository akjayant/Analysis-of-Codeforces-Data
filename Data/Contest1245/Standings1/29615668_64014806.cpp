#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
int f[1000001];
int ans=1;
char s[1000001];
main(){
	f[0]=f[1]=1;
  f[2]=2;
  for(int i=3;i<=100000;++i)
    f[i]=(2*f[i-2]%mod+f[i-3])%mod;
  scanf("%s",s+1);
  int len=strlen(s+1);
  for(int i=1,nxt;i<=len;i=nxt){
    nxt=i+1;
    if(s[i]=='u'||s[i]=='n'){
    	while(nxt<=len&&s[nxt]==s[i])
    	  ++nxt;
    	ans=(ans*f[nxt-i])%mod;
    }
    if(s[i]=='m'||s[i]=='w'){
      puts("0");
      return 0;
    }
  }
  printf("%lld",ans);
	return 0;
}