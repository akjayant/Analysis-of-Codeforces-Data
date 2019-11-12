#include <bits/stdc++.h>
#define P pair<int, int>
using namespace std;

int main()
{
    int k;
    for( cin >> k; k--; ){
        int n;
        string s, t;
        vector<P> res;
        cin >> n >> s >> t;
        bool failed = false;
        for( int i = 0; i < n && !failed; i++ )   
            if(s[i] != t[i]){
                bool can = false;
                for( int j = i + 1; j < n; j++ )
                    if( s[j] == s[i] ){
                        can = true;
                        res.push_back(P(j, i));
                        swap(s[j], t[i]);
                        break;
                    }
                    else if( t[j] == s[i] ){
                        can = true;
                        res.push_back(P(j, j));
                        swap(s[j], t[j]);
                        res.push_back(P(j, i));
                        swap(s[j], t[i]);
                        break;
                    }
                if(!can)
                    failed = true;
            } 
        if( failed )
            cout << "No" << endl;
        else{
            cout << "Yes" << endl;
            cout << res.size() << endl;
            for( int i = 0; i < res.size(); i++ )
                cout << res[i].first + 1 << ' ' << res[i].second + 1 << endl;
        }
    }

    return 0;
}