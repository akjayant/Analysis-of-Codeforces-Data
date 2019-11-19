#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
int t;
cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;

        int least = n + 1;
        int right = -1;
        for(int i = 0 ; i < n ; i++)
        {
            if(s[i] == 49)
            {
                least = min(least,i);
                right = max(right,i);
            }
        }

        int answer = max(2*(n-least) , 2*(right+1));
        answer = max(answer,n);
        cout<<answer<<endl;
    }
}