//Level of each Node using DFS
//Parent of each Node using DFS
//Children of each Node using DFS
#include<bits/stdc++.h>
using namespace std;

void bournVita() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif  
}


void dfs(vector<vector<int> >& edges, int currNode, int parent, vector<int>& children) {
    // level[currNode] = currLevel; //For level of each Node
    // parent1[currNode] = parent; //For parent of each Node
    for(int ngr : edges[currNode]) {
        if(ngr != parent) {
            children[currNode]++;
            dfs(edges, ngr, currNode, children);
        }
    }
}


void solve() {
    int n;
    cin >> n;

    vector<vector<int> > edges(n, vector<int>());
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    // vector<int> level(n, -1);
    // vector<int> parent(n, -1);
    vector<int> children(n, 0);
    dfs(edges, 0, -1, children);

    for(int i=0; i<n; i++) {
        cout << children[i] << endl;
    }
    cout << endl;
}

int main() {
    bournVita();

    solve();
}
