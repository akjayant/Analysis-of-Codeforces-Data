#include <bits/stdc++.h>

#define int long long int
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define mii map<int,int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007

using namespace std;

vi primes;
vii primeFactors;

void sieve ()
{
    int i, j;
    bitset <1000010> bs;
    bs.set();
    bs[0]=bs[1]=0;
    for (i=2; i<=1000000; i++)
    {
        if (bs[i]==1)
        {
            for (j=i*i; j<=1000000; j+=i)
                bs[j]=0;
            primes.pb(i);
        }
    }
}

void p_factorize (int N)
{
    for (int i=0; i<primes.size(); i++)
    {
        int Count=0;
        while (N%primes[i]==0)
        {
            N/=primes[i];
            Count++;
        }
        if (Count)
            primeFactors.pb(mp(primes[i], Count));
    }
    if (N!=1)
        primeFactors.pb(mp(N, 1));
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    sieve();
    cin>>n;
    p_factorize(n);
    if (primeFactors.size()>1 || n==1)
        cout<<'1';
    else
        cout<<primeFactors[0].ff;
}
