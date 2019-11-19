#include <iostream>
#include <algorithm>

using namespace std;

long long N,A[200001],K=0,K1=0;
int main(){
    cin >> N;
    for (int i=1;i<=N;i++)
        cin >> A[i];
    sort(A+1,A+N+1);
    for (int i=1;i<=N/2;i++)
        K+=A[i];
    for (int i=N/2+1;i<=N;i++)
        K1+=A[i];
    cout << K*K+K1*K1;
}