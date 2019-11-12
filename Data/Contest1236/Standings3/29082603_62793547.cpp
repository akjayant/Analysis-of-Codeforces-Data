#include<bits/stdc++.h>
using namespace std;
const int MX = (1<<20);
typedef  long long ll;
vector < int > v[500];
int main() {
#ifndef ONLINE_JUDGE
    //freopen("exptree.in", "r", stdin);
#endif
    int n;
    cin>>n;
    int st = 0;
    for(int j = 0 ; j < n * n ; j += n){
        vector < int > vec;
        for(int i = j ;  i < j + n ; i++)
            vec.push_back(i + 1);
        if(st % 2) reverse(vec.begin() , vec.end());

        for(int i = 0 ; i < n ; i++){
            v[i].push_back(vec[i]);
        }

        ++st;
    }
    for(int j = 0 ; j < n ; j++) {
        for (auto pp : v[j])
            cout << pp << ' ';
        cout << endl;
    }

}