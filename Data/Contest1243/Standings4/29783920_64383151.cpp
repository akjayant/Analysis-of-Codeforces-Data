#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    int k;
    cin >> k;
    for (int i = 0; i < k; i++){
        int n;
        string s; string t;
        cin >> n >> s >> t;
        int z = 0;
        vector<int> v;
        for (int i = 0; i < n; i++){
            if (s[i] == t[i]){
                z++;
            }
            else {
                v.push_back(i);
            }
        }
        if (z != n - 2){
            cout << "No\n";
        }
        else {
            if (s[v[0]] == s[v[1]] && t[v[0]] == t[v[1]]){
                cout << "Yes\n";
            }
            else {
                cout << "No\n";
            }
        }
    }
}

