#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int a,b,ca;
	cin>>a>>b;
	if(a>b)swap(a,b);
	vector<bool>u(b);
	int br=0;
	ca=a%b;
	while(u[ca]==0)
	{
		u[ca]=1;
		br++;
		ca=(a+ca)%b;
	}
	if(br==b)cout<<"Finite\n";
	else cout<<"Infinite\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	while(n--)
		solve();
}
