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
    int n;
    cin>>n;
    int a[n];
    rep(i,0,n)
    	cin>>a[i];
    sort(a,a+n);
    ll x=0,y=0;
    rep(i,0,n)
    {
    	if(i<n/2)
    		x+=a[i];
    	else
    		y+=a[i];
	}
	cout<<x*x+y*y<<endl;
}
