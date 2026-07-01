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
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    vector<int> A(n - 1);
    for (int i = 0; i < n - 1; i++){
        A[i] = -((s[i] == 'S') + (s[i + 1] == 'R'));
    }
    
    int N = sz(A);
    vector<bool> rest(N + 2, true);
    rest[0] = rest[N + 1] = false;
    vector<int> left(N + 2), right(N + 2), val(N + 2);
    priority_queue<pair<int, int>> que;
    
    for (int i = 0; i < N + 2; i++){
        left[i] = i - 1;
        right[i] = i + 1;
    }
    
    for (int i = 0; i < N; i++){
        val[i + 1] = A[i];
        que.emplace(val[i + 1], i + 1);
    }
    
    vector<int> ANS = {0};
    while (!que.empty()) {
        auto [add, i] = que.top(); 
        que.pop();
        if (!rest[i]) continue;
        
        ANS.push_back(ANS.back() + add);
        int L = left[i], R = right[i];
        
        if (1 <= L) {
            right[left[L]] = i; 
            left[i] = left[L]; 
        }
        if (R <= N) {
            left[right[R]] = i; 
            right[i] = right[R]; 
        }
        
        if (rest[L] && rest[R]) {
            val[i] = val[L] + val[R] - val[i];
            que.emplace(val[i], i);
        } else {
            rest[i] = false;
        }
        rest[L] = rest[R] = false;
    }
    
    for (int& x : ANS) x = -x;
    
    vector<int> out(n + 1, 0);
    for (int i = 0; i < sz(ANS); i++){
        out[ANS[i]] = i;
    }
    for (int i = 0; i < n; i++){
        out[i + 1] = max(out[i + 1], out[i]);
    }
    
    cout << out << "\n";
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

// Solution referenced from https://atcoder.jp/users/maspy

/*
The algorithm uses a greedy approach with a priority queue to find the Maximum Weight Independent Set on a path graph 
(effectively computing the optimal choice of non-adjacent pairs for all possible sizes k). It evaluates each valid 
string pair into an integer weight representation. By keeping track of the selected node and its neighbors in a doubly-linked 
list structure, the algorithm incorporates the "Aliens trick" / localized slope optimization: when a node with weight V_M 
is selected, it gets replaced by a surrogate node with weight (V_L + V_R - V_M) to seamlessly process reversing the current 
greedy choice in favor of picking its two neighbors later. Finally, a prefix max ensures the output array monotonically 
reflects the maximum independent sets possible under a given total cost.

Time Complexity: O(N log N) per test case, where N is the length of the string, strictly driven by popping and inserting 
elements into the max priority queue.

Space Complexity: O(N) auxiliary space per test case for accommodating the arrays used for tracking the doubly linked list 
structures, the values, and the priority queue elements.
*/