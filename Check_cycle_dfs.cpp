#include <bits/stdc++.h>
using namespace std;
bool check_cycle(int v,int e, vector<int> adj[],int start,int parent,vector<int>& visited)
{
    visited[start]=1;
    //cout<<start<<" ";
    for(auto itr:adj[start])
    {
        if(visited[itr]==0)
            {
            if(check_cycle(v,e,adj,itr,start,visited))
                return true;
            }
            
        else
        {
            if(itr!=parent)
            {
                return true;
            }
        }
        
            
    }
    return false;
}

int main() {
    int e,v;
    cin>>v>>e;
    vector<int> adj[v+1];
    for (int i=0;i<e;i++)
    {
        int n,m;
        cin>>n>>m;
        adj[n].push_back(m);
        adj[m].push_back(n);
    }
    vector<int> visited(v+1);
    for(int i=0;i<v;i++)
        visited[i]=0;
        int count=0;
    int flag=0;
    for(int i=0;i<v;i++)
    {
        if(visited[i]==0)
        {
            if(check_cycle(v,e,adj,i,-1,visited))
                {
                    cout<<"Contains Cycle";
                    flag=1;
                    break;
                }
            
        }
    }
    if(flag==0)
        cout<<"Doesnot Contain Cycle";
}