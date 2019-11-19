#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
#include <utility>
#include <iterator>

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i<n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    long long sum1 = 0;
    long long sum2 = 0;
    for (long long i = 0; i<n; i++) {
        if (i<n/2) {
            sum1 += a[i];
        }
        else sum2 += a[i];
    }
    long long ans = sum1*sum1+sum2*sum2;
    cout << ans;
    


    return 0;
}