#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string A,B;
        vector<int>temp;
        cin>>A>>B;
        for(int i=0;i<N;i++){
            if(A[i]!=B[i])
            {
                temp.push_back(i);
            }
        }
        if(temp.size()>2||temp.size()==1)
        {
            cout<<"No\n";
        }
        else
        {
            if(temp.size()==2)
            {
                if(A[temp[0]]==A[temp[1]]&&B[temp[1]]==B[temp[0]])
                {
                    cout<<"Yes\n";
                }
                else
                {
                    cout<<"No\n";
                }
            }
            else
            {
                cout<<"Yes\n";
            }
        }
    }
}