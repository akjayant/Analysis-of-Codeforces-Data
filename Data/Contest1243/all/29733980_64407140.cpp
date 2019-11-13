#include<bits/stdc++.h>
using namespace std;
#define read FILE *fp;\
fp=freopen("testcase.txt","r",stdin);
#define ll long long
#define ull unsigned long long
#define sf(n) scanf("%I64d",&n)
#define pf(n) printf("%I64d\n",n)
#define loop for(long long i=0;i<n;i++)
#define lp(b,n) for(long long i=b;i<=n;i++)
#define pb(n) push_back(n)
#define srt(v) sort(v.begin(),v.end())
#define rvs(v) sort(v.begin(), v.end(), greater<long long>());
#define F first
#define S second
#define mp(a,b) make_pair(a,b);
#define fio ios::sync_with_stdio(false); cin.tie(),cout.tie();
bool sortbysec(const pair<pair<ll,ll>,ll> &a,
               const pair<pair<ll,ll>,ll> &b)
{
    return (a.second < b.second);
}
class team
{
public:
    ll sol,pen,sub,tpen;
    vector<ll> v;
};
string add(string st1,string st2)
{
    ll r=0;
    string ans;
    ans.resize(3000);
    for(ll i=2999; i>=0; i--)
    {
        ll x=st1[i]-'0';
        ll y=st2[i]-'0';
        ll z=x+y+r;
        if(z>=10)
        {
            r=1;
        }
        else
            r=0;
        ans[i]=(z%10)+'0';
    }
    //cout<<ans<<endl;;
    return ans;
}
// C++ program to print all primes smaller than or equal to
// n using Sieve of Eratosthenes
#include <bits/stdc++.h>
using namespace std;
bool prime[1000000+1];
void SieveOfEratosthenes(ll n)
{
	// Create a boolean array "prime[0..n]" and initialize
	// all entries it as true. A value in prime[i] will
	// finally be false if i is Not a prime, else true.

	for (ll p=2; p*p<=n; p++)
	{
		// If prime[p] is not changed, then it is a prime
		if (prime[p] == false)
		{
			// Update all multiples of p
			for (ll i=p*2; i<=n; i += p)
				prime[i] = true;
		}
	}

	// Print all prime numbers

}

// Driver Program to test above function


int main()
{

ll q;
cin>>q;
while(q--)
{
    ll n;
    sf(n);
    string st1;
    string st2;
    cin>>st1;
    cin>>st2;
    ll c=0;
    vector<pair<ll,ll> > vp;
    loop
    {
        if(st1[i]!=st2[i])
        {
            ll f=0;
            for(ll j=i+1;j<n;j++)
            {
                if(st1[i]==st1[j])
                {
                    c++;
                    vp.pb(make_pair(j,i));
                    swap(st1[j],st2[i]);
                    f=1;
                    break;
                }
                else if(st2[j]==st1[i])
                {
                    c+=2;
                    vp.pb(make_pair(j,j));
                    vp.pb(make_pair(j,i));
                    swap(st1[j],st2[j]);
                    swap(st1[j],st2[i]);
                    f=1;
                    break;
                }
            }


        }
    }
    ll fl=0;
    loop
    {
        if(st1[i]!=st2[i])
        {
            fl=1;
            break;
        }
    }
    if(fl==1)
    {
        printf("NO\n");
    }
    else
    {
        cout<<"YES\n";
        cout<<c<<endl;
        for(ll i=0;i<vp.size();i++)
        {
            printf("%lld %lld\n",vp[i].F+1,vp[i].S+1);
        }
    }
}
}




