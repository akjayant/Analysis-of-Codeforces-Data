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

    while (q--) {
    	int n;
    	string s, t;

    	cin >> n >> s >> t;

    	vi diffs;
    	for (int i = 0; i < n; ++i) {
    		if (s[i] != t[i]) {
    			diffs.push_back(i);

    			if (diffs.size() > 2) break;
    		}
    	}

    	if (diffs.size() != 2) {
    		cout << "No\n";
    	} else {
    		if (s[diffs[0]] == s[diffs[1]] && t[diffs[1]] == t[diffs[0]]) {
    			cout << "Yes\n";
    		} else {
    			cout << "No\n";
    		}
    	}
    }

    return 0;
}
