#include <bits/stdc++.h>
#define ll long long int
#define Zeroes ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define Auto int main()
#define Accepted {return 0;}
int const Max = 1e5 + 7;
int const MOD = 1e9 + 7;

using namespace std;

ll n;
ll a[400][400];
Auto {
    Zeroes
    cin >> n;
    ll x = n*n;
    bool f = true;
    a[0][0]= x;
    for(ll i = 1 ; i < n ; i++){
        if(f){
            x = x - n*2 + 1;
            f = !f;
        }else{
            x--;
            f = !f;
        }

        a[0][i] = x;
    }
    f = false;
    for(ll i = 1 ; i < n ; i++){
        for(ll j = 0 ; j < n ; j++){
            if(f){
                a[i][j] = a[i - 1][j] + 1;
                f = !f;
            }else{
                a[i][j] = a[i - 1][j] - 1;
                f = !f;
            }
        }
        if(n%2)
            f = !f;
    }

    for(ll i = 0 ; i < n ; i++){
        for(ll j = 0 ; j < n ; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

    Accepted
}
