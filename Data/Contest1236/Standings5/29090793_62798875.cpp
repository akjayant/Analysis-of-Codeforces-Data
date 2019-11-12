#include <iostream>
using namespace std;
int a[512][512];
int main () {
    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (i%2==0) a[j][i]=i*n+j+1;
            else a[j][i]=i*n+n-j;
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
