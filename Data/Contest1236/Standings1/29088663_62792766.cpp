#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 1e5+100;

int a[N];

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n;cin >> n;
    for(int i=0 ; i<n*n ; i++)
        a[i] = i+1;
    for(int i=0 ; i<n*n ; i+=n)
        if((i/n) >= n/2)
            reverse(a+i, a+i+n);
    for(int i=0 ; i<n ; i++){
        for(int s=i ; s<n*n ; s+=n)
            cout << a[s] << " ";
        cout << "\n";
    }
}

