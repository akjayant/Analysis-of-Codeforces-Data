#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define vi vector <int>
#define vl vector <long long>
#define pb push_back
#define mk make_pair
#define pi pair <int,int>
#define pl pair <ll,ll>
#define rep(i,a,n) for(int i=a;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define rep_(i,a,n) for(int i=(n-1);i>=a;i--)
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int p[n];
    	ll x1=0,y1=0,x2=0,y2=0;
    	rep(i,0,n)
    	{
    		cin>>p[i];
			if(p[i]%2)
				x1++;
			else
				y1++;
    	}
		int m;
    	cin>>m;
    	int q[m];
    	rep(i,0,m)
    	{
			cin>>q[i];
			if(q[i]%2)
				x2++;
			else
				y2++;
		}
		cout<<(x1*x2)+(y1*y2)<<endl;
	}
}
