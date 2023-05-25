#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<limits.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the no of vertices : ";
    cin>>n;
    unordered_map<int,list<pair<int ,int>>> adj;
    int e;
    cout<<"Enter the no of edges : ";
    cin>>e;
    int u , v , w;
    cout<<"Enter edges (source destination weight)  "<<endl;
    for(int i=0;i<e;i++)
    {
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int> key (n,INT_MAX);
    vector< bool > mst(n,false);
    vector < int > parent(n,-1);

    key[0]=0;
    // mst[0]=true;
    parent[0]=-1;    
    for(int i=0;i<n;i++)
    {
        int min = INT_MAX;
        int u;
        for(int v=0;v<n;v++)
        {
             if(mst[v]==false && key[v]<min)
             {
                u = v;
                min = key[v];
             }
        }
        mst[u]=true;

        for(auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if(mst[v]==false && w < key[v])
            {
                parent[v]=u;
                key[v]=w;
            }

        }
    }
    cout<<"minimum spanning tree (source destination weight) : "<<endl;
    for(int i=1 ; i<n;i++)
    {
        cout<<parent[i]<<" "<<i<<" weight : "<<key[i]<<endl;
    }
    return 0;
}
