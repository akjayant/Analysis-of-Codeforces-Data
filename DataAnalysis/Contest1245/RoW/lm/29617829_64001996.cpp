using namespace std;

string s;
int n;

const int md = 1000000007;
int d[100010];

int32_t main()
{


    ios_base::sync_with_stdio(false);
    cin >> s;
    n = s.length();
    d[0] = 1;
    for(int i = 0; i < n; i++){
        if(s[i] == 'w' or s[i] == 'm'){
            cout << 0 << endl;
            return 0;
        }
        d[i+1] += d[i];
        if(d[i+1] >= md) d[i+1] -= md;
        if(i){
            if(s[i] == 'u' && s[i-1] == 'u' || s[i] == 'n' && s[i-1] == 'n'){
                d[i+1] += d[i-1];
                if(d[i+1] >= md) d[i+1] -= md;
            }
        }
    }
    cout << d[n] << '\n';
    return 0;
}
