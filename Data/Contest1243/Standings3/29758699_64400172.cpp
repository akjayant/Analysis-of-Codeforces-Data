#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e3 + 9 ;
int a[N];
vector < ll > factors;
void factorize(ll num){
    for(ll i = 2 ; i*i<=num ; ++i){
        if(num % i == 0){
            factors.push_back(i);
            if(i!=num/i)
                factors.push_back(num / i);
        }
    }
}
int main()
{    
    int t;
    cin >> t;
    while(t--){
        string s , t;
        int n;
        cin >> n >> s >> t;
        int cnt = 0;
        bool ans = 1;
        bool f = 0;
        vector < pair < int , int > > v;
        for(int i = 0 ; i < n ; ++i){
            //cout << s << " " << t << endl;
            if(s[i] == t[i]) continue;
            if(f){
                ans = 0;
                break;
            }
            f = 1;
            for(int j = i +1 ; j < n ; ++j){
                if(t[i] == t[j] ){
                    f = 0;
                    v.push_back({i , j});
                    swap(s[i] , t[j]);
                    break;

                }
            }
            if(f){
                for(int j = i + 1 ; j < n ; ++j){
                     if(s[j] == t[i] ){
                     f = 0;
                     v.push_back({j,j});
                     swap(s[j] , t[j]);
                     v.push_back({i , j});
                     swap(s[i] , t[j]);
                     break;

                }
                }
            }
        }
        if(f) ans = 0;
        if(ans && (int)v.size() <= 2*n){
            cout << "Yes\n";
            cout << v.size() << endl;
            for(auto i : v) cout << i.first +1 << " " << i.second +1 << endl;
        }
        else{
            cout << "No\n";

        }





    }
    return 0;
}
