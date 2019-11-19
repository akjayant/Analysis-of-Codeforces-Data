#include <iostream>

using namespace std;

using LL = long long;

void one_test() {
        LL e1, e2, o1, o2;
        e1 = e2 = o1 = o2 = 0;
        int N;
        int n;
        cin >> N;
        for (int i = 0; i < N; i++) {
                cin >> n;
                if (n & 1) {
                        o1 ++;
                } else {
                        e1 ++;
                }
        }
        cin >> N;
        for (int i = 0; i < N; i++) {
                cin >> n;
                if (n & 1) {
                        o2 ++;
                } else {
                        e2 ++;
                }
        }
        cout << e2 * e1 + o2 * o1 << endl;
}

int main() {
        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
                one_test();
        }
        return 0;
}