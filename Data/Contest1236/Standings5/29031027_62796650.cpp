#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
#include <cmath>

#define pii pair<int, int>
#define all(a) a.begin(),a.end()
#define y1 erd
#define int long long

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

typedef long long ll;

using namespace std;

const int M = 1e9 + 7;

int fastpow(int a, int b){
    if(b == 0)
        return 1;
    if(b % 2){
        return (a * fastpow(a, b - 1)) % M;
    }
    else{
        int k = fastpow(a, b / 2) % M;
        return (k * k) % M;
    }
}

int n;

vector<int> a[330];
int32_t main()
{
    cin >> n;
    int k = 1;
    while(k <= n * n){
        for(int j = 1; j <= n; j++){
            a[j].push_back(k);
            k++;
        }
        if(k > n * n)
            break;
        for(int j = n; j >= 1; j--){
            a[j].push_back(k);
            k++;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j : a[i])
            cout << j << " ";
        cout << endl;
    }
}
