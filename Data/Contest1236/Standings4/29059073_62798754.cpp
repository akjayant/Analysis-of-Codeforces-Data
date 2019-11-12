#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=1e5+5, mod=1e9+7;

int a[305][305];

int main()
{
    int n;
    cin >> n;

    for(int i=0, k=1; i<n; i++) {
        for(int j=0; j<n; j++, k++) {
            if(i&1) a[n-1-j][i]=k;
            else a[j][i]=k;
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("%d ", a[i][j]);
        }
        puts("");
    }

}
