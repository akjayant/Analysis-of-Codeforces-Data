#include <iostream>
using namespace std;

int main() {
	long long games, points, pWin, pDraw;
	cin >> games >> points >> pWin >> pDraw;

	long long targetMod = points % pWin;
	long long draws = 0;
	if (targetMod != 0) {
		long long curMod = 0;
		do {
			curMod = (curMod + pDraw) % pWin;
			draws++;
		}
		while (curMod != targetMod && curMod != 0);
		if (curMod != targetMod) {
			cout << -1 << "\n";
			return 0;
		}
	}

	long long wins = (points - draws * pDraw) / pWin;
	if (wins >= 0 && wins + draws <= games) {
		cout << wins << " " << draws << " " << games - wins - draws << "\n";
	}
	else {
		cout << -1 << "\n";
	}

	return 0;
}