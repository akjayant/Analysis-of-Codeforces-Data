#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first 
#define Y second
const int inf=0x3f3f3f3f;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
const int N=1005;
int n;
int a[N];
int main(){
	int T=read();
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		int ans=0;
		for(int i=n;i>=1;i--) {
			ans=max(ans,min(a[i],n-i+1));
		}
		cout<<ans<<endl;
	}
	return 0;
}