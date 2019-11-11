#include<bits/stdc++.h>
typedef long long int ll;

using namespace std;

const int MAXN = 2e5 + 123;
const ll MOD = 1e9 + 7;
int l[MAXN], r[MAXN], ch[MAXN];

int main(){
    int t;
    cin >> t;
    while(t){
        int a, b;
        cin >> a >> b;
        if(__gcd(a, b) == 1)
            cout << "Finite\n";
        else
            cout << "Infinite\n";
        t --;
    }
}
