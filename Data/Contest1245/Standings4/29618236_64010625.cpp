#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int cas=0; cas< t;cas++){
        int n; cin >> n;
        int a, b, c;
        cin >> a >> b >> c;
        string sol = "";
        string inp;
        cin >> inp;

        int wins= 0;
        for(int i = 0; i< n; i++){
            sol += "X";
            if(inp[i] == 'R' && b != 0){
                b--;
                wins++;
                sol[i] = 'P';
            }
            else if(inp[i] == 'P' && c != 0){
                c--;
                wins++;
                sol[i] = 'S';
            }
            else if(inp[i] == 'S' && a != 0){
                a--;
                wins++;
                sol[i] = 'R';
            }
        }

        if(wins < ((n+1)/2)){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            for(int i = 0; i < n; i++){
                if(sol[i] == 'X'){
                    if(a > 0){
                        a--;
                        sol[i] = 'R';
                    }
                    else if(b > 0){
                        b--;
                        sol[i] = 'P';
                    }
                    else{
                        c--;
                        sol[i] = 'S';
                    }
                }
            }
            cout << sol << endl;
        }
    }


    return 0;
}
