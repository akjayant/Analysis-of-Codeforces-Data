#include <bits/stdc++.h>

using namespace std;

string s="";
int pref[1000];
int suf[1000];
int rm=0;
int ll=0,rr=0;
signed main()
{
	int n=0;
	cin >> n;
	cin >> s;
	for (int i=0; i<n; i++)
	{
		for (int j=i; j<n; j++)
		{
			if (j==i && i!=0)
				continue;
			swap(s[i], s[j]);
			int bal=0,Max=0;
			for (int k=0; k<n; k++)
			{
				if (s[k]=='(')
					bal--;
				else
					bal++;	
				pref[k] = bal;
				if (bal>0)
					Max = max(Max, bal);
			}
			bal = 0;
			for (int k=n-1; k>=0; k--)
			{
				if (s[k]=='(')
					bal--;
				else
					bal++;
				suf[k] = bal;
			}
			int res=0;
			for (int k=0; k<n; k++)
			{
				if ((k==0 && pref[n-1]==0 && Max==0) || pref[k-1]+suf[k]==0 && suf[k]<=-Max && pref[k-1]>=0)
				{
					res++;
				}
			}	
			if (res>rm)
			{
				rm = res;
				ll = i;
				rr = j;
			}
			swap(s[i], s[j]);
		}	
	}
	cout << rm << endl;	
	cout << ll+1 <<' '<<rr+1;
}