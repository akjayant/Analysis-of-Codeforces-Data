#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int MAXN=3e3+1;
const int inf = MAXN;
vector<vector<int>> trans(MAXN, vector<int>(0));

int n;
vector<pair<int , int>> edges(0);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        vector<int> arr(0);
        for(int j=0;j<m;j++){
            int c;
            cin>>c;
            arr.push_back(c);
        }
        sort(arr.begin(), arr.end());
        int ans=1;
        for(int j=0;j<m;j++){
            ans=max(ans, min(arr[j], m-j));
        }
        cout<<ans<<endl;
    }
}