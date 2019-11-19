#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define mod 1000000007
#define INF 1000000000000000000

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;

    cin >> n >> k;

    ll arr[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, arr+n);

    int fw_id = 0;
    int bk_id = n-1;
    ll minm = -1;
    ll maxm = -1;

    ll ans = 0;

    for(int i = 0; i < n; i++){
        if(fw_id == n-1){
            break;
        }
        else if(bk_id == 0){
            break;
        }
        else if(fw_id >= bk_id){
            break;
        }
        else{
            ll diff1 = (fw_id+1)*(arr[fw_id+1] - arr[fw_id]);
            ll diff2 = (n-bk_id)*(arr[bk_id] - arr[bk_id-1]);

            if((fw_id+1) == (n-bk_id)){
                if((arr[fw_id+1] - arr[fw_id]) >= (arr[bk_id] - arr[bk_id-1])){
                    if(diff1 <= k){
                        k -= diff1;
                    }
                    else{
                        minm = k/(fw_id+1);
                        break;
                    }
                    fw_id++;
                }
                else{
                    if(diff2 <= k){
                        k -= diff2;
                    }
                    else{
                        maxm = k/(n-bk_id);
                        break;
                    }
                    bk_id--;
                }
            }

            else if((fw_id+1) > (n-bk_id)){
                if(diff2 <= k){
                    k -= diff2;
                }
                else{
                    maxm = k/(n-bk_id);
                    break;
                }
                bk_id--;
            }

            else{
                if(diff1 <= k){
                    k -= diff1;
                }
                else{
                    minm = k/(fw_id+1);
                    break;
                }
                fw_id++;
            }

        }
    }

    if(minm != -1){
        ans = (arr[bk_id] - (arr[fw_id] + minm));
        cout << ans << endl;
    }
    else if(maxm != -1){
        ans = ((arr[bk_id] - maxm) - arr[fw_id]);
        cout << ans << endl;
    }
    else{
        cout << 0 << endl;
    }

    return 0;
}