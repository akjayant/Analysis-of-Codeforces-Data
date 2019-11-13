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
int main()
{
	int k;
	s(k);
	while(k--)
	{
		vector <int> v;
		vector <pair <int,int> > ans;

		int flg = 1;
		int i,j;
		int n;
		cin >> n;

		string s,t;
		cin >> s >> t;
		

		for(i=0;i<s.size();i++)
		{
			if(s[i] == t[i])
				continue;

			for(j=i+1;j<s.size();j++)
			{
				if(s[j] == t[j])
					continue;

				if(s[i] == s[j])
				{
					ans.pb(mp(j,i));
					swap(t[i] , s[j]);
					break;
				}

				if(s[i] == t[j])
				{
					ans.pb(mp(j,j));
					swap(s[j] , t[j]);

					ans.pb(mp(j,i));
					swap(t[i] , s[j]);

					break;
				}

				if(t[i] == t[j])
				{
					ans.pb(mp(i,j));
					swap(t[j] , s[i]);
					break;
				}

				if(t[i] == s[j])
				{
					ans.pb(mp(j,j));
					swap(s[j] , t[j]);

					ans.pb(mp(i,j));
					swap(t[j] , s[i]);
					break;
				}
			}

			if(j == s.size())
				break;
		}
		

		if(i < s.size())
		{
			cout << "No\n";
			continue;
		}

		cout << "Yes\n";
		cout << ans.size() << endl;
		for(i=0;i<ans.size();i++)
			cout << ans[i].fi+1 << " " << ans[i].se+1 << endl;
	}

	return 0;
}