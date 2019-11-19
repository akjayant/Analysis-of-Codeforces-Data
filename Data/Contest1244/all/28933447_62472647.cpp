    #include <bits/stdc++.h>
    using namespace std;

    int t;
    string s;
    int main()
    {
        cin >> t;
        while(t--)    
        {
            int len;
            cin >> len;
            cin >> s;
            int pos = 0;
            for(int i = 0;i < s.size(); ++i)
            {
                if(s[i] == '1')
                pos = max(pos,max(i + 1,len - i));
            }
            cout << max(2*pos,len) << endl;
        }
        return 0;
    }