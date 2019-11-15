#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
 
int main(){
 
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int rock, paper, scis; cin >> rock >> paper >> scis;
        string s; cin >> s;
        string res(n, '1');
        int win = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'R' and paper) res[i] = 'P', paper--, win++;
            if(s[i] == 'P' and scis) res[i] = 'S', scis--, win++;
            if(s[i] == 'S' and rock) res[i] = 'R', rock--, win++;
        }
        for(int i = 0; i < n; i++)
            if(res[i] == '1'){
                if(s[i] == 'R'){
                    if(rock) res[i] = 'R', rock--;
                    else res[i] = 'S', scis--;
                }
                else if(s[i] == 'P'){
                    if(paper) res[i] = 'P', paper--;
                    else res[i] = 'R', rock--;
                }
                else{
                    if(scis) res[i] = 'S', scis--;
                    else res[i] = 'P', paper--;
                }
            }
        if(win*2 >= n){
            cout << "YES" << endl;
            cout << res << endl;
        }
        else cout << "NO" << endl;
    }
 
	return 0;
}