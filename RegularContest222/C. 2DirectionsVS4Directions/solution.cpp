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
    int n;
    cin >> n;
    // vector<int>arr(n);
    // cin >> arr;
    vector<vll> a(n, vll(n));
    cin >> a;
    vector<vll> c(n, vll(n, 0));
    for(int i {0}; i < n; i++){
        for(int j {0}; j < n; j++){
            if(j > 0){
                c[i][j] += a[i][j-1];
            }
            if(j < n - 1){
                c[i][j] += a[i][j+1];
            }
        }
    }
    ll INF = 1e18;
    vector<vll> dp(n, vll(n, INF)), rdp(n, vll(n, INF));
    for(int i {0}; i < n; i++){
        dp[0][i] = c[0][i];
        rdp[n-1][i] = c[n-1][i];
    }
    for(int i {1}; i < n; i++){
        for(int j {0}; j < n; j++){
            ll b = INF;
            if(j > 0){
                b = min(b, dp[i-1][j-1]);
            }
            if(j < n - 1){
                b = min(b, dp[i-1][j+1]);
            }
            dp[i][j] = c[i][j] + b;
        }
    }
    for(int i = n - 2; i >= 0; i--){
        for(int j {0}; j < n; j++){
            ll b = INF;
            if(j > 0){
                b = min(b, rdp[i+1][j-1]);
            }
            if(j < n - 1){
                b = min(b, rdp[i+1][j+1]);
            }
            rdp[i][j] = c[i][j] + b;
        }
    }
    vector<vll> bp(n, vll(n));
    for(int i{0}; i < n; i++){
        for(int j {0}; j < n; j++){
            bp[i][j] = dp[i][j] + rdp[i][j] - c[i][j];
        }
    }
    for(int i {0}; i < n; i++){
        vll res;
        for(int j {0}; j < n; j++){
            ll temp = INF;
            if(j > 0){
                temp = min(temp, bp[i][j-1]);
            }
            if(j < n - 1){
                temp = min(temp, bp[i][j + 1]);
            }
            res.push_back(temp);
        }
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