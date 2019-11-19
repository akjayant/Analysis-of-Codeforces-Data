#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, m, k, ans, mod=1e9+7;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, temp=0;
	cin>>n;
	while(n--)
	{
		int a, b, c, d, e;
		cin>>a>>b>>c>>d>>e;
		int x=(a-1)/c+1, y=(b-1)/d+1;
		if(x+y<=e) cout<<x<<' '<<y<<'\n';
		else cout<<"-1\n";
	}
}