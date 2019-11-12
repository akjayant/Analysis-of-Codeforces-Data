#include<bits/stdc++.h>
#define int long long
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin>>N;
    vector<vector<int>> a(N);
    for(int i=0;i<N*N;i++){
        if((i/N)%2==0){
            a[i%N].push_back(i+1);
        }else{
            a[N-1-i%N].push_back(i+1);
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(j) cout<<' ';
            cout<<a[i][j];
        }
        cout<<endl;
    }
    return 0;
}