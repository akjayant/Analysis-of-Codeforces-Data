#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t;
	cin>>t;
	for(ll tt=0;tt<t;tt++)
	{
		ll n;
		cin>>n;
		string a,b;
		cin>>a>>b;
		vector<bool> v(n);
		for(ll i=0;i<n;i++)
			if(a[i]==b[i])
				v[i] = 1;
 
		ll c = 0;
		for(ll i=0;i<n;i++){
           if(!v[i])
			c += 1;
    }
 
		if(c==0)
			cout<<"Yes"<<endl;
		else if(c!=2)
			cout<<"No"<<endl;
		else
		{
			vector<ll> x;
			for(ll i=0;i<n;i++)
				if(v[i]==0)
					x.push_back(i);
			swap(a[x[0]], b[x[1]]);
			if(a!=b)
				cout<<"No"<<endl;
			else
				cout<<"Yes"<<endl;
		}
	}
 
    return 0;
}