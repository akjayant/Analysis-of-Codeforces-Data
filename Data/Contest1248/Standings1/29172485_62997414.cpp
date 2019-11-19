#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,n) for(int i = 0;i < (int)(n);i++)
#define RREP(i,n) for(int i = (int)n-1;i >= 0;i--)
#define FOR(i,s,n) for(int i = s;i < (int)n;i++)
#define RFOR(i,s,n) for(int i = (int)n-1;i >= s;i--)
#define ALL(a) a.begin(),a.end()
template<class T>inline bool CHMAX(T&a,T b){if(a<b){a = b;return true;}return false;}
template<class T>inline bool CHMIN(T&a,T b){if(a>b){a = b;return true;}return false;}
constexpr long long INF = 1e18;
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0)



signed main(){
	IOS();
	int N;
	cin>>N;
	string s;
	cin>>s;
	int ans = 0;
	int jj=0,ii=0;
	REP(i,N){
		FOR(j,i+1,N){
			swap(s[i],s[j]);
			int now=0,cnt=0,ma=0,start=0,mi=INF;
			REP(k,N){
				if(s[k]=='(')now++;
				else now--;
				if(CHMIN(mi,now))start=k+1;
			}
			now=0;
			int flg=1;
			FOR(k,start,start+N){
				if(s[k%N]=='(')now++;
				else now--;
				if(now<0)flg=0;
				if(now==0)cnt++;
			}
			if(flg&&now==0&&CHMAX(ans,cnt)){
				ii=i;jj=j;
				//cout<<ans<<" "<<s<<endl;
			}
			swap(s[i],s[j]);
		}
	}
	cout<<ans<<endl;
	cout<<ii+1<<" "<<jj+1<<endl;
}