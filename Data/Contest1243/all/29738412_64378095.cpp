#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define de(x) cout << #x << " = " << x << endl
#define dd(x) cout << #x << " = " << x << " "
#define endl '\n'
#define pw(x) (1ll<<(x))
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
int a[1001];
 
int main() 
{
    std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	int t;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>n;
			rep(i,1,n+1)cin>>a[i];
			sort(a+1,a+1+n);
			int ans=0;
			int k=1;
			rep(i,1,n+1)
			{
				while(k<=n&&i>a[k])k++;
				if(k>n)break;
				if(n-k+1>=i)ans=i;
				else break;
			}
			cout<<ans<<endl;
		}
	}
 
	return 0;
}