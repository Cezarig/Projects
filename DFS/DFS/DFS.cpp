#include <iostream>
#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::list;

class Graph {

private :

	int N;
	list<int> *next;
	void DFSUtil(int x, bool visited[]); 
public: 

	Graph(int N);
	void AddEdge(int N, int x);
	void DFS(int start);
};

Graph::Graph(int N) {

	this->N = N;
	next = new list<int>[N];
}

void Graph::AddEdge(int N, int x) {

	next[N].push_back(x);
}

void Graph::DFSUtil(int x, bool visited[]) {

	visited[x] = true;
	cout << x << " ";

	list<int>::iterator i;
	for (i = next[x].begin(); i != next[x].end(); i++) {

		if (!visited[*i]) {

			DFSUtil(*i, visited);
		}
	}
}

void Graph::DFS(int x) {

	bool* visited = new bool[x];
	for (int i = 0; i < N; i++) {
		
		visited[i] = false;
	}

	DFSUtil(x, visited);
}

int main()
{
	Graph g(6);
	g.AddEdge(0, 1);
	g.AddEdge(0, 2);
	g.AddEdge(1, 2);
	g.AddEdge(2, 0);
	g.AddEdge(2, 3);
	g.AddEdge(3, 3);

	cout << "Following is Depth First Traversal"
		" (starting from vertex 2) \n";
	g.DFS(2);
}