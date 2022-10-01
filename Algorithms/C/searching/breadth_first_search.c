//Gaurang
//https://github.com/gaurang7goel

#include <stdio.h>
#include <conio.h>
#include <limits.h>

// queue implementation:
int queue[1000];
int head = 0, tail = 0, max = 1000;
void push(int val)
{
	if (head == max - 1)
		printf("overflow \n");
	else if (head == 0)
	{
		head = 1;
		tail = 1;
	}
	else
	{
		tail = tail + 1;
	}

	queue[tail] = val;
}

int pop()
{
	int val;
	if (tail == 0)
		printf("underflow \n");
	else if (head == tail)
	{
		val = queue[head];
		head = 0;
		tail = 0;
	}
	else
	{
		val = queue[head];
		head = head + 1;
	}

	return val;
}

// graph implementation:
int adj[1000][1000];
int size;
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

// breadth first search logic:
void bfs(int source, int visited[], int distance[])
{
	for (int i = 0; i < size; i++)
	{
		if (i != source)
		{
			visited[i] = 0;
			distance[i] = INT_MAX;
		}
	}

	visited[source] = 1;
	distance[source] = 0;
	printf("%d \t\t\t %d \n", source, distance[source]);
	push(source);

	while (head != 0)
	{
		int node = pop();
		for (int i = 0; i < size; i++)
		{
			if (adj[node][i] == 1 && !visited[i])
			{
				visited[i] = 1;
				distance[i] = distance[node] + 1;
				push(i);
				printf("%d \t\t\t %d", i, distance[i]);
				printf("\n");
			}
		}
	}
}

// driver code:
int main()
{
	build_graph();

	int source;
	printf("enter source of graph: ");
	scanf("%d", &source);
	int visited[size], distance[size];
	printf("The vertices which are reachable from source are: \nvertex \t\t distance from source \n");
	bfs(source, visited, distance);

	return 0;
}
