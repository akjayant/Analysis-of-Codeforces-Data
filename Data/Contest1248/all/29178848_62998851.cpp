#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;

int N, M;
ll arr[100001][2];
ll ans;

int main(){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE
    
cin >> N >> M;

arr[1][0] = 0;
arr[1][1] = 2;
arr[2][0] = 2;
arr[2][1] = 2;
for (int i = 3; i <= max(N,M); ++i){
    arr[i][0] = arr[i-1][1];
    arr[i][1] = arr[i-1][0]+arr[i-1][1];
    arr[i][0]%=MOD;
    arr[i][1]%=MOD;
}

ans = (arr[M][1]+arr[M][0]+arr[N][1]+arr[N][0]-2)%MOD;
cout << ans << '\n';



return 0;
}