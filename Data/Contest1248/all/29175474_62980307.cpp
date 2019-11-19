#include <iostream>

using namespace std;
long long T,N,M,K,K1,X;
int main(){
    cin >> T;
    while (T--){
        K=0;K1=0;
        cin >> N;
        for (int i=1;i<=N;i++){
            cin >> X;
            K+=(X%2);
        }
        cin >> M;
        for (int i=1;i<=M;i++){
            cin >> X;
            K1+=(X%2);
        }
        cout << K*K1+(N-K)*(M-K1) << endl;
    }
}