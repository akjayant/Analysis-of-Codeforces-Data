#include <bits/stdc++.h>
using namespace std;
typedef pair< int, int > ii;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; 
    cin >> t;
    while( t-- ) {
        int n;
        string s, t;
        cin >> n;
        cin >> s >> t;
        int v[26];
        memset( v, 0, sizeof v );
        for( int i = 0; i < n; i++ ) {
            v[s[i]-'a']++;
            v[t[i]-'a']++;
        }
        bool ans = true;
        for( int i = 0; i < 26; i++ ) {
            if( v[i]&1 ) {
                ans = false;
                break;
            }
        }
        if( ans ) {
            cout << "Yes\n";
            vector< ii > answer;
            for( int i = 0; i < n; i++) {
                if( s[i] != t[i] ) {
                    for( int j = i+1; j < n; j++ ) {
                        if( s[i] == s[j] ) {
                            answer.push_back( ii(j+1, i+1) );
                            swap( s[j], t[i] );
                            break;
                        }
                        if( s[i] == t[j] ) {
                            answer.push_back( ii(i+2, j+1) );
                            answer.push_back( ii(i+2, i+1) );
                            swap( s[i+1], t[j] );
                            swap( s[i+1], t[i] );
                            break;
                        }
                    }
                }
            }
            cout << answer.size() << '\n';
            for( ii &i: answer ) {
                cout << i.first << ' ' << i.second << '\n';
            }
        } else {
            cout << "No\n";
        }
    }
    return 0;
}