#include <bits/stdc++.h>
#define intt long long
#define pb push_back
#define endl '\n'
#define F first
#define S second
#define pii pair<int,int>
#define pil pair<int,intt>
#define pli pair<intt,int>
#define pll pair<intt,intt>
using namespace std;
int i,j;
int main()
{
	int t;
	cin >> t;
	while ( t-- )
	{
		int x,y,z;
		cin >> x >> y >> z;
		int ans=0;
		while ( y > 0 && z > 1 )
		{
			ans += 3;
			y--;
			z -= 2;
		}
		while ( x > 0 && y > 1 )
		{
			ans += 3;
			y -= 2;
			x--;
		}
		cout << ans << endl;
	}
}