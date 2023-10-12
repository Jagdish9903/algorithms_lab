#include<bits/stdc++.h>
using namespace std;
void add(vector<int> adj[], int a, int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}
void BFS(int a, vector<int> adj[],vector<bool> &visit)
{
    cout<<"BFS traversal is : ";
    queue<int> q;
    q.push(a);
    visit[a] = true;
    while(!q.empty())
    {
        int u = q.front();
        cout<<u<<" ";
        q.pop();
        for(int i = 0; i < adj[u].size(); i++)
        {
            if(!visit[adj[u][i]])
            {
                q.push(adj[u][i]);
                visit[adj[u][i]] = true;
            }
        }
    }
}
void DFS(int a, vector<int> adj[],vector<bool> &visit)
{
    cout<<"DFS traversal is : ";
    stack<int> s;
    s.push(a);
    visit[a] = true;
    while(!s.empty())
    {
        int u = s.top();
        cout<<u<<" ";
        s.pop();
        for(int i = 0; i < adj[u].size();i++)
        {
            if(!visit[adj[u][i]])
            {
                s.push(adj[u][i]);
                visit[adj[u][i]] = true;
            }
        }
    }
}
int main()
{
    int n,m;
    cout<<"enter the no. of vertices : ";
    cin>>n;
    vector<int> adj[n];
    vector<bool> visit(n,false);
    cout<<"enter the no. of edges : ";
    cin>>m;
    int a,b;
    for(int i = 0; i < m; i++)
    {
        cout<<"enter source and destination : ";
        cin>>a>>b;
        add(adj,a,b);
    }
    cout<<"enter the source vertice for BFS : ";
    cin>>a;
    BFS(a,adj,visit);
    cout<<"\n";
    cout<<"enter the source vertice for DFS : ";
    cin>>a;
    visit = vector<bool>(n,false);
    DFS(a,adj,visit);
}
