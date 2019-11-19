#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
#include <iomanip>

#define ll long long
#define vll vector<long long>

#define fori(a, b) for(ll i = a;i <= b;i++)
#define forj(a, b) for(ll j = a;j <= b;j++)
#define fork(a, b) for(ll k = a;k <= b;k++)

#define input2(a, b) cin >> a >> b;
#define input(a) cin >> a;

#define max(a,b) (a<b?b:a)
#define min(a,b) (a>b?b:a)

using namespace std;

ll MOD = 1;
unsigned ll sum = 0;

ll fac[31];
ll temp12[10];
ll power(ll x, ll n, ll mod){
    if(n == 0){
        return 1;
    }
    ll temp = power(x, n/2, mod);
    if(n % 2 == 1){
        return (x*temp*temp)%mod;
    } else {
        return (temp*temp)%mod;
    }
}
ll abs(ll a, ll b){
    if(a > b){
        return a - b;
    }
    return b - a;
}
ll perm(ll arr[]){
    ll sum1 = 0;
    fori(0, 9){
        sum1 += arr[i];
    }
    ll sol = 1;
    sol *= fac[sum1];
    fori(0, 9){
        sol /= fac[arr[i]];
    }
    return sol;
}
void solve(ll arr[], ll chosen){
    if(chosen == 10){
        //cout << "!!!!" << arr[0] << " " << arr[1] << " " << arr[9] << endl;
        sum += perm(arr);
        //cout << "sum zvysene o " << perm(arr) << endl;
        if(arr[0] > 0){
            arr[0]--;
            sum -= perm(arr);
            //cout << "sum znizene o " << perm(arr) << endl;
            arr[0]++;
        }
        return;
    } else {
        if(arr[chosen] == 0){
            //cout << "1   " << arr[chosen] << "  " << chosen+1 << endl;
            solve(arr, chosen+1);
            return;
        } else {
            temp12[chosen] = arr[chosen];
            for(ll j = arr[chosen];j >= 1;j--){
                arr[chosen] = j;
                //cout << "2   " << arr[chosen] << "  " << chosen+1 << endl;
                solve(arr, chosen+1);
            }
            arr[chosen] = temp12[chosen];
            return;
        }
    }
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //
    char grid[10][10];
    fori(0, 9){
        forj(0, 9){
            cin >> grid[i][j];
        }
    }
    double expect[10][10];
    expect[0][0] = 0.0;
    expect[0][1] = 6.0;
    expect[0][2] = 6.0;
    expect[0][3] = 6.0;
    expect[0][4] = 6.0;
    expect[0][5] = 6.0;
    vector<pair<ll, ll>> lastSpaces;
    fori(0, 5){
        lastSpaces.push_back(make_pair(0, i));
    }
    double answer;
    fori(0, 9){
        if(i % 2 == 0){
            //doprava
            forj(0, 9){
                if(i == 0 && j < 6){
                    continue;
                }
                answer = 0;
                fork(0, 5){
                    if(grid[lastSpaces[k].first][lastSpaces[k].second] != '0'){
                        answer += min(expect[lastSpaces[k].first][lastSpaces[k].second], expect[lastSpaces[k].first-(grid[lastSpaces[k].first][lastSpaces[k].second]-'0')][lastSpaces[k].second]);
                    } else {
                        answer += expect[lastSpaces[k].first][lastSpaces[k].second];
                    }
                }
                answer /= 6.0;
                answer += 1.0;
                expect[i][j] = answer;
                lastSpaces.erase(lastSpaces.begin());
                //cout << lastSpaces[0].first << " " << lastSpaces[1].first << "    " << lastSpaces[5].first << endl;
                lastSpaces.push_back(make_pair(i, j));
                //cout << i << " " << j << " " << answer << endl;
            }
        } else {
            for(ll j = 9;j >= 0;j--){
                answer = 0;
                fork(0, 5){
                    if(grid[lastSpaces[k].first][lastSpaces[k].second] != '0'){
                        answer += min(expect[lastSpaces[k].first][lastSpaces[k].second], expect[lastSpaces[k].first-(grid[lastSpaces[k].first][lastSpaces[k].second]-'0')][lastSpaces[k].second]);
                    } else {
                        answer += expect[lastSpaces[k].first][lastSpaces[k].second];
                    }
                }
                answer /= 6.0;
                answer += 1.0;
                expect[i][j] = answer;
                lastSpaces.erase(lastSpaces.begin());
                lastSpaces.push_back(make_pair(i, j));
                //cout << i << " " << j << " " << answer << endl;
            }
        }
    }
    cout << fixed << setprecision(10) << expect[9][0] << endl;
    return 0;
}
