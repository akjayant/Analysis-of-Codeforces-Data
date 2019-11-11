#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
using namespace std;
ll NOD(ll A, ll B){
    while (A!=B)
        if (A>B) A-=B;
        else B-=A;
    return A;
}


int main(){
    ll t,a,b,i;
    cin>>t;
    for (i=0; i<t; i++){
        cin>>a>>b;
        if (NOD(a,b)==1)
            cout<<"Finite"<<endl;
        else
            cout<<"Infinite"<<endl;
    }
    return 0;
};
