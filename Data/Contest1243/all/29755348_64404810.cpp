#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> graph;
typedef long long ll;

#define F first
#define S second

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int q;

    cin >> q;

    vector<ii> swaps;
    while (q--) {
    	int n;
    	string s, t;
        bool good = true;

    	cin >> n >> s >> t;

    	vi diffs;
        vector<set<int> > cnts(30, set<int>()), cntt(30, set<int>());;

        for (int i = 0; i < n; ++i) cnts[s[i] - 'a'].insert(i), cntt[t[i] - 'a'].insert(i);

        for (int i = 0; i < 30; ++i) {
            if ((cnts[i].size() + cntt[i].size()) % 2) {
                good = false;
                cout << "No\n";
                break;
            }
        }

        if (!good) continue;

        cout << "Yes\n";

        swaps.clear();
        for (int i = 0; i < n; ++i)
        {
            cnts[s[i]-'a'].erase(i);
            cntt[t[i]-'a'].erase(i);

            if (s[i] == t[i]) continue;

            int cnta = cnts[s[i]-'a'].size();
            int cntb = cntt[t[i]-'a'].size();

            if (cnta == 0 || cntb == 0) {
                swaps.push_back({i + 1, i + 1});

                swap(s[i], t[i]);

                cnta = cnts[s[i]-'a'].size();
                cntb = cntt[t[i]-'a'].size();
            }

            if (cnta >= cntb) {
                int first = *cnts[s[i]-'a'].begin();

                swaps.push_back({first + 1, i + 1});

                cnts[t[i]-'a'].insert(first);
                cnts[s[i]-'a'].erase(first);

                swap(s[first], t[i]);
            } else if (cntb > cnta) {
                int first = *cntt[t[i]-'a'].begin();

                swaps.push_back({i + 1, first + 1});

                cntt[s[i]-'a'].insert(first);
                cntt[t[i]-'a'].erase(first);

                swap(s[i], t[first]);
            }
        }

        cout << swaps.size() << '\n';
        for (auto x: swaps) cout << x.F << ' ' << x.S << '\n';
    }

    return 0;
}
