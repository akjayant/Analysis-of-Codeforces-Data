 #include <bits/stdc++.h>

 using namespace std;

 int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T,A,B,C;

    cin>>T;

    while(T--){
        int R=0;
        cin>>A>>B>>C;
        R+=min(B,C/2)+2*min(B,C/2);
        B-=min(B,C/2);
        R+=min(A,B/2)+2*min(A,B/2);
        cout<<R<<'\n';
    }


    return 0;
 }
