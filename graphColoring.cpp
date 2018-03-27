#include<iostream>
using namespace std;

int n,e,m;
bool adj[100][100];
int color[100];

void print()
{
    for(int i=0;i<n;i++)
    {
        cout<<i<<"="<<color[i];
        cout<<endl;
    }
}
bool isPossible(int a,int c)
{
    for(int i=0;i<n;i++)
    {

        if(adj[a][i] && color[i]==c)
        {

            return false;
        }
    }
        return true;


}
void mColoring(int k)
{
    for(int c=1;c<=m;c++)
    {
        if(isPossible(k,c))
        {
            color[k]=c;

            if(k+1<n)
            {

                mColoring(k+1);
            }
            else
            {
                print();
                return;
            }
        }
    }
}
int main()
{
    int x,y;
    cin>>n>>e>>m;

    for(int i=0;i<e;i++)
    {
        cin>>x>>y;

        adj[x][y]=true;
        adj[y][x]=true;
    }
    mColoring(0);

    return 0;
}
/*
4
14
3
0 0
0 1
0 3
1 0
1 1
1 2
1 3
2 1
2 2
2 3
3 1
3 0
3 2
3 3
*/

