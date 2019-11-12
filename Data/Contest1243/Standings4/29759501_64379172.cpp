#include <bits/stdc++.h>
#define P pair<char, char>
using namespace std;

vector<P> diff;

int main()
{
    int k;
    for( cin >> k; k--; ){
        int n;
        string s, t;
        diff.clear();
        cin >> n >> s >> t;
        for( int i = 0; i < n; i++ )
            if( s[i] != t[i] )
                diff.push_back(P(s[i], t[i]));
        string res = "No";
        if( diff.size() == 2 && diff[0].first == diff[1].first && diff[0].second == diff[1].second )
            res = "Yes";
        cout << res << endl;
    }

    return 0;
}