#include <bits/stdc++.h>
#define MAX 50
using namespace std;


int func(string str,int cost[][MAX],int n)
{
  int sum=cost[n-1][0];
    int a=n-1,b=0;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='R')
        {
            b=b+1;
        }
        else if(str[i]=='L')
        {
            b=b-1;
        }
        else if(str[i]=='U')
        {
            a=a-1;
        }
        else if(str[i]=='D')
        {
            a=a+1;
        }
        sum+=cost[a][b];
    }
    return sum;  
}


// Function returns true if the
// move taken is valid else
// it will return false.
bool isSafe(int row, int col, int m[][MAX],
				int n, bool visited[][MAX])
{
	if (row == -1 || row == n || col == -1 ||
				col == n || visited[row][col]
						|| m[row][col] == 1)
		return false;

	return true;
}


// paths from (n-1, 0) to (0, n-1).
void printPathUtil(int row, int col, int m[][MAX],
			int n, string& path, vector<string>&
			possiblePaths, bool visited[][MAX])
{
	
	if (row == -1 || row == n || col == -1
			|| col == n || visited[row][col]
						|| m[row][col] == 1)
		return;

	
	if (row == 0 && col == n - 1) {
		possiblePaths.push_back(path);
		return;
	}

	// Mark the cell as visited
	visited[row][col] = true;

	// Try for all the 4 directions (down, left,
	// right, up) in the given order to get the
	// paths in lexicographical order

	// Check if downward move is valid
	if (isSafe(row + 1, col, m, n, visited))
	{
		path.push_back('D');
		printPathUtil(row + 1, col, m, n,
				path, possiblePaths, visited);
		path.pop_back();
	}

	// Check if the left move is valid
	if (isSafe(row, col - 1, m, n, visited))
	{
		path.push_back('L');
		printPathUtil(row, col - 1, m, n,
				path, possiblePaths, visited);
		path.pop_back();
	}

	// Check if the right move is valid
	if (isSafe(row, col + 1, m, n, visited))
	{
		path.push_back('R');
		printPathUtil(row, col + 1, m, n,
				path, possiblePaths, visited);
		path.pop_back();
	}

	// Check if the upper move is valid
	if (isSafe(row - 1, col, m, n, visited))
	{
		path.push_back('U');
		printPathUtil(row - 1, col, m, n,
			path, possiblePaths, visited);
		path.pop_back();
	}

	// Mark the cell as unvisited for
	// other possible paths
	visited[row][col] = false;
}


void printPath(int m[MAX][MAX], int n,string& path, vector<string>&
			possiblePaths)
{
	// vector to store all the possible paths
	bool visited[n][MAX];
	memset(visited, false, sizeof(visited));
	
	// Call the utility function to
	// find the valid paths
	printPathUtil(n-1, 0, m, n, path,
					possiblePaths, visited);
	
}

// Driver code
int main()
{   
    int n;
    cout<<"Enter the size of square maze: ";
    cin>>n;
    cout<<endl;
	int m[MAX][MAX],cost[MAX][MAX];
	
	cout<<"Enter the elements of maze"<<endl;
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<n;j++)
	    {
	        cin>>m[i][j];
	    }
	}
	cout<<endl;
	cout<<"Enter the cost of each element in maze"<<endl;
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<n;j++)
	    {
	        cin>>cost[i][j];
	    }
	}
	cout<<endl;
	vector<string> possiblePaths;
	string path;
	printPath(m, n,path,possiblePaths);
	int min=100000000,c;
	string s;
for (int i = 0; i < possiblePaths.size(); i++)
{
		 c=func(possiblePaths[i],cost,n);
		 if(c<min)
		 {
		   min=c;
		   s=possiblePaths[i];
		 }
}
if(min!=100000000)
{
cout<<"shortest path length is "<<min<<endl;
cout<<"Path is : "<<s;
}
else
cout<<"There is no path to traverse!!!!!";
	return 0;
}
