#include <bits/stdc++.h>

using namespace std;

#define MM 1000000007 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,T;
    // cin >> T;
    T = 1;

    deque<long long> fib{1,1,2,3};

    for(t=1;t<=T;t++){
        string s;
        cin >> s;

        char last = 'y';
        bool done = false;
        int c = 0;
        deque<int> q;
        for(int i=0;i<s.size();i++){
            if(s[i]=='m' || s[i]=='w'){
                done = true;
                break;
            }
            if(s[i] == 'n' && last == 'n'){
                c++;
            }
            else if(s[i] == 'u' && last == 'u'){
                c++;
            }
            else{
                if(c > 0){
                    q.push_back(c+1);
                }
                c = 0;
                last = s[i];
            }
        }
        if(c > 0){
            q.push_back(c+1);
        }
        

        if(done){
            cout << "0\n";
            continue;
        }

        long long res = 1;
        for(int x: q){
            while(x >= fib.size()){
                int s = fib.size();
                fib.push_back((fib[s-1]+fib[s-2])%MM);
            }
            // cout << x << ' ' << fib[x] <<'\n';

            res = (res*fib[x])%MM;
        }
        cout << res << endl;
    }
    return 0;
}