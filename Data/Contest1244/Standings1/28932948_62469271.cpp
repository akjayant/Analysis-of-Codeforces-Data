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
	while(Q--){
		int a,b,c,d,k;
		cin>>a>>b>>c>>d>>k;
		int A = (a+c-1)/c;
		int C = (b+d-1)/d;
		if(A+C<=k){
			cout<<A<<" "<<C<<endl;
		}else{
			cout<<-1<<endl;
		}
	}
}