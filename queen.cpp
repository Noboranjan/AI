#include<iostream>
#include<stdlib.h>
using namespace std;

#define n 8

int t[n] = {-1};
int sol = 1;


void printsol()
{
	int i,j;
	char crossboard[n][n];

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			crossboard[i][j]='0';
		}
	}
	for(i=0;i<n;i++)
	{
			crossboard[i][t[i]]='Q';
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<< crossboard[i][j] << " ";
		}
		cout<<endl;
	}
}
int empty(int i)
{
	int j=0;
	while((t[i]!=t[j]) && (abs(t[i]-t[j])!=(i-j)) && j<n)
        j++;

	return i==j?1:0; //equal equal 1 or 0
}

void queens(int i)
{
	for(t[i]=0; t[i]<n; t[i]++)
	{
		if(empty(i))
		{
			if(i == (n-1)){
				printsol();
				cout<< endl << "solution " << sol++ << endl;
			}
			else
			queens(i+1);
		}
	}
}



int main()
{
	queens(0);
	return 0;
}
