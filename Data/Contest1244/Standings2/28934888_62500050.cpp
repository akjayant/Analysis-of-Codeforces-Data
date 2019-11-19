#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[200005],b[200005],s[200005],cnt[200005];
void Siyuan() {/*Siyuan Ak ioi*/return ;}
signed main(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++)cin >> a[i];
	sort(a+1,a+1+n);
	for(int i = 1; i <= n; i++) b[i]=a[i];
	int m=unique(b+1,b+1+n)-b-1;
	for(int i = 1; i <= n; i++)cnt[lower_bound(b+1,b+1+m,a[i])-b]++;
	int Min=1,Max=m,ans=0,tmp=0;
	ans = tmp = 0;
	while(1 + 1 == 2){
		if(Min>=Max)break; 
		if(cnt[Min]<cnt[Max]){
			if((b[Min+1]-b[Min])*cnt[Min]<=k){k-=(b[Min+1]-b[Min])*cnt[Min];}
			else{tmp=k/cnt[Min];break;}
			cnt[Min+1]+=cnt[Min];
			Min = Min + 1;
		}
		else if(cnt[Min] >= cnt[Max]){
			if(cnt[Max]*(b[Max]-b[Max-1])<=k){k-=(b[Max]-b[Max-1])*cnt[Max];}
			else{tmp=k/cnt[Max];break;}
			cnt[Max-1]+=cnt[Max];
			Max = Max - 1;
		}
	}
	ans=b[Max]-b[Min]-tmp;
	cout << ans << endl;
	return 0;
}