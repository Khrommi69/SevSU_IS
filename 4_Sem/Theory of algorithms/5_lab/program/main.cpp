#include <iostream>
#include <iomanip>
#include <algorithm>
#include <chrono>

using namespace std;

const int INF = 1000000000;
bool used[100] = {0};
int top[100] = {0};
int g[100][100] = {0};
int n;
int l;
int s;
int f;
int d[100] = {0};

void dfs(int v) {
    if(used[v])
        return;
    used[v] = true;
    for(int to = 0; to < n; to++)
        if(g[v][to])
            dfs(to);
    top[l++] = v;
}

void topSort() {
    l = 0;
    for(int i = 0; i < n; i++)
        dfs(i);
    reverse(top, top+l);
}

void solve() {
    int i, j;
    for(i = 0; i < n; i++)
        d[i] = INF;
    d[s] = 0;
    for(i = 1; i < n; i++)
        for(j = 0; j < i; j++)
            if(g[top[j]][top[i]])
                d[top[i]] = min(d[top[i]], d[top[j]] + g[top[j]][top[i]]);
}

void deikstra() {
    int i,j,
            v,
            to,
            len;
    for(i = 0; i < n; i++)
        d[i] = INF;
    d[s] = 0;
    for(i = 0; i < n; i++) {
        v = -1;
        for(j = 0; j < n; j++)
            if(!used[j] && (v == -1 || d[j] < d[v]))
                v = j;
        used[v] = true;
        for(to = 0; to < n; to++) {
            if(g[v][to]) {
                len = g[v][to];
                if(d[v] + len < d[to]) {
                    d[to] = d[v] + len;
                }
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    n = 10;
    cout << "??????? ????????? ???????: ";
    cin >> s;
    cout << "??????? ???????? ???????: ";
    cin >> f;
    cout << "??????? ??????? 9x9:" << endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> g[i][j];
        }
    }
    auto start_time = chrono::high_resolution_clock::now();
    auto end_time = chrono::high_resolution_clock::now();
    long long time;
    start_time = chrono::high_resolution_clock::now();
    for(int i=0;i<1000000;i++) {
        for(int j=0;j<100;j++)
            used[j] = false;
        deikstra();
    }
    end_time = chrono::high_resolution_clock::now();
    time = chrono::duration_cast<chrono::milliseconds>(end_time-start_time).count();
    cout << "?????????? ???????? ??? ????????? ????????: " << d[f] << endl;
    cout << "?????: " << time << endl;

    start_time = chrono::high_resolution_clock::now();
    for(int i=0;i<1000000;i++) {
        for(int j=0;j<100;j++)
            used[j] = false;
        topSort();
        solve();
    }
    end_time = chrono::high_resolution_clock::now();
    time = chrono::duration_cast<chrono::milliseconds>(end_time-start_time).count();
    cout << "?????????? ???????? ??? ????????? ????????????? ????????????????: " << d[f] << endl;
    cout << "?????: " << time << endl;
    return 0;
}
