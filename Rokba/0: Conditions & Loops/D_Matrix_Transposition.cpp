#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){

    int h, w; 
    cin >> h >> w;

    int a[h][w];

    for(int i=0; i < h; i++){
        for(int j=0; j < w; j++){
            cin >> a[i][j];
        }
    }

    for(int j=0; j < w; j++){
        for(int i=0; i < h; i++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}