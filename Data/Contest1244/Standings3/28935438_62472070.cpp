#include <iostream>
using namespace std;

int main() {
	int lec, prac, numPen, numPencil, caseSize;
	int q;
	cin >> q;
	while (q--) {
		cin >> lec >> prac >> numPen >> numPencil >> caseSize;
		int x = (lec - 1) / numPen + 1;
		int y = (prac - 1) / numPencil + 1;
		if (x + y > caseSize) {
			cout << -1 << "\n";
		}
		else {
			cout << x << " " << y << "\n";
		}
	}
	return 0;
}