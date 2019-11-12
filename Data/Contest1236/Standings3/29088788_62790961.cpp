#include <iostream>
using namespace std;
typedef long long int lli;

lli n, m, ans, k = 1e9 + 7;

lli p(lli x, lli y){
    if(!y){
        return 1;
    }
    else{
        lli lol = p(x, y/2);

        return (((lol % k * lol % k) % k) * (y & 1 ? x : 1) % k) % k;
    }
}

int main(){
    cin >> n >> m;

    cout << p((k + p(2, m) - 1) % k, n) % k << '\n';
    return 0;
}
