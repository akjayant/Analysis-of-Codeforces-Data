#include <bits/stdc++.h>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    long long int n,k;
    cin>>n>>k;

    int gauche = 0, droite = n-1;
    vector<long long> v (n);
    for(int c=0;c<n;c++) {
        cin>>v[c];
    }
    sort(v.begin(),v.end());
    while(k>0&&gauche<droite) {

        //for(int c=0;c<v.size();c++) cout<<v[c]<<" ";
        //cout<<endl;

        while(gauche+1<n&&v[gauche+1]==v[gauche]) gauche++;
        while(droite-1>=0&&v[droite-1]==v[droite])droite--;
        long long d1 = gauche+1;
        long long d2 = n-droite;
        if(d1 < d2) {
            long long delta = v[gauche+1]-v[gauche];
            long long go = min(k/d1,delta);
            if(go <= 0) break;
            v[gauche]+=go;
            k-=go*d1;
        } else {
            long long delta = v[droite]-v[droite-1];
            long long go = min(k/d2,delta);
            if(go <= 0) break;
            v[droite]-=go;
            k-=go*d2;
        }
    }
    if(droite <= gauche) {
        cout<<0;
        return 0;
    }
    cout<<v[droite]-v[gauche];
}
