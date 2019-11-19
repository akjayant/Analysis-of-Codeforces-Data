    #include<iostream>
    #include<cstdio>
    #include<cstring>
    #include<cmath>
    #include<algorithm>
    #include<queue>
    #include<stack>
    #include<vector>
    #include<map>
    #define int long long
    using namespace std;
    const int maxn =1e5+10;
     
    int read(){
    	int x=0,f=1;
    	char c=getchar();
    	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    	while(isdigit(c)){x=(x<<3)+(x<<1)+c-48;c=getchar();}
    	return x*f;
    }
     
    int k,m,n,t;
    int a[maxn];
    signed main(){
    	t=read();
    	
    	while(t--){
    		int a=read(),b=read(),c=read(),d=read();k=read();
    		int x=(a-1)/c+1;
    		m=k;
    		k-=x;
    		if((b-1)/d+1>k)puts("-1");
    		else printf("%lld %lld\n",x,m-x);
    	}
    	/*n=read();k=read();		
    	for(register int i=1;i<=n;i++)a[i]=read();
    	sort(a+1,a+n+1);
    	int l=1,r=n,ans;
    	while(a[l]==a[l+1])l++;
    	while(a[r]==a[r-1])r--;
    	while(l<=r){
    		int min_=min(l,)
    		if(l<=n-r+1){
    			a[l]++;
    			
    		}				
    	}*/
    	return 0;
    }