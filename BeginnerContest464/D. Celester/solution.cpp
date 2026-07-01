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
    string s;
    cin >> s;
    vll x(n), y(n - 1);
    cin >> x >> y;
    ll dp0 = (s[0] == 'R' ? -x[0] : 0);
    ll dp1 = (s[0] == 'S' ? -x[0] : 0);
    for(int i {1}; i < n; i++){
        ll ndp0 = (s[i] == 'R' ? -x[i] : 0) + max(dp0, dp1 + y[i - 1]);
        ll ndp1 = (s[i] == 'S' ? -x[i] : 0) + max(dp0, dp1);    
        dp0 = ndp0;
        dp1 = ndp1;
    }
    cout << max(dp0, dp1) << endl;
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