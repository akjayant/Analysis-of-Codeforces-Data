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
    
    long long t;
    cin >> t;
    for (long long i = 0; i<t; i++) {
        int n;
        cin >> n;
        vector<long long> p(n);
        long long even = 0;
        long long odd = 0;
        for (long long i = 0; i<n; i++) {
            cin >> p[i];
            if (p[i]%2==0) even++;
            else odd++;
        }
        int m;
        cin >> m;
        vector<long long> q(m);
        long long evenq = 0;
        long long oddq = 0;
        for (long long i = 0; i<m; i++) {
            cin >> q[i];
            if (q[i]%2==0) evenq++;
            else oddq++;
        }
        long long ans = even*evenq + odd*oddq;
        cout << ans << endl;
    }
    
    


    return 0;
}