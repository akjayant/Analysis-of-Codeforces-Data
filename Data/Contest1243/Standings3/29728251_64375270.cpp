#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
#include <utility>
#include <iterator>

#define mod 1000000007

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    int k;
    cin >> k;
    for (int i = 0; i<k; i++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int j = 0; j<n; j++) {
            cin >> a[j];
        }
        sort(a.begin(), a.end());
        int ans = 0;
        for (int j = n-1; j>=0; j--) {
            if (ans+1 > a[j]) break;
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}