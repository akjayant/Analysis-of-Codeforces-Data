#include<bits/stdc++.h>
#define LL long long int
#define FIO ios::sync_with_stdio(false)
#define FRD freopen("input.txt","r",stdin)
#define lowbit(x) (x&-(x))
#define INF 1e18
#define ms(x) memset(x,0,sizeof x)
#define pb(x) push_back(x)
#define lson l,mid,now<<1
#define rson mid+1,r,now<<1|1
#define UNIQUE(x) unique(x.begin(),x.end())
#define SORT(x) sort(x.begin(),x.end())
#define LISAN(x) x.erase(UNIQUE(x),x.end())
#define pii pair<int,int>
#define pll pair<LL,LL>
#define N 100010
const LL MOD=1e9+7;
using namespace std;
template<class T> inline T Min(const T& a,const T& b){return a<b?a:b;}
template<class T> inline T Max(const T& a,const T& b){return a<b?b:a;}
inline void inc(int &x,int &v,int &mod){x+=v;if(x>=mod) x-=mod;}
inline void dec(int &x,int &v,int &mod){x-=v;if(x<0) x+=mod;}
inline int read(){char ch = getchar();int x = 0, f = 1;while(ch < '0' || ch > '9') {if(ch == '-') f = -1;ch = getchar();}while('0' <= ch && ch <= '9') {x = x * 10 + ch - '0';ch = getchar();}return x * f;}
inline LL readl(){char ch = getchar();LL x = 0, f = 1;while(ch < '0' || ch > '9') {if(ch == '-') f = -1;ch = getchar();}while('0' <= ch && ch <= '9') {x = x * 10 + ch - '0';ch = getchar();}return x * f;}
string str;
int n,k;
void update(int l,int r){
	if(l==r)	return;
	int len=r-l+1;
	if(len&1){
		for(int i=l+1,cnt=k;i<=(r+l)/2&&cnt;cnt--,i++){
			str[i]=str[l];
		}
		for(int i=r-1,cnt=k;i>=(r+l)/2&&cnt;cnt--,i--){
			str[i]=str[r];
		}
		if(k&1){
			int L=l+k+1,R=r-k-1;
			while(L<=R){
				if(str[L]=='B')	str[L]='W';
				else str[L]='B';
				L++;
			}
		}
	}
	else{
		//cout<<l<<' '<<r<<' '<<len<<endl;
		for(int i=l+1,cnt=k;i<l+len/2&&cnt;cnt--,i++){
			str[i]=str[l];
		}
		for(int i=r-1,cnt=k;i>r-len/2&&cnt;cnt--,i--){
			str[i]=str[r];
		}
		if(k&1){
			int L=l+k+1,R=r-k-1;
			while(L<=R){
				if(str[L]=='B')	str[L]='W';
				else str[L]='B';
				L++;
			}
		}
	}
}
void solve(int l,int r){
//	cout<<l<<' '<<r<<endl;
//	for(int i=n;i<=r;i++)
//		cout<<str[i];
//	for(int i=l;i<n;i++){
//		cout<<str[i];
//	}
//	cout<<endl;
	int lastpt=l,nowpt=l+1;
	bool flag=true;
	while(nowpt<=r){
		if(str[nowpt]==str[nowpt-1]){
			update(lastpt,nowpt-1);
			lastpt=nowpt;
//			for(int i=n;i<=r;i++)
//				cout<<str[i];
//			for(int i=l;i<n;i++){
//				cout<<str[i];
//			}
//			cout<<endl;
		}
		nowpt++;
	}
	update(lastpt,r);
	for(int i=n;i<=r;i++)
		cout<<str[i];
	for(int i=l;i<n;i++){
		cout<<str[i];
	}
}
int main(){
	#ifndef ONLINE_JUDGE
    	int startTime = clock();
		FRD;
	#endif
	FIO;
	cin>>n>>k;
	cin>>str;
	bool flag=true;
	if(str[0]==str[n-1])	flag=false;
	for(int i=1;i<str.size();i++){
		if(str[i]==str[i-1])	flag=false;
	}
	if(flag){
		if(k&1){
			for(int i=0;i<str.size();i++){
				if(str[i]=='B')	str[i]='W';
				else str[i]='B';
			}
			cout<<str<<endl;
		}
		else cout<<str<<endl;
		return 0;
	}
	else{
		str+=str;
		if(str[0]==str[n-1])	solve(0,n-1);
		else{
			for(int i=1;i<n;i++){
				if(str[i]==str[i-1]){
					solve(i,i+n-1);
					break;
				}
			}
		}
	}
	#ifndef ONLINE_JUDGE
    	printf("Time = %dms\n", clock() - startTime);
	#endif
	return 0;
}









