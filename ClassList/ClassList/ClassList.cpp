#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class List {

 private:

	struct Lista{
	
		float value;
		Lista* next;
	};
	
	Lista* head;

public:

	List() {

		head = NULL;
	}

	~List() {};

	void AppendNode(float value);
	void InsertNode(float value);
	void DeleteNode(float value);
	void WriteList();
};

void List::AppendNode(float value) {

	Lista* node, *aux;

	node = new Lista;
	node->value = value;
	node->next = NULL;

	if (head == NULL) {

		head = node;
	}
	else {

		aux = head;
		
		while (aux->next != NULL) {

			aux = aux->next;
		}
		aux->next = node;
	}
}

void List::InsertNode(float value) {

	Lista *node;

	node = new Lista();
	node->value = value;
	node->next = NULL;
	
	Lista* aux = head, *previous = new Lista();

	if (head == NULL) {

		head = node;
		node->next = NULL;
	}
	else {

		while (aux != NULL && aux->value < value) {

			previous = aux;
			aux = aux->next;
		}
	}

	if (previous->value == 0) {

		node->next = head;
		head = node;
	}
	else {

		previous->next = node;
		node->next = aux;
	}
}

void List::DeleteNode(float value) {

	Lista* aux, *previous;

	aux = new Lista();
	previous = new Lista();

	if (head == NULL) {
		return;
	}

	if (head->value == value) {

		aux = head->next;
		delete head;
		head = aux;
	}
	else {

		while (aux != NULL && aux->value != value) {
		
			previous = aux;
			aux = aux->next;
		}

		previous->next = aux->next;
		delete aux;
	}
}

void List::WriteList() {

	Lista* node = head;

	cout << "Lista este : ";

	while (node != NULL) {

		cout << node->value << " ";
		node = node->next;
	}
	cout << endl;
}

int main()
{
	List a;

	a.AppendNode(5);
	a.AppendNode(6);
	a.AppendNode(8);
	a.WriteList();

	a.InsertNode(7);
	a.WriteList();

	a.InsertNode(3.4);
	a.WriteList();

	a.DeleteNode(3.4);
	a.WriteList();
}
