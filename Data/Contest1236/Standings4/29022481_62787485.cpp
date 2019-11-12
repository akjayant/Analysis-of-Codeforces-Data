#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e5+5;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int a,b,c,ans=0;
		scanf("%d %d %d",&a,&b,&c);	
		
		int t1,t2;
		
		t1=min(b,c/2);
		t2=min(a,(b-t1)/2);
		ans=t1*3+t2*3;
		
		t1=min(a,b/2);
		t2=min(b-2*t1,c/2);
		ans=max(ans,t1*3+t2*3);
		
		printf("%d\n",ans);	
	}
    return 0;
}
