#include <bits/stdc++.h>

using namespace std;

int res[300][300];

int main(){
    char ch[] = {'R', 'P', 'S'};
    res['R']['S'] = 1;
    res['S']['R'] = -1;

    res['P']['R'] = 1;
    res['R']['P'] = -1;

    res['S']['P'] = 1;
    res['P']['S'] = -1;
    int t;
    for(cin >> t; t--; ){
        int n, A[3];
        string s;
        cin >> n;
        cin >> A[0] >> A[1] >> A[2];
        cin >> s;
        int v[300];
        memset( v, -1, sizeof v );
        int sc = 0;

        for( int a = 0; a < 3; a++ ){
            for( int i = 0; i < n; i++ )
                if( v[i] == -1 && res[ch[a]][s[i]] == 1 && A[a] ){
                    sc++;
                    A[a]--;
                    v[i] = a;
                }
        }
        
        for( int a = 0; a < 3; a++ ){
            for( int i = 0; i < n; i++ )
                if( v[i] == -1 && A[a] ){
                    A[a]--;
                    v[i] = a;
                }
        }
        
        if(sc < (n + 1) / 2){
            cout << "no" << endl;
        }
        else{
            cout << "yes" << endl;
            for( int i = 0; i < n; i++ )
                cout << ch[v[i]];
            cout << endl;
        }
    }




    return 0;
}