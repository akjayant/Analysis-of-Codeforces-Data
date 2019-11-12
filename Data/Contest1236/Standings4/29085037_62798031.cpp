#include <bits/stdc++.h>
using namespace std;

int main () {
        int n; cin >> n;
        /*
        long long Sum = (pow(1ll*n,4)-pow(1ll*n,3))/2;
        long long gr = n * (n-1) / 2;
        cout << "Sum = " << Sum << ", group = " << gr << endl;
        cout << 1.0 * Sum / gr << endl;
        */
        vector <int> ans[n];
        for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                        if (j%2) {
                                ans[i].push_back((j+1)*n-i);
                        } else {
                                ans[i].push_back(j*n+i+1);
                        }
                }
        }
        for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) printf("%d%c",ans[i][j]," \n"[j+1==n]);
        }
        /*
        for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                        if (i == j) continue;
                        int res = 0;
                        for (int a = 0; a < n; ++a) {
                                for (int b = 0; b < n; ++b) {
                                        if (ans[i][a] > ans[j][b]) ++res;       
                                }
                        }
                        printf ("from %d to %d  = %d\n",i+1,j+1,res);
                }
        }
        */
        return 0;
}