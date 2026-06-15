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
    ll a, b, c;
    cin >> a >> b >> c;
    // vector<int>arr(n);
    // cin >> arr;
    ll res {0};
    if (a >= 1 && b >= 1 && c >= 1){
        ll temp = min({a + b - 2, b + c - 2, c + a - 2, (a + b + c - 3) / 2});
        res = max(res, temp);
    }
    if (b >= 1 && c >= 1){
        ll temp = min(a + c - 1, b - 1);
        res = max(res, temp);
    }
    if (c >= 1 && a >= 1){
        ll temp = min(b + a - 1, c - 1);
        res = max(res, temp);
    }
    if (a >= 1 && b >= 1){
        ll temp = min(c + b - 1, a - 1);
        res = max(res, temp);
    }
    if (c == 0){
        ll temp = (b >= a) ? a : max(0LL, b - 1);
        res = max(res, temp);
    }
    if (a == 0){
        ll temp = (c >= b) ? b : max(0LL, c - 1);
        res = max(res, temp);
    }
    if (b == 0){
        ll temp = (a >= c) ? c : max(0LL, a - 1);
        res = max(res, temp);
    }
    cout << res << endl;
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