#include<iostream>
#include<vector>
using namespace std;
bool check(vector< vector<long int> > &graph)
{
    for(int i=0;i<graph.size();i++)
        if(graph[i][i] != 0)
            return false;
    return true;
}
int main()
{
	int n,m;
	long int mini = 32165478;
	cin>>n>>m;
	vector< vector<long int> > graph(n, vector<long int>(n));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i!=j)
				graph[i][j] = 32165478;
			else
				graph[i][j] = 0;
		}
	}
	for(int i=0;i<m;i++)
	{
		int v1,v2,w;
		cin>>v1>>v2>>w;
		graph[v1-1][v2-1] = w;
	}
	for(int k=0;k<n;k++)
	{
		for(int i =0;i<n;i++){
			for(int j=0;j<n;j++){
				if(graph[i][j]>graph[i][k] + graph[k][j])
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}
    if(check(graph))
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                mini = min(mini,graph[i][j]);
        cout<<mini;
    }
    else
        cout<<"NULL";

}
