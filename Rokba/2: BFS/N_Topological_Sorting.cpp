#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int> 
#define endl '\n'
#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MAX = 10010;

set<int> adj[MAX];
vector<int> occor(MAX, 0);
vector<int> v(MAX, 0);
vector<int> res;

void bfs(int n){

    priority_queue<int, vector<int>, greater<int>> q;

    for(int i=1; i <= n; i++)
        if(occor[i] == 0)
            q.push(i);

    while(!q.empty()){
        
        int curr = q.top();
        v[curr] = 1;
        res.push_back(curr);
        q.pop();

        for(auto& node: adj[curr]){
            occor[node]--;
            if(!occor[node]) q.push(node);
        }
    }
}

int main(){

    Nkumbo

    int n, m;
    cin >> n >> m;

    vector<bool> root(n+1, false);

    for(int i=1; i <= m; i++){
        int a, b; cin >> a >> b;
        adj[a].insert(b);
        occor[b]++;
    }   

    bfs(n);

    if(res.size() == n){
        for(auto i: res) cout << i << ' '; cout << endl;
    }
    else 
        cout << "Sandro fails." << endl;

}