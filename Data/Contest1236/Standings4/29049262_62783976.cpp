#include <bits/stdc++.h>
using namespace std;

#define int long long int

const int mod = 1e9+7;


#undef int
int main()
{
#define int long long int
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin>>t;
	while(t--)
	{
		int a, b, c;
		cin>>a>>b>>c;
		int l = min(b, c/2);
		b-=l;
		l+=min(a, b/2);
		cout<<3*l<<endl;
	}

	return 0;
}