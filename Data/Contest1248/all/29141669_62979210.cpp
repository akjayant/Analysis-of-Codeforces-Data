#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for(int ti=0;ti<t;ti++) {
        int n;
        cin >> n;
        long long evens1 = 0;
        long long odds1=0;
        for(int i=0;i<n;i++) {
            int k;
            cin >> k;
            if(k%2==0)
                evens1++;
            else
                odds1++;
        }
        int m;
        cin >> m;
        long long odds2=0;
        long long evens2=0;
        for(int i=0;i<m;i++) {
            int k;
            cin >> k;
            if(k%2==0)
                evens2++;
            else
                odds2++;
        }
        cout << odds2*odds1 + evens2*evens1 << endl;

    }
    return 0;
}
