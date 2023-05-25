#include<bits/stdc++.h>

#define N 100

using namespace std;
vector<int> parent(N);
vector<int> sz(N);

void make(int v)
{
     parent[v]=v;
     sz[v]=1;
}

int find(int v)
{
    if(v == parent[v])
    {
        return v;    
    }
    return parent[v] = find(parent[v]);
}

void Union(int a,int b)
{
     a = find(a);
     b= find(b);
     if(a!=b)
     {
        if(sz[a]< sz[b])
        {
           swap(a,b);
        }
        parent[b]=a;
        sz[a]+=sz[b];
        
     }
}


int main()
{
    int n,e;
    cin>>n>>e;
    vector<pair<int, pair<int,int>>> edges;
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,{u,v}});
    }
    sort(edges.begin(),edges.end());
    for(int i = 1 ; i<=n;i++)
    {
        make(i);
    }
    int min = 0;
    for(auto& edge : edges)
    {
        int w = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if(find(u)!= find(v))
        {
            Union(u,v);
            min+=w;
            cout<<u<<" "<<v<<endl;
        }

    }
    cout<<"minimum weight : "<<min;

    return 0;
}