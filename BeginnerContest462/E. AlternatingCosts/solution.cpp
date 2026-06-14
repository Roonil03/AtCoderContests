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
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    // vector<int>arr(n);
    // cin >> arr;
    x = abs(x);
    y = abs(y);
    if(a > b){
        swap(a, b);
        swap(x, y);
    }
    auto h1 = [&](ll k) -> unsigned long long{
        ll p = (k + 1) / 2;
        ll d {0};
        if(p < x){
            d = x - p;
        } else if(p > k - y){
            d = p - (k - y);
        } else{
            d = (p % 2 != x % 2) ? 1 : 0;
        }
        return (unsigned long long)a * k + (unsigned long long)(b - a) * d;
    };
    unsigned long long res = h1(x + y);
    ll tar = max({x + y, 2 * x, 2 * y});
    for(ll i {-10}; i <= 10; i++){
        ll k = tar + i;
        if(k >= x + y && (k % 2 == (x + y) % 2)){
            res = min(res, h1(k));
        }
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