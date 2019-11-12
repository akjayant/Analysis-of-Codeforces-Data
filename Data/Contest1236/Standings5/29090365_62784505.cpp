#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int lim = 2e5+5;
const int mod = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	
	int t;
	cin>>t;
	while(t--) {
		int a,b,c,n=0;
		cin>>a>>b>>c;

		int s23 = min(b,c/2);
		b -= s23;
		n += 3*s23;

		int s12 = min(a,b/2);
		n += 3*s12;
		
		cout<<n<<'\n';
	}
    return 0;
}