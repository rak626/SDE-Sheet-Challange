// Intersection of Two Linked Lists

int findIntersection(Node *firstHead, Node *secondHead)
{
	if (!firstHead or !secondHead) return -1;

	Node * a = firstHead, * b = secondHead;

	while (a != b) {
		a = a == NULL ? secondHead : a->next;
		b = b == NULL ? firstHead : b->next;
	}
	return a == NULL ? -1 : a->data;

}

// Cycle Detection in a Singly Linked List

bool detectCycle(Node *head)
{
	if(!head) return 0;
	Node * d = new Node(0);
	d->next = head;
	Node* fast = head->next, * slow = d;
	while(fast and fast->next){
		if(fast == slow){
			return 1;
		}
		fast = fast->next->next;
		slow = slow->next;
	}
	return 0;
}


Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
}