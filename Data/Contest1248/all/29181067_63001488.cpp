/*
g++ -std=c++11 code.cpp; cat inp.txt | ./a.out
*/

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back

typedef long long int ll;

ll arr[100010];

ll p = 1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    if (m > n) swap(n,m);

    arr[1] = 2;
    arr[2] = 4;

    for(int i=3; i<=n; i++)
        arr[i] = (arr[i-1]+arr[i-2])%p;

    ll diff = arr[m] - arr[1];

    for(int i=1; i<=n; i++)
        arr[i] = (arr[i]+diff)%p;
    
    cout << arr[n] << endl;
}