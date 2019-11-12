#include <bits/stdc++.h>
using namespace std;

#define SIZE 310

int arr[SIZE][SIZE];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int num, pt = 1; cin >> num;
    for (int i = 0; i < num; i++) {
        if (i & 1) {
            for (int j = num - 1; j >= 0; j--)
                arr[j][i] = pt++;
        } else {
            for (int j = 0; j < num; j++)
                arr[j][i] = pt++;
        }
    }

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++)
            cout << arr[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}