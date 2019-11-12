//mridul1809
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define s(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define sd(x) scanf("%lf",&x)
#define p(x) printf("%d ",x)
#define pl(x) printf("%lld ",x)
#define pd(x) printf("%lf ",x)
#define ps(x) printf(x)
#define pend printf("\n")
#define nm 100005
int f[30];
int main()
{
	int k;
	s(k);
	while(k--)
	{
		vector <int> v;
		int i;
		bool flg = 0;
		for(i=0;i<30;i++)
			f[i] = 0;
		int n;
		cin >> n;
		string s,t;
		cin >> s >> t;
		for(i=0;i<n;i++)
		{
			if(s[i] != t[i])
				v.pb(i);

			f[s[i] - 'a']++;

			if(f[s[i] - 'a'] > 1)
				flg = 1;
		}

		if(v.size() == 0 && flg)
		{
			cout << "Yes\n";
			continue;
		}

		if(v.size() == 1 || v.size() > 2)
		{
			cout << "No\n";
			continue;
		}

		if(s[v[0]] == s[v[1]] && t[v[0]] == t[v[1]])
		{
			cout << "Yes\n";
			continue;
		}

		cout << "No\n";
	}

	return 0;
}