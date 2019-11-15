#include <bits/stdc++.h>
using namespace std;
const int maxn = 305;
vector<int> ans[maxn];
int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(i % 2 == 1){
            for(int j = 1; j <= n; j++){
                ans[j].push_back(++cnt);
            }
        }
        else{
            for(int j = n; j >= 1; j--){
                ans[j].push_back(++cnt);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(auto it: ans[i]){
            cout << it << " ";
        }
        cout << endl;
    }
}
