#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define mm 1000000007
#define ll long long
ll n,m,t,a,b,c,an,ans,aa[200005],bb[200005],gg;
char s[200005],ss[200005],g;
priority_queue<int> q;
int find(int x){
	return aa[x]==x?x:aa[x]=find(aa[x]);
}
int main(){
	scanf("%I64d",&n);
	if (n<=10){
	for (int i=1;i<=n;i++) aa[i] = i;
	for (int i=1;i<=n;i++){
		for (int j=i+2;j<=n;j++){
			if (n%(j-i) == 0){
				aa[find(aa[j])]=find(aa[i]);
			}
		}
	}
	for (int i=1;i<=n;i++){
		if (bb[find(aa[i])] == 0){
			ans ++;
			bb[find(aa[i])] = 1;
		}
	}
	}else{
		ans = n;
		for (ll i=2;i*i<=n;i++){
			if (n%i == 0 && ans == n){
				ans = i;
				if ((n/i)%i != 0){
					ans = 1;
					break;
				}
			}else if (n%i==0){
				if (i%ans == 0 && (n/i)%i == 0) continue;
				else {
					ans = 1;
					break;
				}
			}
		}
	}
	printf("%I64d\n",ans);
	return 0;
}