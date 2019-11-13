/*input
5
5
souse
houhe
3
cat
dog
2
aa
az
3
abc
bca
5
aacab
aabac

*/
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second
#define watch(x) cout << (#x) << " is " << (x) << endl
#define N 100002

using namespace std;
int main()
{
	fastio
	ll T=1,n,m;string str1,str2;
	cin>>T;
	// cin.ignore(); put after cin, just b4 a getline(cin, s) to avoid getline() directly getting \n
	while(T--)
	{
		ll p=0,q=0,tmp=0,sum=0,count=0; //tmp variable
		int flag=0;
		
		cin >> n;
		cin >> str1;
		cin >> str2;
		char a,b,c,d;
		for (ll i = 0; i < n; ++i)
		{
			if (str1[i]!=str2[i])
			{
				count++;
				if(count==1)
				{
					a=str1[i];
					c=str2[i];
				}
				else if(count==2)
				{
					b=str1[i];
					d=str2[i];
				}
				else
				{
					flag=1;
					break;
				}
			}
		}
		if(flag==0 && (a==b && c==d))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}