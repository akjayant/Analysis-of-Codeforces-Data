#include <bits/stdc++.h>
#define N 100005
#define ll long long int 	
#define MP make_pair
#define pb push_back
#define ppb pop_back
#define sp " "
#define endl "\n"
#define fi first
#define se second
#define ii pair<int,int>
#define lli pair<ll,ll>
#define fast cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define fast2 freopen ("badhair.gir","r",stdin);freopen ("badhair.cik","w",stdout);
#define mod 1000000007
#define fs(x,y) for(ll i=1;i<=y;i++) cin>>x[i]
#define fo(i,x,y) for(ll i=x;i<=y;i++)
#define INF 1000000000005
using namespace std;

ll n,m,ar[N],sum,t,tut[40];

vector<lli> ans;

void write()
{
	cout<<"Yes"<<endl;
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
		cout<<ans[i].fi<<sp<<ans[i].se<<endl;
}



int main()
{
	fast;
	// cout<<endl;
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans.clear();
		fo(i,1,26)
		tut[i]=0;
		char s[3][N];
		cin>>s[1]+1;
		cin>>s[2]+1;
		fo(i,1,n)
			tut[s[1][i]-'a'+1]++,tut[s[2][i]-'a'+1]++;
		int flag=0;
		fo(i,1,26)
		if(tut[i]%2==1)
		{
			cout<<"No"<<endl;
			flag=1;
			break;
		}

		if(flag)
			continue;


		fo(i,1,n)
		{
			if(s[1][i]==s[2][i])
				continue;
			int tut=0;
			for(int j=i+1;j<=n;j++)
			{
				if(s[1][j]==s[1][i])
				{
					tut=j;
					break;
				}
			}
			if(tut)
			{
				ans.pb({tut,i});
				swap(s[1][tut],s[2][i]);
				// cout<<s[1]+1<<sp<<s[2]+1<<endl;
				continue;
			}
			for(int j=i+1;j<=n;j++)
			{
				if(s[2][j]==s[1][i])
				{
					tut=j;
					swap(s[2][j],s[1][n]);
					swap(s[1][n],s[2][i]);
					break;
				}
			}
			// cout<<s[1]+1<<sp<<s[2]+1<<endl;
			ans.pb({n,tut});
			ans.pb({n,i});



		}



		write();

	}

}



/*     cd onedrive\desktop\kod
cls

Sinav:21-22 aralik
Aciklama: Muhtemelen 25 aralik
*/