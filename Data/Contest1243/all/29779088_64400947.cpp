#include <bits/stdc++.h>

#define pb push_back
#define ll long long
#define ull unsigned long long
#define stop return cout << -1 << endl, false;

const long long mod = 1000000007;

using namespace std;

vector <int> primes;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin>>n;

    if(n%2==0) primes.pb(2);

    while(n%2==0) n/=2;

    if(n==1 && primes.size())
    {
        cout<<2<<endl;
        return 0;
    }

    if(n!=1 && primes.size())
    {
        cout<<1<<endl;
        return 0;
    }

    // now, if N is prime, the answer is N
    // else, the answer is 1

    for(int i=3; i<=sqrt(n); i+= 2)
    {
        if(n % i == 0)
        {
            while(n%i==0) n/=i;
            if(n==1)
            {
                cout<<i<<endl;
                return 0;
            }
            cout<<1<<endl;
            return 0;
        }
    }

    cout<<n<<endl;
    return 0;
}
