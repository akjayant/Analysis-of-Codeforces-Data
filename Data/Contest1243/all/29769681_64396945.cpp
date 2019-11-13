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
const int MAXN=1020;
struct line{
	char a;
	int rk;
	int id;
}s[MAXN],t[MAXN]; 

struct anw{
	int a,b;
}ap[MAXN];

int K,N;

string S,T;
int cnt[MAXN]={0};
void prepare(){
	int Ans=0;
	memset(cnt,0,sizeof(cnt));
	cin>>N;
	cin>>S>>T;
	for(int i=1;i<=N;i++){
		s[i].a=S[i-1];
		t[i].a=T[i-1];
		cnt[s[i].a-'a']++;
		cnt[t[i].a-'a']++;
		s[i].id=t[i].id=i;
	}
	for(int i=0;i<=30;i++) if(cnt[i]&1){
		cout<<"No"<<endl;
		return;
	}
	int pnt=0;
	cout<<"Yes"<<endl;
	
	for(int i=1;i<=N;i++){
		pnt=0;
		for(int j=i+1;j<=N;j++){
			if(s[j].a==s[i].a) pnt=j;
		}
		if(pnt){
			Ans++;
			ap[Ans].a=pnt;ap[Ans].b=i;
			swap(s[pnt],t[i]);
			continue;
		}
		for(int j=i;j<=N;j++){
			if(s[i].a==t[j].a) pnt=j;
		}
		swap(s[N],t[pnt]);
		ap[++Ans].a=N;
		ap[Ans].b=pnt;
		swap(s[N],t[i]);
		ap[++Ans].a=N;
		ap[Ans].b=i;
	}
	cout<<Ans<<endl;
	for(int i=1;i<=Ans;i++) printf("%d %d\n",ap[i].a,ap[i].b);
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
