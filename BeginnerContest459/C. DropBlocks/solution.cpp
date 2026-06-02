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
    for (int i = 0; i < (int)v.size(); i++){
        os << v[i];
        if (i + 1 < (int)v.size()) os << " ";
    }
    return os;
}

void solve(){
    int n, q;
    cin >> n >> q;    
    vi a(n + 1, 0);
    vi xx(q + 1, 0);
    xx[0] = n;
    int off {0};    
    for(int i {0}; i < q; i++){
        int t;
        cin >> t;
        if(t == 1){
            int x;
            cin >> x;
            a[x]++;
            xx[a[x]]++;
            if(xx[off + 1] == n){
                off++;
            }
        } else{
            int y;
            cin >> y;
            if(y + off < sz(xx)){
                cout << xx[y + off] << "\n";
            } else{
                cout << 0 << "\n";
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);
    cin.exceptions(cin.failbit);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
