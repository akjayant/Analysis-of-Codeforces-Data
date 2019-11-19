#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
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



signed main(){
	IOS();
	int N,K;
	cin>>N>>K;
	vector<int>a(N);
	REP(i,N)cin>>a[i];
	sort(a.begin(),a.end());
	vector<pair<int,int>>v;
	v.push_back({a[0],1});
	FOR(i,1,N){
		if(v.back().first==a[i])v.back().second++;
		else v.push_back({a[i],1});
	}
	int l=0,r=v.size()-1;
	int lsum=v[0].second,rsum=v.back().second;
	REP(i,N){
		if(K==0||l==r){
			cout<<0<<endl;
			return 0;
		}
		if(lsum>rsum){
			int dist = abs(v[r-1].first-v[r].first);
			if(dist*rsum>=K){
				cout<<v[r].first-K/rsum-v[l].first<<endl;
				return 0;
			}else{
				K-=dist*rsum;
				r--;
				rsum+=v[r].second;
			}
		}else{
			int dist = abs(v[l+1].first-v[l].first);
			if(dist*lsum>=K){
				cout<<v[r].first-v[l].first-K/lsum<<endl;
				return 0;
			}else{
				K-=dist*lsum;
				l++;
				lsum+=v[l].second;
			}
		}
	}
}