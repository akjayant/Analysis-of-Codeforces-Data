#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
int t;
cin>>t;
    while(t--)
    {
        int a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;

        int pens = (a%c == 0) ? a/c : a/c + 1;
        int pencils = (b%d == 0) ? b/d : b/d + 1;;

        if(pens + pencils <= k)
        {
            cout<<pens<<" "<<pencils<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
    }
}