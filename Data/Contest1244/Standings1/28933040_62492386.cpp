#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    map<int, int> arr;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr[x]++;
    }
    while(k > 0){
        /*cout << "cur state: k = " << k << ", arr = ";
        for(auto &kv : arr){
            cout << "{" << kv.first << ", " << kv.second << "}, ";
        }
        cout << endl;*/
        if(arr.begin()->first == arr.rbegin()->first)
            break;
        if(arr.begin()->second < arr.rbegin()->second){
            if(arr.begin()->second > k)
                break;
            long long old_min = arr.begin()->first;
            long long old_min_cnt = arr.begin()->second;
            long long diff = (++arr.begin())->first - arr.begin()->first;
            int plus_cnt;
            if(old_min_cnt * diff <= k)
                plus_cnt = diff;
            else
                plus_cnt = k / old_min_cnt;
            k -= plus_cnt * old_min_cnt;
            arr.erase(arr.begin());
            arr[old_min + plus_cnt] += old_min_cnt;
        }
        else{
            if(arr.rbegin()->second > k)
                break;
            long long old_min = arr.rbegin()->first;
            long long old_min_cnt = arr.rbegin()->second;
            long long diff = -(++arr.rbegin())->first + arr.rbegin()->first;
            int plus_cnt;
            if(old_min_cnt * diff <= k)
                plus_cnt = diff;
            else
                plus_cnt = k / old_min_cnt;
            k -= plus_cnt * old_min_cnt;
            arr.erase((--arr.end()));
            arr[old_min - plus_cnt] += old_min_cnt;
        }
    }
    cout << arr.rbegin()->first - arr.begin()->first;
    return 0;
}
