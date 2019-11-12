/*
数据不清空，爆零两行泪。
多测不读完，爆零两行泪。
边界不特判，爆零两行泪。
贪心不证明，爆零两行泪。
D P 顺序错，爆零两行泪。
大小少等号，爆零两行泪。
变量不统一，爆零两行泪。
越界不判断，爆零两行泪。
调试不注释，爆零两行泪。
溢出不 l l，爆零两行泪。
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
	int n;
	cin>>n;
	if(n%2==0){
		int now=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n/2;j++)cout<<++now<<" ",cout<<n*n-now+1<<" ";
			puts("");
		}
	}
	else{
		int now=0;
		vector<int> ans[n+1];
		for(int i=1;i<=n;i++)for(int j=1;j<=n/2;j++)ans[i].pb(++now),ans[i].pb(n*n-now+1);
		for(int i=1;i<=n;i++)ans[i].pb(now+i);
		for(int i=1;i<=n;i++){
			for(int j=0;j<n;j++)cout<<ans[i][j]<<" ";
			puts("");
		}
	}
	return 0;
}