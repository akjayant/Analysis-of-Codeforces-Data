#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        sort(A,A+N);
        int side_length = 0;
        int max_m = 1;
        int j = N-1;
        while(j>=0&&side_length<N)
        {
            side_length+=1;
            if(A[j]>side_length)
            {
                max_m = max(max_m,side_length);
            }
            else
            {
                max_m = max(max_m,A[j]);
                break;
            }
            j--;
        }
        cout<<max_m<<endl;
    }
}