#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define fast ios_base::sync_with_stdio(false)
#define vi vector<int>
#define pi pair<int,int>
#define s second 
#define f first

const int M=1e9+7;
const int MXN=1e5+10;

inline int add(int a, int b) { int ret=((int)a+b)%M; if(ret<0) ret+=M; return ret; }
inline int mul(int a, int b) { int ret=((int)a*b)%M; if(ret<0) ret+=M; return ret; }
template<typename... Args>
inline int add(int a, Args... args) { return add(a, add(args...)); }
template<typename... Args>
inline int mul(int a, Args... args) { return mul(a, mul(args...)); }


int n,k,t,m;
int a[MXN];

int mul1(int a,int b){
	int res=0;
	a%=M;b%=M;
	while(b){
		if(b&1)res=(res+a)%M;
		(a+=a)%=M;
		b>>=1;
	}
	return res;
}

int power(int a,int b){
	int res=1;
	a%=M;b%=(M-1);

	while(b){
		if(b&1)res=(res*a)%M;
		a=(a*a)%M;
		b>>=1;
	}
	return res;
}

int num(vi a,int ind){
	int res=0;
	for(int i=a.size()-1;i>=0;--i){
		if(i==ind)continue;
		res *= 10;
		res += a[i];
	}
	return res;
}
int dp[MXN];
int dp2[MXN];

int32_t main(){
	fast;
	cin>>n>>m;
	dp[0]=dp[1]=1;
	for(int i=2;i<=1e5+1;++i){
		dp[i] = (dp[i-1]+dp[i-2])%M;
	}
	dp2[1] = dp[n];
	dp2[0] =1; 
	for(int i=2;i<=m;++i){
		dp2[i] = (dp2[i-1]+dp[i-2])%M;
	}
	// for(int i=1;i<=3;++i)
	// 	cout << dp2[i] << ' ';
	cout << 2*dp2[m]%M << endl;
	return 0;
}