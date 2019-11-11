#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if(!b)
        return a;
    return gcd(b, a%b);
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int a, b, c;
        cin>>a>>b>>c;
        string s;
        cin>>s;
        int sol = 0;
        char partida[n+1];
        partida[n] = 0;
        for(int i = 0; i < n; i++) {
            partida[i] = 'A';
            if(s[i] == 'P') {
                if(c)
                    c--, sol++, partida[i] = 'S';
            } else if(s[i] == 'S') {
                if(a)
                    a--, sol++, partida[i] = 'R';
            } else {
                if(b)
                    b--, sol++, partida[i] = 'P';
            }
        }
        if(sol >= (n+1)/2) {
            for(int i = 0; i < n; i++)
                if(partida[i] == 'A') {
                    if(c > 0) {
                        c--;
                        partida[i] = 'S';
                    } else if(b > 0) {
                        b--;
                        partida[i] = 'P';
                    } else {
                        partida[i] = 'R';
                    }
                }
            cout<<"YES"<<endl;
            cout<<partida<<endl;
        } else
            cout<<"NO"<<endl;
    }
}