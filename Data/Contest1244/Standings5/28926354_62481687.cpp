#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

class Triplet
{
	public:
	ll  x;
	ll y;
	ll GCD;
};

Triplet EuclidAlgo (ll a,ll b)      
{
	if(b==0)
	{
		Triplet t;
		t.GCD=a;
		t.x=1;
		t.y=0;
		return t;
	}
	Triplet smallAns=EuclidAlgo(b,a%b);
	Triplet t;
	t.GCD=smallAns.GCD;
	t.x=smallAns.y;
	t.y=smallAns.x-(a/b)*smallAns.y;
	return t;
}
ll MultiplicativeModuloInverse(ll a,ll m)
{
	Triplet t=EuclidAlgo(a,m);
	return (t.x%m + m)% m;
}

ll findAns(ll a,ll b,ll d)       // a=2 b=5 d=3
{
  	ll k=MultiplicativeModuloInverse(b,a);
  	ll y1=(d % a *  k) % a;
  	return y1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,p,w,d;
	cin>>n>>p>>w>>d;
	ll g=__gcd(w,d);
	if(p%g!=0){
		cout<<-1<<endl;
		return 0;
	}
	ll y=findAns(w/g,d/g,p/g);
	ll x=(p-y*d)/w;
	ll z=n-(x+y);
	if(x<0 || y<0 || z<0)cout<<-1<<endl;
	else cout<<x<<" "<<y<<" "<<z<<endl;

}
