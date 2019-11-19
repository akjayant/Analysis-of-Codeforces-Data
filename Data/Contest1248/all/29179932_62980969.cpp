#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
long long p,q;
int main(){
	int t ;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d",&n);
		long long oushu=0,jishu=0;
	    for(int i=0;i<n;i++){
	    	scanf("%lld",&p);
	    	if(p%2==0) oushu++;
	    	else jishu++;
	    }
	    long long oushu2=0,jishu2=0;
	    scanf("%d",&m);
	    for(int i=0;i<m;i++){
	    	scanf("%lld",&q);
			if(q%2==0) oushu2++;
	    	else jishu2++;	
	    }
	    cout<<jishu*jishu2+oushu*oushu2<<endl;
	    
	} 
	return 0;
}
