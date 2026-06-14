#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("O3")
// #pragma GCC target("avx2, bmi, bmi2, popcnt")

#define sz(x) ((int)x.size())
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<long long>

template<typename T>
istream& operator>>(istream& is, vector<T>& v){
    for (T& x : v) is >> x;
    return is;
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v){
    for (int i = 0; i < v.size(); i++){
        os << v[i];
        if (i + 1 < v.size()) os << " ";
    }
    return os;
}

void precomp(){

}

void solve(){
    // int n;
    // cin >> n;
    // vector<int>arr(n);
    // cin >> arr;
    string s;
    int k;
    cin >> s >> k;
    int n = sz(s);
    int O = 80;
    int INF = (1e9);
    int dp[3][165];
    for(int i {0}; i < 3; i++){
        for(int j {0}; j < 165; j++){
            dp[i][j] = INF;
        }
    }
    dp[0][O] = 0;
    int ndp[3][165];
    for(int i {0}; i < n; i++){
        int a {0};
        if(i >= 2 && s[i-2] == 'A' && s[i-1] == 'B' && s[i] == 'C'){
            a = 1;
        }
        for(int j {0}; j < 3; j++){
            for(int d {0}; d < 165; d++){
                ndp[j][d] = INF;
            }
        }
        int ca = (s[i] == 'A') ? 0 : 1;
        int cb = (s[i] == 'B') ? 0 : 1;
        int cc = (s[i] == 'C') ? 0 : 1;
        int x = (s[i] != 'A' && s[i] != 'B' && s[i] != 'C') ? 0 : 1;
        for(int j {0}; j < 3; j++){
            for(int d {0}; d < 165; d++){
                if(dp[j][d] == INF){
                    continue;
                }
                int b = d - a;
                if(b < 0 || b >= 165){
                    continue;
                }
                int va = dp[j][d] + ca;
                if(va < ndp[1][b]){
                    ndp[1][b] = va;
                }
                int nb = (j == 1) ? 2 : 0, vb = dp[j][d] + cb;
                if(vb < ndp[nb][b]){
                    ndp[nb][b] = vb;
                }
                int dc = b + ((j == 2) ? 1 : 0);
                if(dc >= 0 && dc < 165){
                    int vc = dp[j][d] + cc;
                    if(vc < ndp[0][dc]){
                        ndp[0][dc] = vc;
                    }
                }
                int vx = dp[j][d] + x;
                if(vx < ndp[0][b]){
                    ndp[0][b] = vx;
                }
            }
        }
        for(int j {0}; j < 3; j++){
            for(int d {0}; d < 165; d++){
                dp[j][d] = ndp[j][d];
            }
        }
    }
    int res = INF;
    if(O + k >= 0 && O + k < 165){
        for(int j {0}; j < 3; j++){
            if(dp[j][O + k] < res){
                res = dp[j][O+k];
            }
        }
    }
    if(res >= INF){
        cout << -1 << endl;
    } else{
        cout << res << endl;
    }
    // cout << arr;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);
    cin.exceptions(cin.failbit);
    int t;
    cin >> t;    
    precomp();
    while(t--){
        solve();
    }
    return 0;
}