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

int T;

int a,b,c,d,k;

int x,y;

void prepare(){
	cin>>a>>b>>c>>d>>k;
	x=(a/c)+(a%c>0);
	y=(b/d)+(b%d>0);
	if(x+y<=k){
		cout<<x<<" "<<y<<endl;
	}
	else cout<<-1<<endl;
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
