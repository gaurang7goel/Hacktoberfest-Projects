//Gaurang
//https://github.com/gaurang7goel

#include <stdio.h>
#include <conio.h>

int adj[1000][1000];
int size;
int time = 0;

void build_graph()
{
	printf("enter number of vertices: ");
	scanf("%d", &size);

	printf("enter the adjancy matrix for the graph: \n");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			scanf("%d", &adj[i][j]);
		}
	}
}

void dfs_visit(int node, int visited[], int discovery_time[], int finish_time[])
{
	time = time + 1;
	discovery_time[node] = time;
	visited[node] = 1;

	for (int i = 0; i < size; i++)
	{
		if (adj[node][i] == 1 && !visited[i])
		{
			dfs_visit(i, visited, discovery_time, finish_time);
		}
	}

	time = time + 1;
	finish_time[node] = time;
}

void dfs()
{
	int visited[size + 1];
	int discovery_time[size + 1], finish_time[size + 1];
	for (int i = 0; i < size; i++)
	{
		visited[i] = 0;
	}

	for (int j = 0; j < size; j++)
	{
		if (!visited[j])
		{
			dfs_visit(j, visited, discovery_time, finish_time);
		}
	}

	printf("after applying depth first search \nvertex \t\t discovery time \t finish time \n");
	for (int i = 0; i < size; i++)
	{
		printf("%d \t\t %d \t\t\t %d \n", i, discovery_time[i], finish_time[i]);
	}
}

int main()
{
	build_graph();
	dfs();
	return 0;
}
