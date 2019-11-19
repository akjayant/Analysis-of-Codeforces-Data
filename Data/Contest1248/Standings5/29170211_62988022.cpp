#include<bits/stdc++.h>
#define fr(i,a,b) for(register int i = a;i <= b;++i)
#define int long long
#define N 100010
using namespace std;

int a[N],b[N];

inline int read(){
	int x = 0,f = 1;char c = getchar();
	while(!isdigit(c)){if(c == '-')f = -1;c = getchar();}
	while(isdigit(c)){x = x * 10 + c - '0';c = getchar();}
	return f * x;
}

signed main(){
	int t = read();
	while(t--){
		int n = read(),cnt = 0,ans = 0;
		fr(i,1,n){
			a[i] = read();
			if(a[i] & 1)cnt++;
		}
		int m = read();
		fr(i,1,m){
			b[i] = read();
			if(b[i] & 1)ans += cnt;
			else ans += n - cnt;
		}
		cout<<ans<<endl;
	}
	return 0;
}
