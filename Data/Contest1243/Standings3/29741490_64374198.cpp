#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e5+5;
int n,a[1005];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		int ans=-1;
		for(int i=n;i>=1;i--){
			if(a[i]<(n-i+1)){
				ans=n-i;
				break;
			}
		}
		if(ans==-1)ans=n;
		printf("%d\n",ans);
	}
    return 0;
}
