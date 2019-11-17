using namespace std;

long long MOD = 1000000007;
long long n;
long long countt = 0;
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;
    char last = '1';
    long long count = 1;
    long long sol = 1;
    long long f[100002];
    f[1] = 1;
    f[2] = 2;
    for(long long i = 3;i <= 100000;i++){
        f[i] = f[i-1] + f[i-2];
        f[i] %= MOD;
    }
    for(long long i = 0;i <= str.length()-1;i++){
        if(str[i] == 'm' || str[i] == 'w'){
            cout << 0 << endl;
            return 0;
        }
        if(str[i] == last){
            count++;
        } else {
            if(last == 'u' || last == 'n'){
                sol *= f[count];
                sol %= MOD;

            }
            count = 1;
            last = str[i];
        }
    }
    if(last == 'u' || last == 'n'){
        sol *= f[count];
        sol %= MOD;
        count = 1;
    }
    cout << sol << endl;
    return 0;
}
