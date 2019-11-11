#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
using namespace std;

int main(){
    ll i,j,ans=1,k;
    ll C=(ll)(1e9)+7;
    vector <ll> f((ll)1e5);
    f[0]=1;
    f[1]=2;
    for (j=2; j<(ll)1e5; j++)
        f[j]=(f[j-1]+f[j-2])%C;
    char s[(ll)1e5];
    cin>>s;
    for(i=0; s[i]!='\0'; i++){
        if (s[i]=='m' || s[i]=='w'){
            cout<<0;
            return 0;
        }
        if (!(s[i]=='u' || s[i]=='n'))
            continue;
        i++;
        if (s[i]=='\0')
            continue;
        k=1;
        while(s[i]==s[i-1]){
            k++;
            i++;
            if (s[i]=='\0')
                break;
        }
        i--;
        ans=(ans*f[k-1])%C;
    }
    cout<<ans;
    return 0;
};
