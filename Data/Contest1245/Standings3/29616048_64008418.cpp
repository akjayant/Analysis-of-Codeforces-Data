#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;

long gcd(long a, long b) {
    while(b) {
        long c = a%b;
        a = b;
        b = c;
    }
    return a;
}

int T[101][101][101];
char TT[101][101][101];

void print(int a, int b, int c) {
    if (a==0 && b == 0 && c == 0) return;
    char v = TT[a][b][c];
    if (v == 'R')
        print(a-1, b, c);
    if (v == 'P')
        print(a, b-1, c);
    if (v == 'S')
        print(a, b, c-1);
    cout << v;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tests; cin >> tests;
    
    int N, A, B, C;
    string s;
    while(cin >> N >> A >> B >> C >> s) {
        memset(T, 0, sizeof T);
        T[0][0][0] = 0;
        for(int n=1; n<=N; n++)
        for(int a=0; a<=n; a++)
        for(int b=0; b<=n-a; b++) {
            int c = n-a-b;
            int test;
            if (a > 0) {
                test = T[a-1][b][c] + (s[n-1] == 'S' ? 1 : 0);
                if (test > T[a][b][c]) {
                    T[a][b][c] = test;
                    TT[a][b][c] = 'R';    
                }
            }    
            if (b > 0) {
                test = T[a][b-1][c] + (s[n-1] == 'R' ? 1 : 0);
                if (test > T[a][b][c]) {
                    T[a][b][c] = test;
                    TT[a][b][c] = 'P';    
                }
            }
            if (c > 0) {
                test = T[a][b][c-1] + (s[n-1] == 'P' ? 1 : 0);
                if (test > T[a][b][c]) {
                    T[a][b][c] = test;
                    TT[a][b][c] = 'S';    
                }
            }
        }
        if (T[A][B][C] >= ceil(N/2.0)) {
            cout << "YES" << endl;
            print(A, B, C);
            cout << endl;
        } else {
            cout << "NO" << endl;
        }

    }
}