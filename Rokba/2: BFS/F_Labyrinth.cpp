#include <bits/stdc++.h> 

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int> 
#define endl '\n'
#define mk make_pair
#define f first
#define s second

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MAX = 2010;
const int INF = INT_MAX;

char adj[MAX][MAX];
pii v[MAX][MAX];
vector<pii> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m, inr, inc, d, e;

void init() {
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            v[i][j] = {INF, INF};
}

bool isPossible(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m && adj[x][y] == '.');
}

void bfs(int x, int y) {
    deque<pii> q;
    q.push_front({x, y});
    v[x][y] = {0, 0};

    while (!q.empty()) {
        pii no = q.front();
        q.pop_front();

        for (auto& i : moves) {
            int a = no.f + i.f, b = no.s + i.s;
            if (!isPossible(a, b)) continue;

            int r = v[no.f][no.s].f + (i.s == -1);
            int c = v[no.f][no.s].s + (i.s == 1);

            if (r <= d && c <= e && (r < v[a][b].f || c < v[a][b].s)) {
                v[a][b] = {r, c};

                if (i.s == -1)  
                    q.push_front({a, b});
                else 
                    q.push_back({a, b});
            }
        }
    }
}

int main() {
    Nkumbo

    cin >> n >> m >> inr >> inc >> d >> e;

    init();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> adj[i][j];
    
    bfs(inr - 1, inc - 1);

    int num = 0;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            if (v[i][j].f <= d && v[i][j].s <= e) 
                num++;

    cout << num << endl;

    return 0;
}
