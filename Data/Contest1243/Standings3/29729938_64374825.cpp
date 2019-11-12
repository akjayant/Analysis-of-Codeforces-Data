#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+50;
const int INF = 1e9;
int a[maxn];
int cmp(int x,int y){
	return x>y;
}
int main(){
	int t;scanf("%d",&t);
	while(t--){int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1,cmp);
		int ans=1;
		for(int i=2;i<=n;i++){
			if(a[i]>ans){
				ans++;
			}else{
				break;
			}
		}
		printf("%d\n",ans);
	}
}