#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<long long> prime;
char sieve[1000008];
unsigned long long a[1000008];
void primeSieve () {
    long long n=1000007;
    sieve[0] = sieve[1] = 1;
    prime.push_back(2);
    for ( int i = 4; i <= n; i += 2 ) sieve[i] = 1;
    int sqrtn = sqrt ( n );
    for ( int i = 3; i <= sqrtn; i += 2 ) {
        if ( sieve[i] == 0 ) {
            for ( int j = i * i; j <= n; j += 2 * i ) sieve[j] = 1;
        }
    }
    for ( int i = 3; i <= n; i += 2 ) if ( sieve[i] == 0 ) prime.push_back(i);
}

int main()
{
    primeSieve();
    ll x;
    cin>>x;
    int cnt=0;
    ll jj=x;
    for(ll i=0;prime[i]*prime[i]<=x;i++){
        if(x%prime[i]==0){
            cnt++;
            while(x%prime[i]==0)x/=prime[i];
            jj=prime[i];
        }
    }
    if(x!=1)cnt++;
    if(cnt==1){
        cout<<jj<<endl;
    }
    else if(cnt==0){
        cout<<x<<endl;
    }
    else cout<<"1"<<endl;
}
