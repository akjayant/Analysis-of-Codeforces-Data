#include <bits/stdc++.h>

using namespace std;
long long n,q,c,k,s,r,p,sc,a,b,o,aa,lsc,bb,cc,jj,arr[102];
map<long long, long long> m;

void primeFactors(long long n)
{
    while (n % 2 == 0){
        m[2]++;
        n = n/2;
    }
    for (long long i = 3; i <= sqrt(n); i = i + 2){
        while (n % i == 0){
            m[i]++;
            n = n/i;
        }
    }
    if (n > 2) m[n]++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    m.clear();
    primeFactors(n);
    if(n==1) {cout<<1<<'\n'; return 0;}
    auto itr=m.begin();
    if(m.size()==1) {cout<<itr->first<<'\n'; return 0;}
    cout<<1<<'\n';
}
