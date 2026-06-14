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
    vi z(n + 1);
    for (int i {0}; i < n; i++) {
        int x, y;
        cin >> x >> y;
        z[x] = y;
    }
    int res = 0;
    int my = n + 1;
    for (int x{1}; x <= n; x++) {
        if (z[x] < my) {
            res++;
            my = z[x];
        }
    }
    cout << res << "\n";
    // cout << arr;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);
    cin.exceptions(cin.failbit);
    int t = 1;    
    precomp();
    while(t--){
        solve();
    }
    return 0;
}