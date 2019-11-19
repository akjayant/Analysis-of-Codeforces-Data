#include <bits/stdc++.h>

using namespace std;

vector<long long> divs;

long long get_gcd(long long n){
    long long cur_gcd = n;

    for(long long p: divs){

        cur_gcd = __gcd(p,cur_gcd);
    }
    return cur_gcd;
}

void calc_divs(long long n){
    long long sq = sqrt(n);

    for(long long i = 2; i<=sq; ++i){
        if(n%i==0){
            divs.push_back(i);
            divs.push_back(n/i);
        }
    }
}

int main(){
    long long n;
    cin>>n;
    calc_divs(n);
    cout<<get_gcd(n)<<"\n";
    return 0;
}
