#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define vll vector<ll>

using namespace std;

const ll N = 3e5+100;
const ll MOD = 1e9+7;

int main()
{

	ll t;
	cin >> t;
	while(t--)
	{
		ll n;
		cin >> n;
		string s,t;
		cin >> s >> t;
		ll pos1 = -1,pos2=  -1;
		bool poss = true;
		for(int i =0;i<n;i++)
		{
			if(s[i] != t[i])
			{
				if(pos1 == -1) pos1 = i;
				else if(pos2 == -1) pos2 = i;
				else poss=false;
			}
		}
		if(!poss)
		{
			cout << "No\n";
			continue;
		}
		if( (pos2 == -1 && pos1 == -1))
		{
			cout << "Yes\n";
			continue;
		}	
		if(pos1 && pos2==-1)
		{
			if(s[pos1] != t[pos1] )
			{
				cout << "No\n";
				continue;
			}
			cout << "Yes\n";
			continue;
		}
		char a1 = s[pos1],a2 = s[pos2];
		char b1 = t[pos1],b2 = t[pos2];
		if(b1 == b2 && a2 == a1)
		{
			cout << "Yes\n";
			continue;
		}
		cout << "No\n";
	}
	
	return 0;
}