#include <bits/stdc++.h>

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int i = 0; i < t; i++){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int ans = n;


        for(int j = 0; j < n; j++){
            if(s[j] == '1'){
                if(j < n/2){
                    ans = max(ans, 2*(n - j));
                }
                else{
                    ans = max(ans, 2*(j + 1));
                }
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}
