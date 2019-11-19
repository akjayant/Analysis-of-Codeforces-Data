#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i ++){
        long long cnt_0 = 0, cnt_1 = 0, cnt_0_1 = 0, cnt_1_1 = 0;
        int n;
        cin >> n;
        for(int j = 0; j < n; j ++){
            int a;
            cin >> a;
            if(a % 2 == 0){
                cnt_0 ++;
            }
            else{
                cnt_1 ++;
            }
        }
        int m;
        cin >> m;
        for(int j = 0; j < m; j ++){
            int a;
            cin >> a;
            if(a % 2 == 0){
                cnt_0_1 ++;
            }
            else{
                cnt_1_1++;
            }
        }
        cout << cnt_0 * cnt_0_1 + cnt_1 * cnt_1_1 << '\n';
    }
}
