#include <bits/stdc++.h>
 
using namespace std;

bool is[2000000];

vector <int> primes;

int main(){
    for (int i=2; i<2000000; ++i){
        if (!is[i]){
            long long num = 1ll * i * i;
            while (num < 2000000){
                is[num] = 1;
                num += i * 1ll;
            }
            primes.push_back(i);
        }
    }
    long long n;
    cin >>n;
    int pos = 0;
    long long newN = n;
    int num = 0;
    long long ans = 0;
    while (pos < primes.size() && primes[pos] <= sqrt(n)){
        if (n % primes[pos] == 0){
            num++;
            while (n % primes[pos] == 0){
                n /= primes[pos];
            }
            ans = primes[pos];
        }
        pos++;
    }
    if (n > 1){
        num++;
        ans = n;
    }
    if (num == 0){
        ans = n;
    } else if (num > 1){
        cout <<"1\n";
        return 0;
    }
    cout <<ans <<'\n';
    return 0;
}
