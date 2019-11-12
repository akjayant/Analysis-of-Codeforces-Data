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

int N,K;
int room[MAXN]={0};

bool cmp(int a,int b){
	return a>b; 
} 

void prepare(){
	cin>>N;
	for(int i=1;i<=N;i++){
		scanf("%d",&room[i]);
	}
	sort(room+1,room+1+N,cmp);
	int ans=0;
	for(int i=1;i<=N;i++){
		ans=max(ans,min(i,room[i]));
	}
	cout<<ans<<endl;
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
