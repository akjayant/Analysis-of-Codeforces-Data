/*#include<iostream>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdio>
#include<stack>
#include<map>
#include<queue>
#include<vector>*/
/*
lower_bound是大于等于
upper_bound是大于
set存元素
map有映射
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=1000010;

ll N;

void prepare(){
	cin>>N;
	
	int cnt=0;
	int tmp=0;
	for(ll i=2;i*i<=N;i++){
		if(N%i) continue;
		tmp=i;
		while(N%i==0) N/=i;
		cnt++;
	}
	if(N!=1) cnt++;
	
	if(cnt==1){
		if(tmp) cout<<tmp<<endl;
		else cout<<N<<endl;
	}
	else{
		cout<<1<<endl;
	}
}

void solve(){

}

int main(){
	prepare();
	solve();
	return 0;
}
