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
    for (int p = 0; p<k; p++) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        vector< pair<int, int> > answers;
        int i = 0;
        while (true) {
            while (i<n && s[i] == t[i]) {
                i++;
            }
            if (i >= n) break;
            // at i - not equal
            int found = 0;
            for (int j = i+1; j<n; j++) {
                if (s[j] == s[i]) {
                    found = 1;
                    answers.push_back(make_pair(j+1, i+1));
                    s[j] = t[i];
                    break;
                }
            }
            if (!found) {
                for (int j = i+1; j<n; j++) {
                    if (t[j] == s[i]) {
                        found = 1;
                        answers.push_back(make_pair(i+2, j+1));
                        answers.push_back(make_pair(i+2, i+1));
                        t[j] = s[i+1];
                        s[i+1] = t[i];
                        break;
                    }
                }
            }
            if (!found) {
                cout <<"No"<< endl;
                i = n+5;                
            }
            else i++;
        }
        if (i != n+5) {
            cout << "Yes" << endl;
            cout << answers.size() << endl;
            for (auto x:answers) {
                cout << x.first << " " << x.second << endl;
            }
        }

    }
    return 0;
}