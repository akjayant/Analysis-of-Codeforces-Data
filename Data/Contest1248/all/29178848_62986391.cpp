#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> arr;
long long ans;
long long temp1, temp2;

int main(){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE
    
cin >> N;

for (int i = 0; i < N; ++i){
    int temp;
    cin >> temp;
    arr.push_back(temp);
}

sort(arr.begin(),arr.end());
int SS = arr.size();

for (int i = 0; i < SS/2; ++i){
    temp1+=arr[i];
}
for (int i = SS/2; i < SS; ++i){
    temp2+=arr[i];
}

ans = temp1*temp1 + temp2*temp2;

cout << ans << '\n';


return 0;
}