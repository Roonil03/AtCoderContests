#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("O3")

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
    int n, m;
    cin >> n >> m;
    vll a(n), b(m);
    cin >> a >> b;
    for(int i = 1; i < n; i += 2) a[i] ^= 1;
    for(int i = 1; i < m; i += 2) b[i] ^= 1;
    if(a[0] != b[0]){
        cout << "No\n";
        return;
    }
    vll x, y;
    ll c = 1;
    for(int i = 1; i < n; i++){
        if(a[i] != a[i-1]){
            x.push_back(c);
            c = 1;
        } else {
            c++;
        }
    }
    x.push_back(c);
    c = 1;
    for(int i = 1; i < m; i++){
        if(b[i] != b[i-1]){
            y.push_back(c);
            c = 1;
        } else {
            c++;
        }
    }
    y.push_back(c);
    if(x.size() != y.size()){
        cout << "No\n";
        return;
    }
    int len = x.size();
    vi dp(3, 0);
    dp[0] = 1;
    for(int i = 0; i + 1 < len; i++){
        vi dp2(3, 0);
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                if(!dp[j]) continue;
                if(x[i] + j + k > y[i]) continue;
                if((x[i] + j + k + y[i]) % 2) continue;
                if(x[i] == 1 && j == 0 && k == 0 && y[i] != 1) continue;
                dp2[k] = 1;
            }
        }
        dp = dp2;
    }
    bool ans = false;
    for(int i = 0; i < 3; i++){
        if(!dp[i]) continue;
        if(x[len-1] + i > y[len-1]) continue;
        if((x[len-1] + i + y[len-1]) % 2) continue;
        if(x[len-1] == 1 && i == 0 && y[len-1] != 1) continue;
        ans = true;
    }
    if(ans) cout << "Yes\n";
    else cout << "No\n";
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

// Solution referenced from https://atcoder.jp/users/PCTprobability

/*
The algorithm simplifies the problem's operations by toggling the bits at odd indices of both arrays, transforming the complex 
subarray operations into a run-length encoding (RLE) matching problem. After the transformation, it checks if the first elements 
match and if both arrays produce the same number of alternating contiguous blocks (runs). A dynamic programming state of size 
3 tracks the "carry" or borrowing length passed to adjacent blocks. For each block, it iterates through all possible incoming 
and outgoing carries, validating that the adjusted run length in the source array can reach the corresponding target run length 
via valid parity bounds and edge constraints (such as preventing a solitary element from expanding illicitly).

Time Complexity: O(N + M) per testcase. Toggling bits, constructing the run-length arrays, and comparing them each take linear 
time. The DP loop iterates over the blocks with a constant number of inner iterations (3x3), maintaining O(N + M) overall.

Space Complexity: O(N + M) to store the modified arrays `a` and `b`, as well as their compressed run-length representations `x` 
and `y`.
*/