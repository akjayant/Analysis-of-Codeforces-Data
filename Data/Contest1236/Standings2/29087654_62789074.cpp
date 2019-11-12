 #include <bits/stdc++.h>

 using namespace std;

 long long POW(long long A,long long B){
    if(B==0)return 1ll;
    if(B==1)return A;

    if(B%2==0){
        long long r=POW(A,B/2);
        return (r*r)%1000000007;
    }
    return (POW(A,B-1)*A)%1000000007;
 }

 int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long A,B,C;

    cin>>A>>B;

    cout<<POW(((POW(2,B)-1+1000000007)%1000000007),A)<<'\n';

    return 0;
 }
