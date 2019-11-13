/*
....................
....................
*/
#include<bits/stdc++.h>
#define ll long long int
#define here cout<<"here\n"
#define pb push_back
#define mp make_pair
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pf printf
#define pfi(x) printf("%d\n",x)
#define pfl(x) printf("%lld\n",x)
using namespace std;

const ll mod = 1e9+7;

const int MAX = 100005;


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll A[n][n];
    ll i,j,k=1;
    ll l=1;
    for(i=0;i<n;i++)
    {
       if(k==1)
       {
       	k=0;
       	for(j=0;j<n;j++)
       		{
       			A[j][i]=l;
       			l++;
       		}
       }
       else
       {
       	k=1;
       	for(j=n-1;j>=0;j--)
       		{
       			A[j][i]=l;
       			l++;
       		}
       }
    }

    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    	{
    		cout<<A[i][j]<<" ";
    	}
    	cout<<endl;
    }
	
	return 0;
}