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
	int N,P,W,D;
	cin>>N>>P>>W>>D;
	REP(i,W+1){
		int y = i;
		int p = P - y * D;
		int x = p / W;
		if(x>=0&&y>=0&&x*W+y*D==P&&x+y<=N){
			cout<<x<<" "<<y<<" "<<N-x-y<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
}