#include <iostream>
#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::list;

class Graph {

private:

	int N;
	list<int>* next;

public:

	Graph(int N);
	void AddEdge(int n, int x);
	void BFS(int start);
};

Graph::Graph(int N) {

	this->N = N;
	next = new list<int>[N];
}

void Graph::AddEdge(int n, int x) {

	next[n].push_back(x);
}

void Graph::BFS(int start) {

	bool* visited = new bool[N];
	for (int i = 0; i < N; i++) {
	
		visited[i] = false;
	}

	list<int> queue;
	visited[start] = true;
	queue.push_back(start);
	
	list<int>::iterator i;

	while (!queue.empty()) {

		start = queue.front();
		cout << start << " ";
		queue.pop_front();

		for (i = next[start].begin(); i != next[start].end(); ++i) {

			if (!visited[*i]){

				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}

int main()
{
	int n;

	Graph g(11);
	g.AddEdge(1, 2);
	g.AddEdge(1, 3);
	g.AddEdge(1, 4);
	g.AddEdge(2, 5);
	g.AddEdge(2, 6);
	g.AddEdge(3, 7);
	g.AddEdge(7, 10);
	g.AddEdge(7, 11);
	g.AddEdge(4, 8);
	g.AddEdge(4, 9);

	cout << "Choose the begining node for BFS :" << endl;
	cin >> n;

	g.BFS(n);
}