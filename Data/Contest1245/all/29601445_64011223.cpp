#include<bits/stdc++.h>
#define ll long long int
#define maxn 100005
#define pb push_back

using namespace std;



int main()
{
    int TC;
    cin >> TC;
    while(TC--){
        int n;
        cin >> n;
        int a, b, c, res = 0;
        cin >> a >> b >> c;
        vector<int> R, P, S;
        string s, temp = "";
        cin >> s;
        for(int i=0;i<n;i++)temp += '?';
        for(int i=0;i<n;i++){
            if(s[i] == 'R'){
                R.pb(i);
            }
            if(s[i] == 'P'){
                P.pb(i);
            }
            if(s[i] == 'S'){
                S.pb(i);
            }
        }
        for(auto x: S){
            if(a){
                a--;
                res++;
                temp[x] = 'R';
            }
        }
        for(auto x: R){
            if(b){
                b--;
                res++;
                temp[x] = 'P';
            }
        }
        for(auto x: P){
            if(c){
                c--;
                res++;
                temp[x] = 'S';
            }
        }
        for(int i=0;i<n;i++){
            if(temp[i] == '?'){
                if(a){
                    a--;
                    temp[i] = 'R';
                }
                else if(b){
                    b--;
                    temp[i] = 'P';
                }
                else if(c){
                    c--;
                    temp[i] = 'S';
                }
            }
        }
        int nd = (n/2) + (n%2);
        if(res >= nd){
            cout <<"YES"<<endl;
            cout << temp << endl;
        }
        else{
            cout <<"NO"<<endl;
        }

    }
    return 0;
}
