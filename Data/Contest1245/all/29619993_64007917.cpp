#include <bits/stdc++.h>

using namespace std;

int GCD(int a, int b){
    if (b==0) return a;
    return(GCD(b, a%b));

}


int main()
{
    int t;
    cin>>t;
    int n, a, b, c;
    string s;
    while(t--){
        cin>>n>>a>>b>>c;
        vector<char> us;
        int aa = 0, bb = 0, cc = 0;
        int otv = 0;
        cin>>s;
        for(int i = 0; i<s.size(); i++){
            switch(s[i]){
            case 'R':
                aa++;
                break;
            case 'P':
                bb++;
                break;
            case 'S':
                cc++;
                break;
            }
        }
        if(b>= aa){
            otv+=aa;
            for(int i = 0; i < b-aa; i++){
                us.push_back('P');
            }
        }
        else otv+= b;
        if(c>= bb){
            otv+=bb;
            for(int i = 0; i < c-bb; i++){
                us.push_back('S');
            }
        }
        else otv+= c;
        if(a>= cc){
            otv+=cc;
            for(int i = 0; i < a-cc; i++){
                us.push_back('R');
            }
        }
        else otv+= a;
        int p = 0;
        if(otv >= (n+1)/2){
            cout<<"YES\n"<<endl;
            for(int i = 0; i<s.size(); i++){
                switch(s[i]){
            case 'R':
                if(b>0){
                    b--;
                    cout<<"P";
                }
                else{
                    cout<<us[p++];
                }
                break;
            case 'P':
                if(c>0){
                    c--;
                    cout<<"S";
                }
                else{
                    cout<<us[p++];
                }
                break;
            case 'S':
                if(a>0){
                    a--;
                    cout<<"R";
                }
                else{
                    cout<<us[p++];
                }
                break;
            }
            }
            cout<<endl;
        }
        else
            cout<<"NO\n";
    }


    return 0;
}