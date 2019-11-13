// Author--> darklight13
//Everything you want is waiting for you on the other side of consistency!
#define _CRT_SECURE_NO_DEPRECATE
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define SYNC std::ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define FRE freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
typedef long double ld;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii>   vii;
#define rep(i,l,r)   for(int i=(l);i<(r);++i)
#define deb(x)     cout << (#x) << " is " << (x) << endl
#define  pb push_back
#define  F  first
#define  S  second
#define all(v) (v).begin(),(v).end()
#define sz(a) (int)((a).size())
#define sq(x) ((x)*(x))
const int MOD = 1e9+7;
const int MOD1 = 998244353;
const int N = 2e5+5;
const int INF = 1000111000111000111LL;
const ld PI = 3.1415926536;

int32_t main()
{
	SYNC
	int T;cin>>T;
	while(T--)
	{
		int n;cin>>n;
		int fre[26]={0};
		string a,b;
		cin>>a>>b;
		for(int i=0;i<sz(a);i++)
		{
			fre[a[i]-'a']++;
			fre[b[i]-'a']++;
		}
		bool good = true;
		for(int i=0;i<26;i++)
		{
			if(fre[i]%2)
			{	
				good = false;
				break;
			}
		}
		if(!good)
		{
			cout<<"No\n";
			continue;
		}
		vector<ii>ans;
		for(int i=0;i<n;i++)
		{
			if(a[i]==b[i])
			{
				continue;
			}
			int flag = 0;
			for(int j = i+1;j<n;j++)
			{
				if(a[j]==a[i])
				{
					ans.pb({j+1,i+1});
					char tmp = a[j];
					a[j] = b[i];
					b[i] = tmp;
					flag++;
					break;
				}
			}
			if(flag)
				continue;
			for(int j=i+1;j<n;j++)
			{
				if(b[j]==a[i])
				{
					ans.pb({j+1,j+1});
					char tmp = a[j];
					a[j] = b[j];
					b[j] = tmp;
					ans.pb({j+1,i+1});
					tmp = a[j];
					a[j] = b[i];
					b[i] = tmp;
					flag++;
					break;
				}
			}
		}
		if(a!=b)
		{
			cout<<"No\n";
		}else
		{
			cout<<"Yes\n";
			cout<<sz(ans)<<'\n';
			for(auto it:ans)
			{
				cout<<it.F<<" "<<it.S<<'\n';
			}
		}
	}	
    return 0;
}