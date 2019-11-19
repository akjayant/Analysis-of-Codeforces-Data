#include <bits/stdc++.h>

using namespace std;

int main () {
    long long int q;
    cin >> q;
    while(q--) {
        long long int n;
        string s;
        cin >> n >> s;
        long long int f1 = -1, f2=-1;
        for(int i = 0 ; i < s.size() ; i++ ) {
            if(s[i]=='1') {
                f1=i;
                break;
            }
        }
        for(int i = s.size()-1; i >= 0 ; i-- ) {
            if(s[i]=='1') {
                f2=i;
                break;
            }
        }
        if(f1==-1) {
            cout << n;
        }
        else {
            cout << max(2*(n-f1),2*(f2+1));
        }
        cout << '\n';
    }
}

