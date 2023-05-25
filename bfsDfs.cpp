#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
#include<list>
#include<stack>
using namespace std;


void bfs(vector<bool> visited,unordered_map<int,list<int>> adj )
{
    int s;
    queue<int >q;
    cout<<"Enter the starting index : ";
    cin>>s;
    q.push(s);
    while(!q.empty())
    {

        int curr = q.front();
        cout<<curr<<" ";
        q.pop();
        visited[curr]=true;
        for(auto it : adj[curr])
        {

            int v = it;
            // cout<<"Adjcent of "<<curr<<"are "<<it<<endl;
            if(!visited[v])
            {
                q.push(v);
                visited[v]=true;
            }
        }
    }
}

void dfs(int n,vector<bool> visited,unordered_map<int,list<int>> adj )
{
   
    stack<int >s;
    
    s.push(n);
    while(!s.empty())
    {

        int curr = s.top();
        cout<<curr<<" ";
        s.pop();
        visited[curr]=true;
        for(auto it : adj[curr])
        {

            int v = it;
            // cout<<"Adjcent of "<<curr<<"are "<<it<<endl;
            if(!visited[v])
            {
                dfs(v,visited,adj);
            }
        }
    }
}
int main()
{
    int n;
    cout<<"Enter the no of vertices : ";
    cin>>n;
    unordered_map<int,list<int>> adj;
    int e;
    cout<<"Enter the no of edges : ";
    cin>>e;
    int u , v , w;
    cout<<"Enter edges (source destination weight)  "<<endl;
    for(int i=0;i<e;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
   
    vector<bool > visited(n,false);
    bfs(visited,adj);
    int start;
    cout<<"Enter the starting index : ";
    cin>>start;
    dfs(start,visited,adj);
    cout<<endl;
    }