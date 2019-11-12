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
    for (int j = 0; j<k; j++) {
        int n; 
        cin >> n;
        string s, t;
        cin >> s;
        cin >> t;
        int ind = 0;
        for (int i = 0; i<n; i++) {
            if (s[i] != t[i]) {
                ind = i;
                break;
            }
        }
        int ind2 = -1;
        for (int i = ind+1; i<n; i++) {
            if (s[i] != t[i]) {
                ind2 = i;
                break;
            }
        }
        if (ind2 == -1) {
            cout <<"No"<<endl;
            continue;
        }
        int found = 0;
        for (int i = ind2+1; i<n; i++) {
            if (s[i]!=t[i]) {
                cout <<"No"<<endl;
                found = 1;
                break;
            }
        }
        if (found) continue;
        if (s[ind] == s[ind2] && t[ind] == t[ind2]) {
            cout << "Yes" << endl;
        }
        else {
            cout <<"No" << endl;
        }
    }
    return 0;
}