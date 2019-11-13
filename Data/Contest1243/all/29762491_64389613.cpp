#include<bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        string s1, s2;
        int n;
        cin >> n;
        cin >> s1 >> s2;
        vector<int> d;
        for(int i=0;i<n;++i)
            if(s2[i]!=s1[i])
                d.push_back(i);
        if(d.size()==0||(d.size()==2&&s1[d[0]]==s1[d[1]]&&s2[d[0]]==s2[d[1]]))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;


    }

}
