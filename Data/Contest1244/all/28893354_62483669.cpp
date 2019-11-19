#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;
const long long MOD = 1e9 + 7;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    
    while (t--) {
        
        long long n, k;
        cin>>n>>k;
        
        long long a[n];
        for (int i=0;i<n;i++)
            cin>>a[i];
        
        sort(a, a + n);
        
        long long x = 0, y = n - 1, l = 1, r = 1, d;
        while (x < y and a[x] < a[y]) {
            if (l < r) {
                while (a[x] == a[x + 1] and x < y) {
                    x++;
                    l++;
                }
                
                d = a[x + 1] - a[x];
                a[x] += min(d, k / l);
                k -= (l * min(d, k / l));
            }
            else {
                while (a[y] == a[y - 1] and x < y) {
                    y--;
                    r++;
                }
                
                d = a[y] - a[y - 1];
                a[y] -= min(d, k / r);
                k -= (r * min(d, k / r));
            }
            
            if (k == 0 or k < min(l, r))
                break;
        }
        
        cout<<(a[y] - a[x])<<endl;
    }
	
	return 0;
}
