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

int K,N;
string S,T;
void prepare(){
	int cnt=0;
	cin>>N;
	cin>>S>>T;
	char a,b,c,d;
	for(int i=0;i<N;i++){
		if(S[i]!=T[i]){
			cnt++;
			if(cnt==1) a=S[i],b=T[i];
			if(cnt==2) c=S[i],d=T[i];
		}
	}
	if(cnt==2&&((a==c&&b==d))){
		cout<<"Yes"<<endl;
	}
	else cout<<"No"<<endl;
}

void solve(){

}

int main(){
	cin>>K;
	while(K--){
	prepare();
	solve();
	}
	return 0;
}
