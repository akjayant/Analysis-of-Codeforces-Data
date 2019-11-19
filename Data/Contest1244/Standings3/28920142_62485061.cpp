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

    ll n, p, d, w;

    cin >> n >> p >> w >> d;

    bool flag = true;

    ll i;

    for(i = 0; i < d; i++){
        if((p - (i*w)) >= 0){
            if(((p - (i*w))%d) == 0){

                ll j = (p - (i*w))/d;

                if((i+j) <= n){
                    cout << i << " " << j << " " << (n-(i+j)) << endl;
                    break;
                }
                else{
                    ll num = ((p-(i*w))/d)/w;

                    ll j = (i+(num*d));

                    ll ot_num = ((p-(i*w))/d) - (num*w);

                    if((ot_num+j)<=n){
                        cout << j << " " << ot_num << " " << (n-(ot_num+j)) << endl;
                        break;
                    }
                }
            }
        }
        else{
            cout << -1 << endl;
            break; 
        }
    }

    if(i == d){
        cout << -1 << endl;
    }

    return 0;
}