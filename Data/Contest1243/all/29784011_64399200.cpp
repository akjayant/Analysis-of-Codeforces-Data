#include <bits/stdc++.h>
#define int long long
#define bp __builtin_popcountll
#define pb push_back
#define in(s) freopen(s, "r", stdin);
#define out(s) freopen(s, "w", stdout);
#define inout(s, end1, end2) freopen((string(s) + "." + end1).c_str(), "r", stdin),\
		freopen((string(s) + "." + end2).c_str(), "w", stdout);
#define fi first
#define se second
#define bw(i, r, l) for (int i = r - 1; i >= l; i--)
#define fw(i, l, r) for (int i = l; i < r; i++)
#define fa(i, x) for (auto i: x)
using namespace std;
const int mod = 1e9 + 7, inf = 1061109567;
const long long infll = 4557430888798830399;
const int N = 16, MASK = (1 << 15) + 5;
typedef pair<int, int> ii;
int k, avg = 0, sumBox[N];
vector<ii> ans[MASK];
bool goodMask[MASK]; //If just within this subset we can make them all good.
bool dp[MASK];
int sub[MASK];
int val[N], transfer[N];
vector<int> boxes[N];
map<int, int> boxID;
void getAns(int mask) {
	if (!goodMask[mask]) {
		int tmp = sub[mask];
		getAns(tmp);
		getAns(mask ^ tmp);
	} else {
		//Answer is stored in the form of {weight, box ID}
//		cout << "mask = " << mask << "\n";
		fw (j, 0, ans[mask].size()) {
//			cout << ans[mask][j].fi << " " << ans[mask][j].se << "\n";
			int nxtBox = j - 1;
			if (nxtBox < 0) nxtBox += ans[mask].size();
			nxtBox = ans[mask][nxtBox].se;
			int curBox = ans[mask][j].se, lol = ans[mask][j].fi;
			val[curBox] = lol;
			transfer[curBox] = nxtBox;
		}
	}
}
signed main() {
	#ifdef BLU
	in("blu.inp");
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> k;
	fw (i, 0, k) {
		int x;
		cin >> x;
		boxes[i].resize(x);
		fw (j, 0, x) {
			cin >> boxes[i][j];
			avg += boxes[i][j];
			boxID[boxes[i][j]] = i;
			sumBox[i] += boxes[i][j];
		}
	}
	if (avg % k) {
		cout << "No";
		return 0;
	}
	avg /= k;
	fw (i, 0, k) {
		fa (j, boxes[i]) {
//			cout << "delete  " << j << " at box " << i << "\n";
			//If we delete this item what is the replacement until we reach the box again.
			int msk = 0;
			int curBox = i, lstVal = j;
			bool firstTurn = 1, bad = 0;
			vector<ii> tempo;
			while (curBox != i || firstTurn) {
				if (msk & (1 << curBox)) {
					bad = 1;
					break;
				}
				firstTurn = 0;
				msk |= (1 << curBox);
				
				tempo.pb(ii(lstVal, curBox));
				
				int neededVal = avg - sumBox[curBox] + lstVal;
//				cout << "neededVal at " << curBox << " is " << neededVal << "\n"; 
				if (!boxID.count(neededVal)) {
					bad = 1;
					break;
				}
				
				curBox = boxID[neededVal];
				lstVal = neededVal;
			}
			if (!bad) {
				if (lstVal == j) {
					if (!goodMask[msk]) {
						goodMask[msk] = 1;
						ans[msk] = tempo;
					}
				}
			}
		}
	}
	fw (i, 0, (1 << k)) {
		if (goodMask[i]) dp[i] = 1;
		else {
			for (int submask = i; submask > 0; submask = (submask - 1) & i) {
//				cout << "i = " << i << " submask = " << submask << " other = " << (i ^ submask) << "\n";
				if (dp[submask] && dp[i ^ submask]) {
					dp[i] = 1;
					sub[i] = submask;
					break;
				}
			}
		}
	}
	if (!dp[(1 << k) - 1]) cout << "No";
	else {
		cout << "Yes\n";
		getAns((1 << k) - 1);
		fw (i, 0, k) cout << val[i] << " " << transfer[i] + 1 << "\n";
	} 
	return 0;
}