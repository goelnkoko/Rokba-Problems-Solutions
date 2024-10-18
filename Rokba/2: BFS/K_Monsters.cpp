#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int INF = INT_MAX;

int n, m;
char grid[MAXN][MAXN];
int dist[MAXN][MAXN];
bool vis[MAXN][MAXN];
pair<int, int> parents[MAXN][MAXN];
vector<pair<int, int>> dx = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<char> pdx = {'D', 'U', 'R', 'L'};

void bfs1() {
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'M') {
                q.push({i, j});
                dist[i][j] = 0;
            } else {
                dist[i][j] = INF;
            }
        }
    }

    while (!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();
        int x = front.first, y = front.second;
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d].first;
            int ny = y + dx[d].second;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '.' && dist[nx][ny] == INF) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

bool bfs2(pair<int, int> s) {
    queue<pair<int, int>> q;
    q.push(s);
    vis[s.first][s.second] = true;
    while (!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();
        int x = front.first, y = front.second;
        if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
            vector<char> path;
            while (make_pair(x, y) != s) {
                auto px = parents[x][y].first;
                auto py = parents[x][y].second;
                if (px == x + 1) path.push_back('U');
                else if (px == x - 1) path.push_back('D');
                else if (py == y + 1) path.push_back('L');
                else if (py == y - 1) path.push_back('R');
                x = px;
                y = py;
            }
            reverse(path.begin(), path.end());
            cout << "YES\n" << path.size() << "\n";
            for (char dir : path) {
                cout << dir;
            }
            cout << "\n";
            return true;
        }
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d].first;
            int ny = y + dx[d].second;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
                if (grid[nx][ny] == '.' && (dist[nx][ny] == INF || (dist[nx][ny] > dist[x][y] + 1))) {
                    dist[nx][ny] = dist[x][y] + 1;
                    vis[nx][ny] = true;
                    parents[nx][ny] = {x, y};
                    q.push({nx, ny});
                }
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    pair<int, int> s;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                s = {i, j};
            }
        }
    }
    
    bfs1();
    dist[s.first][s.second] = 0;
    if (!bfs2(s)) {
        cout << "NO\n";
    }

    return 0;
}