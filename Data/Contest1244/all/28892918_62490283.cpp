#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; long long k;
    cin >> n >> k;

    int a[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    sort(a, a + n);

    int l = 0, r = n - 1;
    while(true){
        while(a[l] == a[l + 1] && l + 1 < r){
            ++l;
        }
        while(a[r] == a[r - 1] && r - 1 > l){
            --r;
        }
        int dl = l + 1, dr = n - r;
        if(dl <= dr){
            long long x = a[l + 1] - a[l];
            long long d = k / dl;
            if(d < x){
                a[l] += d;
                break;
            }
            else{
                k -= x * dl;
                a[l] += x;
            }
        }
        else{
            long long x = a[r] - a[r - 1];
            long long d = k / dr;
            if(d < x){
                a[r] -= d;
                break;
            }
            else{
                k -= x * dr;
                a[r] -= x;
            }
        }
        if(r - l == 1 && a[l] == a[r]){
            break;
        }
    }

    cout << a[r] - a[l];
}
