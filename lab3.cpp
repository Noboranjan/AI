#include<iostream>
#include <queue>
using namespace std;

int path(int G,int s,int v);
int color[50],time,d[50],p[50],u,v,f[50],n,graph[50][50], GREY=1,WHITE=0,BLACK=-1,s;

int path(int G[50][50],int s,int v)
{
    if(v==s)
    {
        cout<<s<<"->";
    }
    else if(p[v] < 0)
    {
        cout<<"no path";
    }
    else
    {
        path(G,s,p[v]);
        cout<<v<<"->";
    }
}

int BFS (int G[50][50],int s)
{

	queue<int> newqueue;
	newqueue.push (s);
	while (!newqueue.empty())
    {
		u = newqueue.front();
		newqueue.pop();
        for(int v=0;v<n;v++)
        {
            if(graph[u][v]==1)
            {
                if (color[v] == WHITE)
                {
                   color[v] = GREY;
                    d[v] = d[u] + 1;
                    p[v] = u;
                    newqueue.push (v);
                }
            }
        }
		color[u] = BLACK;
	}
}
int main()
{
    cout << "Enter the number of nodes: "<<endl;
    cin >> n;
    int i,j;
    cout<<"enter the value:"<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>graph[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<graph[i][j]<<"  ";
        }
        cout<<endl;

    }
    for (int i=0;i<n;i++)
    {
        color[i] = WHITE;
        d[i]=0;
    }
    cout<<"enter source: ";
    cin>>s;
    BFS(graph,s);
    cout<<"enter destination:"<<endl;
    int v;
    cin>>v;
    path(graph, s, v);

}

/*
4
0 1 1 0
0 0 1 0
1 0 0 1
0 0 0 1
*/


