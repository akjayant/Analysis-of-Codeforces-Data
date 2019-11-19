#include <bits/stdc++.h>


#define mkp(i,j) make_pair(i,j)
#define int long long
#define _sz(x) (int)x.size()

using namespace std;
typedef long long ll;
const int MAX = 1e5 + 10;
const int LOGMAX = 105;
const int inf = 1e9;
const int md = 1e9 + 7;
typedef pair < int , int > ii;


int32_t main(){
    int n;cin>>n;
    vector<int> primes;

    for(int i = 2;i*i<=n;i++){
        if (n%i==0){
            primes.push_back(i);
            while(n%i==0) n /= i;

        }
    }
    if(n>1) primes.push_back(n);
    //for(auto num: primes) cout<<num<<" "; cout<<endl;
    if(_sz(primes)==1) cout<<primes[0]<<endl;
    else cout<<1<<endl;

    return 0;

}
