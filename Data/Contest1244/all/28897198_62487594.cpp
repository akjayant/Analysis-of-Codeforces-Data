#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1e6 + 5;
long long a[maxn];

int main() {
    long long n, k;
    cin >> n >> k;
    k -= (n+1)*n/2;
    if(k < 0) cout << -1 << endl;
    else {
        for(int i = 1; i <= n; i++) a[i] = i;
        for(long long i = 1, j = n; i < j;) {
            long long ex = j - i;
            if(ex <= k) {
                k -= ex;
                a[i] ^= a[j];
                a[j] ^= a[i];
                a[i] ^= a[j];
                i++, j--;
            } else i++;
        }
        long long sum = 0;
        for(long long i = 1; i <= n; i++) sum += max(i, a[i]);
        cout << sum << endl;
        for(int i = 1; i <= n; i++) cout << i << " ";
        cout << endl;
        for(int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}