#include <iostream>
#include <vector>
using namespace std;

int main() {
    int k;
    cin >> k;
    
    while (k--) {
        string a, b;
        vector<int> v(26*26);
        
        int n;
        cin >> n;
        cin >> a >> b;
        
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) continue;
            int h = (a[i]-'a')*26 + (b[i]-'a');
            // cout << h << endl;
            v[h]++;
        }
        
        int cnt2 = 0;
        int cntAny = 0;
        for (int i = 0; i < 26*26; i++) {
            if (v[i] == 2) cnt2++;
            if (v[i] != 0) cntAny++;
        }
        
        // cout << cnt2 << ' ' << cntAny << endl;
        
        if (cnt2 == 1 && cntAny == 1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
