#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class List {

 private:
	struct node {

		float m_value;
		node* next;
	};

	node* head;

public:

	List() {
		head = NULL;
	}
	~List();
	void AddNode(float value);
	void DeleteNode(int position);
	void SeeList();
};

void List::AddNode(float value) {

	node *Node, *aux;
	Node = new node();
	Node->m_value = value;
	
	if (head == NULL) {
		head = Node;
		head->next = NULL;
	}
	else {
		aux = head;
		while (aux->next){

			aux = aux->next;
		}
		aux->next = Node;
		Node->next = NULL;
	}
}

void List::DeleteNode(int position) {

	node* aux, *previous;

	if (position == 1){

		head->next = head->next->next;
		head = head->next;
	}
	else
	{
		aux = head;
		while (aux->next != NULL && position) {

			previous = aux;
			position--;
			aux = aux->next;
		}
		previous->next = aux->next;
		delete aux;
	}
}

int main()
{
    std::cout << "Hello World!\n"; 
}