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



signed main(){
	int Q;
	cin >> Q;
	vector<int>ans;
	while(Q--){
		int N;
		cin >> N;
		string s;
		cin >> s;
		int zero=1,iti=1;
		REP(i,N){
			if(s[i]!='0')zero=0;
			if(s[i]!='1')iti=0;
		}
		if(zero)ans.push_back(N);
		else if(iti)ans.push_back(N*2);
		else{
			int l = 0;
			while(l<N&&s[l]=='0')l++;
			int r = 0;
			while(r<N&&s[N-1-r]=='0')r++;
			ans.push_back((N-min(l,r))*2);
		}
	}
	for(auto e:ans)cout<<e<<endl;
}