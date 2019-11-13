#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <utility>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <numeric>
#include <cmath>
#include <stack>
#include <map>
#include <deque>
#include <sstream>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef long long ll;
typedef string str;
typedef long double ld;
typedef vector <vector <int>> graf;
#define pi M_PI
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define pb push_back
#define re return
#define X first
#define Y second
#define fr(x) for(int i = 0; i <(x); i++)
const int inf = 1000000000 + 7;

signed main() {
    int k;
    cin >> k;
    while(k--)
    {
        bool ans = 1;
        int n;
        cin >> n;
        str s,t;
        cin >> s >> t;
        queue <pair<int,int>> q;
        for(int i = 0 ; i < n; i++){
            if(s[i] == t[i])
                continue;
                bool f = false;
            for(int j = i + 1; j < n; j++)
                if(s[j] == s[i])
                {
                    swap(s[j],t[i]);
                    q.push({j, i});
                    f=1;
                    break;
                }
                else
                if(t[j] == t[i])
                {
                    swap(s[i],t[j]);
                    q.push({i, j});
                    f=1;
                    break;
                }
                else
                    if(t[i] == s[j])
                {
                    swap(s[j],t[n-1]);
                    swap(t[n-1],s[i]);
                    q.push({j,n-1});
                    q.push({i,n-1});   f=1;
                    break;
                }
                else
                    if(s[i] == t[j])
                {
                    swap(t[j],s[n-1]);
                    swap(s[n-1],t[i]);
                    q.push({n-1,j});
                    q.push({n-1,i});   f=1;
                    break;
                }
            if(!f)
            {
                cout << "No\n";
                ans = 0;
                break;
            }
        }
        if(q.size() <= 2*n && ans){
            cout << "Yes\n" << q.size() << endl;
            while(!q.empty()){
                cout << q.front().first + 1<< " "<< q.front().second + 1<< endl;
                q.pop();
            }
        }
    }

}
