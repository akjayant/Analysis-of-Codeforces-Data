#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=105;
ll a[10],t,n;
ll ans[maxn],s[maxn];
int main(){
	cin>>t;
	while(t--){
		memset(ans,0,sizeof(ans));
		memset(s,0,sizeof(s));
		memset(a,0,sizeof(a));
		string tp;
		cin>>n>>a[1]>>a[2]>>a[3];
		cin>>tp;
		for (int i=1;i<=n;i++){
			if (tp[i-1]=='R') s[i]=1;
			if (tp[i-1]=='P') s[i]=2;
			if (tp[i-1]=='S') s[i]=3;
		}
		ll cnt=0,up=(n+1)/2;
		for (int i=1;i<=n;i++){
			if (s[i]==1&&a[2]>=1){
				ans[i]=2;
				cnt++;
				a[2]--;
			}
			if (s[i]==2&&a[3]>=1){
				ans[i]=3;
				cnt++;
				a[3]--;
			}
			if (s[i]==3&&a[1]>=1){
				ans[i]=1;
				cnt++;
				a[1]--;
			}
		}
		if (cnt<up){
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		for (int i=1;i<=n;i++){
			if (ans[i]!=0) continue;
			for (int j=1;j<=3;j++){
				if (a[j]>=1){
					a[j]--;
					ans[i]=j;
					break;
				}
			}
		}
		//cout<<"P N  "<<n<<endl;
		for (int i=1;i<=n;i++){
			if (ans[i]==1) cout<<"R";
			else if (ans[i]==2) cout<<"P";
			else cout<<"S";
		}
		cout<<endl;
	}
}