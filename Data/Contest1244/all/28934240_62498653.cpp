#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll n,p,w,d;

// true : nice
// false : you need to win more
bool works(ll numWins) {
	ll score = numWins * w;
	ll scoreLeft = p-score;
	ll y = scoreLeft / d;
	ll z = n - numWins - y;
	return (z >= 0);
}

void printStuff(ll numWins) {
	ll score = numWins * w;
	ll scoreLeft = p-score;
	ll y = scoreLeft / d;
	ll z = n - numWins - y;
	cout << numWins << " " << y << " " << z << endl;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

	cin >> n >> p >> w >> d;

	ll lowestNumWins = -1;
	rep(i, 0, 1000000) {
		ll score = w*i;
		ll scoreLeft = p-score;
		if (scoreLeft < 0) {
			break;
		}
		if (scoreLeft % d == 0) {
			lowestNumWins = i;
			break;
		}
	}
	ll highestNumWins = -1;
	rep(i, 0, 1000000) {
		ll score = d*i;
		ll scoreLeft = p-score;
		if (scoreLeft < 0) {
			break;
		}
		if (scoreLeft % w == 0) {
			highestNumWins = scoreLeft / w;
			break;
		}
	}
	if (lowestNumWins == -1 || highestNumWins == -1) {
		cout << -1 << endl;
		return 0;
	}

	ll change = d;
	rep(i, 1, d) {
		if ((w*i) % d == 0) {
			change = i;
			break;
		}
	}

	ll low = lowestNumWins;
	ll high = highestNumWins;
	while (low <= high) {
		ll dist = (high - low) / change;
		ll mid = low + dist/2 * change;
		if (works(mid)) {
			printStuff(mid);
			return 0;
		}
		low = mid + change;
	}
	cout << -1 << endl;
}
