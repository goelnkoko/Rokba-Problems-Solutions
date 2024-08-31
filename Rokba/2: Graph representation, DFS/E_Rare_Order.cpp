#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int> 
#define endl '\n'
#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MAX = 26;

vector<int> adj[MAX];
map<int, int> occor;
vector<int> res;

void init(vector<string>& aux){
    for(int i=0; i < aux.size(); i++)
        for(int j=0; j < aux[i].size(); j++)
            occor[aux[i][j] - 'A' + 1] = 0;
}   

void createGraph(vector<string>& aux){
    for(int i=1; i < aux.size(); i++){
        int t1 = aux[i-1].size(), t2 = aux[i].size();
        for(int j=0; j < t1 && j < t2; j++){
            if(aux[i-1][j] != aux[i][j]) {
                adj[aux[i-1][j] - 'A'+1].push_back(aux[i][j] - 'A'+1);
                occor[aux[i][j]-'A'+1]++;
                break;
            }
        }
    }
}

void bfs(){

    queue<int> q;
    for(const auto& i: occor)
        if(i.second == 0)
            q.push(i.first);
    
    while(!q.empty()){
        int curr = q.front();
        q.pop();

        res.push_back(curr);

        for(const auto& node: adj[curr]){
            occor[node]--;

            if(!occor[node])
                q.push(node);
        }
    }
}

int main(){

    Nkumbo

    string s;
    vector<string> aux;

    while(cin >> s && s != "#")
        aux.push_back(s);

    init(aux);
    createGraph(aux);
    bfs();

    for(auto i: res){
        cout << (char)(i + 'A' - 1);
    }
    cout << endl;

}