#include<bits/stdc++.h>
using namespace std;

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   int tc;
   cin >> tc;
   while(tc--){

        int n;
        cin >> n;
        string s , t;
        cin >> s >> t;
        vector<pair<int,int>>answer;
        for(int i = 0; i < n; ++i){
            if(s[i] != t[i]){
                int flag = 0;
                if(flag == 0){
                   for(int j = i + 1; j < n; ++j){
                        if(s[j] == t[j]){
                            continue;
                        }
                        if(s[i] == s[j]){
                            swap(t[i] , s[j]);
                            answer.push_back({j + 1 , i + 1});
                            flag = 1;
                            break;
                        }
                   }
                }
                if(flag == 0){
                    for(int j = i + 1; j < n; ++j){
                        if(s[j] == t[j]){
                            continue;
                        }
                        if(s[i] == t[j]){
                            swap(s[j] , t[j]);
                            answer.push_back({j + 1  , j + 1});
                            swap(t[i] , s[j]);
                            answer.push_back({j + 1 , i + 1});
                            flag = 1;
                            break;
                        }
                    }
                }
            }
        }
        int k = answer.size();
        if(k > (2 * n) || s != t){
            cout << "No\n";
        }
        else{
          //  cout << s << " : " << t << "\n";
            cout << "Yes\n";
            int k = answer.size();
            cout << k << "\n";
            for(int i = 0; i < k; ++i){
                cout << answer[i].first << " " << answer[i].second << "\n";
            }
        }

   }


return 0;}
