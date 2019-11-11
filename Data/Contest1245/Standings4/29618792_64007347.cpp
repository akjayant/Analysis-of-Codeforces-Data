#include <bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,T;
    cin >> T;

    for(t=1;t<=T;t++){
        int n,Ra,Pa,Sa,r=0,p=0,s=0;
        cin >> n >> Ra >> Pa >> Sa;
        string sss;
        cin >> sss;
        for(char c: sss){
            if(c == 'R')
                r++;
            else if(c == 'S')
                s++;
            else
                p++;
        }

        int total = 0, rem_R=0,rem_S=0,rem_P=0;
        if(Ra >= s){
            total += s;
            rem_R = Ra-s;
        }
        else{
            total += Ra;
        }

        if(Pa >= r){
            total += r;
            rem_P = Pa-r;
        }
        else{
            total += Pa;
        }

        if(Sa >= p){
            total += p;
            rem_S = Sa - p;
        }
        else{
            total += Sa;
        }

        if(2*total < n){
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        for(char c:sss){
            if(c == 'R'){
                if(Pa > 0){
                    cout << 'P';
                    Pa--;
                }
                else{
                    if(rem_R > 0){
                        cout << 'R';
                        Ra--;
                        rem_R--;
                    }
                    else{
                        cout << 'S';
                        Sa--;
                        rem_S--;
                    }
                }
            }

            /////
            else if(c == 'P'){
                if(Sa > 0){
                    cout << 'S';
                    Sa--;
                }
                else{
                    if(rem_P > 0){
                        cout << 'P';
                        Pa--;
                        rem_P--;
                    }
                    else{
                        cout << 'R';
                        Ra--;
                        rem_R--;
                    }
                }
            }
            //////
            else if(c == 'S'){
                if(Ra > 0){
                    cout << 'R';
                    Ra--;
                }
                else{
                    if(rem_S > 0){
                        cout << 'S';
                        Sa--;
                        rem_S--;
                    }
                    else{
                        cout << 'P';
                        Pa--;
                        rem_P--;
                    }
                }
            }
        }
        cout << '\n';

    }
    return 0;
}