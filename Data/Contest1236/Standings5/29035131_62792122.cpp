/**************************************************RJ***************************************************/
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define ppb         pop_back
#define	endl		'\n'
#define mii         map<ll int,ll int>
#define msi         map<string,ll int>
#define mis         map<ll int, string>
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define mpi         map<pair<ll int,ll int>,ll int>
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define vii         vector<pair<ll int, ll int>>
#define vs          vector<string>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define lbnd        lower_bound//lower_bound returns an iterator pointing to the first element in the range [first,last) which has a value not less than ‘val’.
#define ubnd        upper_bound//upper_bound returns an iterator pointing to the first element in the range [first,last) which has a value greater than ‘val’.
#define bs          binary_search
#define er          equal_range//used to find the sub-range within a given range [first, last) that has all the elements equivalent to a given value. It returns the initial and the final bound of such a sub-range.
#define mp          make_pair
#define what_is(x)  cerr << #x << " is " << x << endl;
#define N  100005
#define strup(s)       transform(s.begin(),s.end(),s.begin(), ::toupper)//changes string completely to upper case
#define strlow(s)       transform(s.begin(),s.end(),s.begin(), ::tolower)//changes string completely to lower case
using namespace std;
/*Syntax:-
binary_search(start_ptr, end_ptr, num);
lower = lower_bound (v.begin(), v.end(), val);  
upper = upper_bound (v.begin(), v.end(), val);
pos=upper-v.begin(); or pos=lower-v.begin();
ip =equal_range(v.begin(), v.end(), val);
*/
//ll int primes[n+1];
/*void sieve(ll int n)
{
    rep(i,0,n+1)
    {
        primes[i] = 1;
    }
    rep(i,2,(int)sqrt(n)+1)
    {
        if(primes[i]==1)
        {
            for(ll j=i;j*i<n+1;j++) 
            primes[i*j] = 0;
        }
    }
}*/
ll int binaryExponentiation(ll int x,ll int n)
{
    if(x==0)
    return 0;
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return binaryExponentiation(x*x,n/2);
    else                             //n is odd
        return x*binaryExponentiation(x*x,(n-1)/2);
}
ll int modularExponentiation(ll int x,ll int n,ll int M)
{
    if(x==0)
    return 0;
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return modularExponentiation((x*x)%M,n/2,M);
    else                             //n is odd
        return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;

}

bool prime_check(ll x)
{
    bool prime = (x >= 2);
    for (long long i = 2; i * i <= x; i++) 
    {
        if (x % i == 0) 
        {
            prime = false;
            break;
        }
    }
    return prime;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin>>n>>m;
	ll s=(modularExponentiation(2,m,hell)-1+hell)%hell;
	s=modularExponentiation(s,n,hell);
	cout<<s;
	return 0;
}
