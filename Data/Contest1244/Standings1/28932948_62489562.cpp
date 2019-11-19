#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
#define REP(i,n) for(int i = 0;i < (int)(n);i++)
#define FOR(i,s,n) for(int i = s;i < (int)n;i++)
#define RREP(i,n) for(int i = (int)n-1;i >= 0;i--)
template<class T>inline bool CHMAX(T&a,T b){if(a<b){a = b;return true;}return false;}
template<class T>inline bool CHMIN(T&a,T b){if(a>b){a = b;return true;}return false;}
constexpr long long INF = 1e18;
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0)

int dp[100010][4][4];

signed main(){
	IOS();
	int N;
	cin >> N;
	vector<vector<int>>col(N,vector<int>(3));
	REP(i,3)REP(j,N)cin>>col[j][i];
	vector<int>cnt(N,0);
	vector<int>g[N];
	REP(i,N-1){
		int a,b;
		cin>>a>>b;
		a--;b--;
		cnt[a]++;
		cnt[b]++;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int hazi=2;
	REP(i,N){
		if(cnt[i]==1)hazi--;
		else if(cnt[i]==2)continue;
		else{
			cout<<-1<<endl;
			return 0;
		}
	}
	vector<int>used(N,0);
	REP(i,100010)REP(j,4)REP(k,4)dp[i][j][k]=INF;
	int now = 0;
	REP(i,N)if(cnt[i]==1)now=i;
	REP(i,3)dp[now][i][3]=col[now][i];
	REP(i,N-1){
		used[now]=true;
		int next;
		if(used[g[now][0]])next=g[now][1];
		else next=g[now][0];
		REP(j,3){
			REP(k,4){
				REP(l,4){
					if(j==k||j==l)continue;
					CHMIN(dp[next][j][k],dp[now][k][l]+col[next][j]);
				}
			}
		}
		now=next;
	}
	int mi = INF;
	int three,two;
	REP(i,4)REP(j,4){
		if(CHMIN(mi,dp[now][i][j])){
			three=i+1;
			two=j+1;
		}
	}
	int arr[]={three,two,6-three-two};
	vector<int>ans(N,0);
	int count=0;
	REP(i,N-1){
		ans[now]=arr[count%3];
		if(ans[g[now][0]])now=g[now][1];
		else now=g[now][0];
		count++;
	}
	ans[now]=arr[count%3];
	cout<<mi<<endl;
	REP(i,ans.size())cout << ans[i] << " \n"[i+1 == ans.size()];

}