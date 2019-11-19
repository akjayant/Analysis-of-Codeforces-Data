#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll n, sum, a[1111111], x;

int main(){
    
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) sum += a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n/2; i++) x += a[i];
    cout << x*x + (sum - x)*(sum - x);
    
    return 0;
}
