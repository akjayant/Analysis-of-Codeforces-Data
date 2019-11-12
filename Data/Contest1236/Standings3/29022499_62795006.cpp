#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxN = 1e3+10;

vector<vector<int> > v(maxN);
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n; cin >> n;
    int k = n / 2; 
    int cnt = 1;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < n; j++) {
            v[j].push_back(cnt);
            cnt++;
        } 
    }
    int Cnt = n*n;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < n; j++) {
            v[j].push_back(Cnt);
            Cnt--;
        } 
    }
    for(int i = 0; i < n; i++) {
        v[i].push_back(cnt);
        cnt++;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << v[i][j] << " "; 
        }
        cout << endl;
    }

    return 0;
}
