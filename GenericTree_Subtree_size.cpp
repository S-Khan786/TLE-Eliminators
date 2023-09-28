//Finding the Subtree size of each Children
//Subtree of a Node is (Node itself + all descendent Nodes)
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

void dfs(vector<vector<int> >& edges, int currNode, int parent, vector<int>& subtree) {
    for(int ngr : edges[currNode]) {
        if(ngr != parent) {
            dfs(edges, ngr, currNode, subtree);
            subtree[currNode] += subtree[ngr];
        }
    }

    subtree[currNode]++;
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

    vector<int> subtree(n, 0);
    dfs(edges, 0, -1, subtree);

    for(int i=0; i<n; i++) {
        cout << subtree[i] << endl;
    }
    cout << endl;
}

int main() {
    bournVita();

    solve();
}
