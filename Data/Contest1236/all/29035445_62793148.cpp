#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector < int > ans[n];

    int sch = 0;
    for(int i = 0; i < n; ++i){
        if(i % 2 == 0){
            for(int j = 0; j < n; ++j){
                ++sch;
                ans[j].push_back(sch);
            }
        }
        else{
            for(int j = n - 1; j >= 0; --j){
                ++sch;
                ans[j].push_back(sch);
            }
        }
    }

    for(int i = 0; i < n; ++i){
        for(int to : ans[i]){
            cout << to << ' ';
        }
        cout << endl;
    }
}
