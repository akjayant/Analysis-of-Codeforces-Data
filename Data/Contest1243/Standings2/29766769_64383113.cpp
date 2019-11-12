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

ll n,m,ar[N],sum,t,tut[40][40];



int main()
{
	fast;
	cin>>t;
	while(t--)
	{
		cin>>n;
		fo(i,1,26)
		fo(j,1,26)
		tut[i][j]=0;
		char s[3][N];
		cin>>s[1]+1;
		cin>>s[2]+1;
		fo(i,1,n)
			tut[s[1][i]-'a'+1][s[2][i]-'a'+1]++;
		int flag=0;
		fo(i,1,26)
			fo(j,1,26)
			{
				if(i==j)
					continue;
				if(tut[i][j])
				{
					flag++;
				}
				if(tut[i][j]!=2 && tut[i][j]>=1)
					flag=3;
			}
		if(flag>1)
		{
			cout<<"No"<<endl;
			continue;
		}
		cout<<"Yes"<<endl;
		continue;
		// int flag2=0;
		// fo(i,1,26)
		// 	fo(j,1,26)
		// 	{
		// 		if(i==j)
		// 			continue;
		// 		if(tut[i][j])
		// 			flag1=i,flag2=j;
		// 	}
		// fo(i,1,n)
		// {
		// 	if(s[i]-'a'+1==flag1 && s[2][i]-'a'+1==flag2)
		// 		cout<<
		// }
	
		// fo(i,1,26)
		// if(tut[i]%2==1)
		// {
		// 	cout<<"No"<<endl;
		// 	flag=1;
		// 	break;
		// }

	}

}



/*     cd onedrive\desktop\kod
cls

Sinav:21-22 aralik
Aciklama: Muhtemelen 25 aralik
*/