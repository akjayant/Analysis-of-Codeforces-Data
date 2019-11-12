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

const int N=50+10;
int n;
char s[2][N];
int cnt[3][26];
vi ans[2];
 
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
			memset(cnt,0,sizeof(cnt));
			rep(i,1,n+1)
			{
				cnt[0][s[0][i]-'a']++;
				cnt[1][s[1][i]-'a']++;
				cnt[2][s[0][i]-'a']++;
				cnt[2][s[1][i]-'a']++;
			}
			bool flag=0;
			rep(i,0,26)if(cnt[2][i]&1)flag=1;
			if(flag)
			{
				cout<<"No\n";
				continue;
			}
			ans[0].clear();
			ans[1].clear();
			rep(i,1,n+1)
			{
				if(s[0][i]==s[1][i])continue;
				else if(cnt[0][s[0][i]-'a']>cnt[1][s[0][i]-'a'])
				{
					rep(j,i+1,n+1)
					{
						if(s[0][i]==s[0][j])
						{
							swap(s[1][i],s[0][j]);
							cnt[0][s[0][j]-'a']++;
							cnt[0][s[1][i]-'a']--;
							cnt[1][s[0][j]-'a']--;
							cnt[1][s[1][i]-'a']++;
							ans[0].pb(j);
							ans[1].pb(i);
							break;
						}
					}	
				}
				else
				{
					rep(j,i+1,n+1)
					{
						if(s[0][i]==s[1][j])
						{
							swap(s[0][j],s[1][j]);
							cnt[0][s[0][j]-'a']++;
							cnt[0][s[1][j]-'a']--;
							cnt[1][s[0][j]-'a']--;
							cnt[1][s[1][j]-'a']++;
							ans[0].pb(j);
							ans[1].pb(j);
							swap(s[1][i],s[0][j]);
							cnt[0][s[0][j]-'a']++;
							cnt[0][s[1][i]-'a']--;
							cnt[1][s[0][j]-'a']--;
							cnt[1][s[1][i]-'a']++;
							ans[0].pb(j);
							ans[1].pb(i);
							break;
						}
					}
				}
			}
			cout<<"Yes\n";
			cout<<ans[0].size()<<endl;
			rep(i,0,ans[0].size())cout<<ans[0][i]<<" "<<ans[1][i]<<endl;
		}
	}
 
	return 0;
}