#include <bits/stdc++.h>
using namespace std;

int T, N, M;

int main(){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
// #ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
// #endif // ONLINE_JUDGE
    
cin >> T;
while(T--){
    long long temp1 = 0;
    long long temp2 = 0;
    long long num;
    long long ans = 0;
    cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> num;
        if(num%2==0) temp1++;
        else temp2++;
    }
    cin >> M;
    for (int i = 0; i < M; ++i){
        cin >> num;
        if(num%2==0) ans+=temp1;
        else ans+=temp2;
    }

    cout << ans << '\n';

}


return 0;
}