#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    long long n;
    cin >> n;
    if(n == 1){
        cout << 1;
        return 0;
    }
    vector<long long> g;
    for(long long i = 2 ; i <= sqrt(n) ; i += 1){
        while(n%i == 0){
            n /= i;
            g.push_back(i);
        }
    }
    if(n > 1){
        g.push_back(n);
    }
    if(g[0] == g[g.size()-1]){
        cout << g[0];
    }else{
        cout << 1;
    }
}