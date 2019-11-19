#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAX 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ub upper_bound
#define lb lower_bound
#define zoom ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    zoom;
    ll n, i;
    cin >> n;
    vector<ll> A(n);
    for(i = 0; i < n; i += 1)
    	cin >> A[i];
    sort(A.begin(), A.end());
    ll one = 0, two = 0;
    for(i = 0; i < (n / 2); i += 1) {
    	one += A[i];
    	two += A[n - i - 1];
    }
    if(n % 2 == 1)
    	two += A[n / 2];
    cout << one * one + two * two;
    return 0;
}