#include <bits/stdc++.h>
using namespace std;
#define LL long long
 

 
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    int q = 1;
    cin >> q;
    while( q-- ) {
        int n ;
        cin >> n;
        string s, t;
        cin >> s >> t;
        vector<pair<int,int> > v;
        int a[27] = {0};
        for ( int i = 0; i < n; i++ ) {
            a[s[i] - 'a']++;
            a[t[i] - 'a']++;
        }
        int f = 0;
        for ( int i = 0; i < 26; i++ ) {
            if( a[i] & 1 ) {
                f = 1;
                break;
            }
        }
        if( f ) {
            cout << "No" << "\n";
            continue;
        }
        cout << "Yes" << "\n";
        for ( int i = 0; i < n; i++ ) {
            if( s[i] == t[i] ) {
                continue;
            }
            int x = -1;
            for(int j = i + 1; j < n ; j++ ){
                if( s[i] == s[j] ){
                    x = j;
                    break;
                }
            }
            if( x == -1 ) {
                for(int j = i + 1; j < n ; j++ ){
                    if( s[i] == t[j] ){
                        x = n - 1;
                        v.push_back( { n - 1, j });
                        int t1 = s[n - 1];
                        s[n - 1] = t[j];
                        t[j] = t1;
                        break;
                    }
                }
            }
            v.push_back( { x, i });
            int t1 = s[x];
            s[x] = t[i];
            t[i] = t1;
        }
        cout << v.size() << "\n";
        for(int i = 0 ; i < v.size() ; i++) {
            cout << v[i].first + 1 << " " << v[i].second + 1 << "\n";
        }
    }
    return 0;
}