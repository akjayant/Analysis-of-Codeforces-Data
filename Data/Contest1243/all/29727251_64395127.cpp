#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define nl cout<<endl

#define pii pair<ll,ll>
#define vi  vector<ll>
#define vii vector<pii>
#define mi  map<ll,ll>
#define all(a)  (a).begin(),(a).end()

#define pb push_back
#define ff first
#define ss second
#define hell 1000000007

#define test4(x,y,z,a) cout<<"x is "<<x<<"		y is "<<y<<"		z is "<<z<<"		a is "<<a<<endl;
#define test3(x,y,z) cout<<"x is "<<x<<"		y is "<<y<<"		z is "<<z<<endl;
#define test2(x,y) cout<<"x is "<<x<<"		y is "<<y<<endl;
#define test1(x) cout<<"x is "<<x<<endl;
#define N 300009

ll power(ll a,ll b,ll m)
{
	ll ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}
vi find(ll n)
{
	set<ll>s;
	vi v;
  while (n % 2 == 0)  
    {  
       s.insert(2);
	n/=2; 
    }  
  
    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
    for (ll i = 3; i <= sqrt(n); i = i + 2)  
    {  
        // While i divides n, print i and divide n  
        while (n % i == 0)  
        {  
            s.insert(i); 
            n = n/i;  
        }  
    }  
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (n > 2)  
     s.insert(n);
	for(auto it=s.begin();it!=s.end();it++)
	{
		//tes1(*it);
		v.pb(*it);
	}
	return v;
}
int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
        ll n;cin>>n;
	if(n==1)
	cout<<1<<endl;
	/*else if(isPrime(n))
	cout<<n<<endl;*/
	else
	{
		/*if(n%2==0)
		{
			ld haha=(ld)(n);
			haha=log2(haha);
			if(haha==(ll)haha)
			cout<<2<<endl;
			else
			cout<<1<<endl;
		}
		else*/
		{
			vi v=find(n);
			if(v.size()==1)
			cout<<v[0]<<endl;
			else
			cout<<1<<endl;
		}
	}
}