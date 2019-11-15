#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> ii;
typedef vector<pair<ll,ll> > vii;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<pair<long long,long long> > vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
 
#define PI 3.141592653589793
#define mod 1000000007
#define N 2000006
//llN;
//# define N 2003
# define maxn 200005
template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }
# define INF 1000000000000000000
# define A 1000000
//# define int long long

//g++ -std=c++11 q4.c

//int cnt[1002][1002];

int main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		string s,t;
		cin >> s >> t;
		vector<pair<int,int> >ans;

		bool ans_no = 0;
		for(int i=0;i<n;i++)
		{
			//trace2(s,t);
			bool f = 0;
			if(ans.size() > 2*n)
				break;
			if(s[i] != t[i])
			{
				for(int j=0;j<n;j++)
				{
					if(j == i)
						continue;
					if((s[j] != t[j]) && (s[i] == s[j]))
					{
						ans.push_back({j,i});
						swap(s[j],t[i]);
						f = 1;
						break;
					}
				}
				if(!f)
				{
					for(int j=0;j<n;j++)
					{
						if(j == i)
							continue;
						if((s[j] != t[j]) && (t[i] == t[j]))
						{
							ans.push_back({i,j});
							swap(s[i],t[j]);
							f = 1;
							break;
						}
					}
				}
				if(!f)
				{
					for(int j=0;j<n;j++)
					{
						if((s[j] != t[j]) && (s[i] == t[j]))
						{
							ans.push_back({j,j});
							ans.push_back({j,i});
							//trace2(j,j);
							//trace2(i,j);
							swap(s[j],t[j]);
							swap(s[j],t[i]);
							f = 1;
							break;
						}
					}
				}
				if(!f)
				{
					//trace1(i);
					cout << "No"<<"\n";
					ans_no = 1;
					break;
				}
			}
			
		}
		//trace1(ans_no);
		if(ans.size()<=2*n && !ans_no)
		{
			cout << "Yes"<<"\n";
			cout << ans.size()<<"\n";
			//trace2(s,t);
			for(int i=0;i<ans.size();i++)
				cout << ans[i].first+1<<" "<< ans[i].second+1 <<"\n";
		}
	}
}