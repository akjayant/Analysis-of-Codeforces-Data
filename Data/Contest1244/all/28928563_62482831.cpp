/* 
 * Author: Imagine_I
 * Time: 2019-10-13 17:52:10
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
const int maxn=1e5+10;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
int book[maxn];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	ll k;
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>book[i];
	sort(book,book+n);
	ll l=0,numl=1,r=n-1,numr=1;
	while(k>0)
	{
		if(l==r) break;
		if(numl<numr)
		{
			ll x=book[l+1]-book[l];
			if(k>=x*numl)
			{
				k-=x*numl;
				l++;
				numl++;
			}
			else break;
		}
		else
		{
			ll x=book[r]-book[r-1];
			if(k>=x*numr)
			{
				k-=x*numr;
				r--;
				numr++;
			}
			else break;
		}
	}
	if(numl<=numr&&l!=r)
	{
		ll x=k/numl;
		book[l]+=x;
	}
	else if(numl>numr&&l!=r)
	{
		ll x=k/numr;
		book[r]-=x;
	}
	cout<<book[r]-book[l]<<'\n';
	return 0;
}
