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
void mian(){
	int a,b,c;
	cin>>a>>b>>c;
	int ans=0;
	for(int i=0;i<=100;i++)for(int j=0;j<=100;j++)
		if(i<=a&&2*i+j<=b&&2*j<=c)ans=max(ans,3*(i+j));
	cout<<ans<<"\n";
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}