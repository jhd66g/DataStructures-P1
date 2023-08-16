#include "MTFList.h"

// deconstructor
MTFList::~MTFList(){
    // call delete on all reamining nodes
	Node *tmp = head;
	while (head != nullptr){
		head = head->link;
		delete tmp;
		tmp = head;
	}
}

// methods

// adds num to front of list
void MTFList::add(int num){
    // check if head is empty (null)
	if (head == nullptr){
		Node *tmp = new Node(num);
		head = tmp;
	}
	// list is not empty
	else{
		Node *tmp = new Node(num);
		tmp->link = head;
		head = tmp;
	}
	return;
}

// searches for num and adds to front of list
bool MTFList::search(int num){
    Node *curr = head;
    count ++; // first traversal is checking the head
    // if list is empty
    if (head == nullptr){
		return false;
	}
    // num is first
	else if (head->data == num){
		head = head->link;
		delete curr;
        add(num);
        return true;
	}
    // num is not first
    while ((curr->link) != nullptr){
        count ++; // update the count
        if ((curr->link)->data == num){
            Node *tmp;
		    tmp = curr->link;
            curr->link = tmp->link; // link to next node
		    delete tmp;
            add(num);
            return true;
        }
        curr = curr->link; // traversal to next node 
    }
    return false;
}

// returns count
int MTFList::getCount(){
    return count;
}

// prints contents of list
void MTFList::print(){
    // create another node pointer to iterate over list
	Node *curr = head;
	while (curr != nullptr)
	{
		cout << curr->data << " ";
		curr = curr->link; // update curr
	}
	cout << endl;
	return;
}