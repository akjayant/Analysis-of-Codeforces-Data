#include<bits/stdc++.h>

#define pb push_back
#define all(v) (v).begin(),(v).end()
#define ll long long int
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define sz(a) (ll)(a.size())
#define mod 1000000007
#define fi first
#define se second
#define pii pair<ll,ll>

using namespace std;
vector<pair<ll,ll> >v;
void divisor(long long int n)
{
    v.clear();
    long long int i,count=0,k=n;
    for(i=2;i*i<=k;i++)
    {
        if(k%i==0){
        count=0;
        while(k%i==0)
        {
            count++;
            k/=i;
        }
        v.push_back(make_pair(i,count));
        }
    }
    if(k!=1)
    {
        v.push_back(make_pair(k,1));
    }
}

int main(){
	ll t,i,j,k,m,n;
	t=1;
	//cin>>t;
	while(t--){
		cin>>n;
		if(n==1){
			cout<<"1";
			return 0;
		}
		divisor(n);
		for(auto it:v){
			//cout<<it.first<<" ";
		}
		if(v.size()>1){
			cout<<"1";

			return 0;
		}
		cout<<v[0].fi;

	}
	return 0;
}