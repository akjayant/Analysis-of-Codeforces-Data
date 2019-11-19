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
const int N=55;
ll n;
ll b[N];
int main(){
	cin>>n;
	int cnt=0;
	for(ll i=2;i*i<=n;i++) {
		if(n%i==0) {
			while(n%i==0) n/=i;
			b[++cnt]=i;
		}
	}
	if(n>1) b[++cnt]=n;
	if(cnt==1) cout<<b[1];
	else cout<<1;
	return 0;
}