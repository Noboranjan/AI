#include <iostream>
#include <string>

using namespace std;

bool result = false;

class Color
{
public:
	int index;
	string name;
};

Color Colors [10];

class Graph {

    public:
		int n;
        int A[100][100];
		int vColor [100];
        Graph(int size = 2)
		{
			int i, j;
			if (size < 2) n = 2;
			else n = size;

			for (i = 0; i < n; ++i)	//creating an ajdacency matrix
			for (j = 0; j < n; ++j)
				A[i][j] = 0;            //setting all values to zero
			for (int i = 0; i < n; i++)
				vColor[i] = 0;
		}

        void addEdge(int x, int y)
		{
			A[x-1][y-1] = A[y-1][x-1] = 1;		//adding the value to the adjacency matrix
		}

		bool isConnected(int x, int y)
		{
			return (A[x-1][y-1] == 1);
		}


       void showGraph ()
	   {
			for (int i = 0 ;i< n;i++)
			{
				for (int j = 0; j<n ;j++)
					cout << A[i][j] << " ";
				cout <<endl;
			}

	   }

	   bool isSafe (int colornumber, int vertex)
		{
			for (int i = 0; i < n; i++)

			 if (A[vertex][i] && colornumber == vColor[i]) return false;  //checking in the row for adjacent nodes

			 return true;
		}

	   bool colorGraph (int vertex, int noOfColor)
	   {

		   if (vertex == n) return true;

		   for (int i = 1 ;i<= noOfColor; i++)
		   {
				if (isSafe (i,vertex))   //if safe coloring it
				{
					vColor[vertex] = i;

					if (colorGraph (vertex + 1, noOfColor)) return true;

					vColor[vertex] = 0;  //backtracking if for any node solution not found makng all zero
				}
		   }

		   return false;
	   }

	   void printSolution (int m)
	   {
		 if (colorGraph (0,m))
		 {
			for (int i = 0; i< n; i++)
			{
				cout << "\nVertex Name : " << i + 1;
				cout << "\nNeighbours ( ";
				for (int j = 0; j< n; j++)
				{
					if (A[i][j]) cout << j+1 << " ";
				}
				cout << ")\nColor Name : " << Colors[vColor [i]-1].name << "\n";
			}
		 }

		 else cout << "not possible";
	   }


};

int main ()
{
	Graph g(10);

    g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 6);
    g.addEdge(2, 7);
	g.addEdge(2, 4);
	g.addEdge(3, 8);
	g.addEdge(3, 5);
	g.addEdge(4, 9);
	g.addEdge(4, 5);
    g.addEdge(5, 10);
	g.addEdge(6, 9);
	g.addEdge(6, 10);
	g.addEdge(7, 8);
	g.addEdge(7, 10);
	g.addEdge(8, 9);

	cout << "Enter the number of colors : ";
	int n;
	cin >> n;

	for (int i = 1;i <=n ;i++)
	{
		cout << "Enter Color " << i << " : ";
		string temp;
		cin >> temp;
		Colors[i-1].index = i;
		Colors[i-1].name = temp;
	}
	g.printSolution (n);
	return 0;
}
