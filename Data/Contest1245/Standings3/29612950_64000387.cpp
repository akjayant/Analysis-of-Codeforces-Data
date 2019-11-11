#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+5;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll mod = 1e9+7;


int n, R, S, P;
string B, A;
// R > S,  P > R,  S > P
int main(){
    int t; cin>>t;
    while(t--){
        cin>>n>>R>>P>>S;
        cin>>B;
        A = B;
        for(int i = 0; i < n; i++){
            if(B[i] == 'R'){
                if(P) --P, A[i] = 'P';
                else A[i] = 'x';
            }else if(B[i] == 'S'){
                if(R) --R, A[i] = 'R';
                else A[i] = 'x';
            }else if(B[i] == 'P'){
                if(S) --S, A[i] = 'S';
                else A[i] = 'x';
            }
        }
        int win = 0;
        for(int i = 0; i < n; i++){
            if(A[i] != 'x') { win++; continue; }
            if(P) --P, A[i] = 'P';
            else if(R) --R, A[i] = 'R';
            else if(S) --S, A[i] = 'S';
        }
        if(win*2 >= n){
            cout<<"YES"<<endl;
            cout<<A<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
	return 0;
}
