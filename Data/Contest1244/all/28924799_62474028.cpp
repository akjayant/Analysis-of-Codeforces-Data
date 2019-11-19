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
const int MAXN=500010;

int T,N;
string S;

void prepare(){
	cin>>N;
	cin>>S;
	int Max=0;
	for(int i=0;i<S.size();i++){
		if(S[i]=='1'){
			Max=max(Max,max(i+1,N-i));
		}
	}
	if(Max==0){
		cout<<N<<endl;
	}
	else{
		cout<<2*Max<<endl;
	}
}

void solve(){

}

int main(){
	cin>>T;
	while(T--){
		prepare();
		solve();
	}
	return 0;
}
