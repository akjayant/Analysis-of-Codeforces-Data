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

const int N=1e4+10;
int n;
char  s[2][N];
vi cc;
 
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
			cin>>s[0]+1;
			cin>>s[1]+1;
			cc.clear();
			rep(i,1,n+1)
			{
				if(s[0][i]==s[1][i])continue;
				else cc.pb(i);
			}
			bool flag=0;
			if(cc.size()==2)
			{
				rep(i,0,2)
				{
					if(s[i][cc[0]]!=s[i][cc[1]])flag=1;
				}
			}
			else flag=1;
			if(flag==0)cout<<"Yes\n";
			else cout<<"No\n";
		}
	}
 
	return 0;
}