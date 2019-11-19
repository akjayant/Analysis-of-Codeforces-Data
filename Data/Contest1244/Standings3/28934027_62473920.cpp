#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;


int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        bool fullZero = true;
        for(int c=0;c<s.size();c++) if(s[c]!='0') fullZero=false;
        if(fullZero) {
            cout<<n<<endl;
            continue;
        }
        int first = 0;
        int last = s.size()-1;
        while(s[first]=='0') first++;
        while(s[last]=='0') last--;
        cout<<(n*2-2*min(first,((n-1)-last)))<<endl;

    }
}
