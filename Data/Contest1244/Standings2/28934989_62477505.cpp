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
    	n=read();k=read();		
    	for(register int i=1;i<=n;i++)a[i]=read();
    	sort(a+1,a+n+1);
    	int l=1,r=n,ans;
    	while(a[l]==a[l+1])l++;
    	while(a[r]==a[r-1])r--;
    	while(l<r && k){
    		if(l<n-r+1){
    			int d=a[l+1]-a[l];
				if(k>=d*l){
					k-=d*l;
    				l++;
					while(a[l]==a[l+1] && l<r)l++;
				}
				else {
					a[l]+=k/l;
					break;
    			}
			}				
    		else {
				int d=a[r]-a[r-1];
				if(k>=d*(n-r+1)){
					k-=d*(n-r+1);
					r--;
    				while(a[r]==a[r-1] && l<r)r--;
				}
				else {
					a[r]-=k/(n-r+1);
					break;
    			}
			}
    	}
		printf("%lld\n",a[r]-a[l]);
    	return 0;
    }