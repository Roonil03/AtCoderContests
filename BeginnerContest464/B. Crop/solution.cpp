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
    int h, w;
    cin >> h >> w;
    // vector<int>arr(n);
    // cin >> arr;
    vector<string> grid(h);
    int a = h, b = -1, c = w, d = -1;
    for(int i {0}; i < h; i++){
        cin >> grid[i];
        for(int j {0}; j < w; j++){
            if(grid[i][j] == '#'){
                if(i < a){
                    a = i;
                }
                if(i > b){
                    b = i;
                }
                if(j < c){
                    c = j;
                }
                if(j > d){
                    d = j;
                }
            }
        }
    }
    for(int i = a; i <= b; i++){
        cout << grid[i].substr(c, d - c + 1) << endl;
    }
    // cout << arr;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);
    cin.exceptions(cin.failbit);
    int t {1};    
    precomp();
    while(t--){
        solve();
    }
    return 0;
}