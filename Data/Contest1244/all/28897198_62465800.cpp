#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int pen = a / c + (a % c != 0);
        int pencils = b / d + (b % d != 0);
        if(pen + pencils > k) cout << -1 << endl;
        else cout << pen << " " << pencils << endl;
    }
    return 0;
}