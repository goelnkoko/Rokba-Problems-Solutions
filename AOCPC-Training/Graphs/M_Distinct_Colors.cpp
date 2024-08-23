#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

const int MAX = 200010;

vector<int> graph[MAX];
vector<int> resp(MAX, 0);
vector<int> c(MAX, 0);
vector<int> r(MAX, 0);
vector<int> cc(MAX, 0);


int dfs(int root, int p){

    int colors = 1;
    cc[c[root]]++;

    for(auto i: graph[root]){
        if(i == p) continue;

        colors += dfs(i, root);
    }

    r[root] = colors;
    cc[c[root]]--;
    if(cc[c[root]] == 0) colors--;
    return colors;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i=1; i <= n; i++){
        cin >> c[i];
    }

    for(int i=0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 1);

    for(int i=1; i <= n; i++){
        cout << r[i] << ' ';
    }
    cout << '\n';
}