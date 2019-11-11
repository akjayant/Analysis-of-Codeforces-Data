#include <bits/stdc++.h>
#define ENDL '\n'
#define F first
#define S second
#define PB push_back
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define FLOOR(a,b) (a-a%b) / b
#define NEXT(a) next_permutation(ALL(a))
#define T = 100000
#define N = 1000000000000000000
#define RANDOM(a) (rand()%a) + 1
#define TEST_CASES 20

using namespace std;

typedef long long int lli;
typedef long double ld;
typedef unsigned long long int ulli;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    lli t;
    lli a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        (__gcd(a,b)==1) ? cout<<"Finite"<<ENDL : cout<<"Infinite"<<ENDL;
    }
    return 0;
}
    