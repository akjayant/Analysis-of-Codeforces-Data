#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+7;
typedef pair<int,int> pii;
set<int> se;
vector<int> vec;
queue<int> q;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n,m;cin>>n>>m;int g=__gcd(n,m);
	if(g==1) cout<<"Finite"<<endl;
	else cout<<"Infinite"<<endl;
	}
	return 0;
 } 