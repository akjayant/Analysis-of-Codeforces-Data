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
const int MAXN=100010;

ll n[MAXN]={0};
ll room[MAXN]={0};
ll num[MAXN]={0};
ll cnt=0;
ll N,K;

bool cmp(ll x,ll y){
	return x<y;
}

void prepare(){
	cin>>N>>K;
	for(ll i=1;i<=N;i++){
		scanf("%I64d",&n[i]);
	}
	sort(n+1,n+1+N,cmp);
	for(ll i=1;i<=N;i++){
		if(n[i]!=n[i-1]){
			cnt++;
			room[cnt]=n[i];
		}
		num[cnt]++;
	}
	N=cnt;
	ll l=1,r=N;
	ll ln=num[1],rn=num[N];
	ll flag=0;
	while(l<r){
		flag=0;
		if(ln<rn){
			if((room[l+1]-room[l])*ln<=K){
				K-=(room[l+1]-room[l])*ln;
				l++;
				ln+=num[l];
				flag=1;
			}
		}
		else{
			if((room[r]-room[r-1])*rn<=K){
				K-=(room[r]-room[r-1])*rn;
				r--;
				rn+=num[r];
				flag=1;
			}
		}
		if(flag==0) break;
	}
	if(l==r){
		cout<<0<<endl;
		return;
	}
	else{
		cout<<room[r]-room[l]-K/min(ln,rn);
	}
}

void solve(){

}

int main(){
	prepare();
	solve();
	return 0;
}
