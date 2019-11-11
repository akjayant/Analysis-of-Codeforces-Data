#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int N,A[100000];
int a, b, c;
int gcd(int a,int b){
    if(a<b){
        return gcd(b,a);
    }
    if(a==b)return a;
    return gcd(a-b,b);
}
int main(){
    //ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N;
    for(int i=0 ; i<N ; i++){
        cin>>a>>b;
        int re= 0;
        if(gcd(a,b)==1){
            cout<<"Finite\n";
        }
        else{
            cout<<"Infinite\n";
        }
    }
}