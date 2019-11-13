#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int N,t;
int a, b, c,S,R,P;
char A[1000],B[1000];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    for(;t;t--){
        cin>>N;
        cin>>a>>b>>c;
        R=P=S=0;
        for(int i=0 ; i<N ;i++){
            char ch;
            cin>>ch;
            if(ch=='R'){
                A[i]=ch;
                R++;
            }
            else if(ch=='P'){
                A[i]=ch;
                P++;
            }
            else{
                A[i]=ch;
                S++;
            }
        }

        if(min(a,S)+min(b,R)+min(c,P)<(N+1)/2){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        for(int i=0 ; i<N ; i++){
            if(A[i]=='R'){
                if(b){
                    b--;
                    B[i]='P';
                }
                else{
                    B[i]='A';
                }
            }
            else if(A[i]=='P'){
                if(c){
                    c--;
                    B[i]='S';
                }
                else B[i]='A';
            }
            else if(A[i]=='S'){
                if(a){
                    a--;
                    B[i]='R';
                }
                else B[i]='A';
            }
            else{
                B[i]='A';
            }
        }
        for(int i=0 ; i<N ; i++){
            if(B[i]=='A'){
                if(a){
                    cout<<'R';
                    a--;
                }
                else if(b){
                    cout<<'P';
                    b--;
                }
                else{
                    cout<<'S';
                    c--;
                }
            }
            else cout<<B[i];
        }
        cout<<"\n";
    }
}