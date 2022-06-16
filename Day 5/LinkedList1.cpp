/*============================================
// Reverse Linked List
============================================*/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) {
	LinkedListNode<int> * prev = nullptr, *cur = head, *next = nullptr;
	while (cur) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}

/*============================================
// Middle Of Linked List
============================================*/

Node *findMiddle(Node *head) {
	Node* fast = head, *slow = head;
	while (fast and fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

/*============================================
// Merge Two Sorted Linked Lists
============================================*/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
	Node<int>* head = new Node<int>(0);
	Node<int> * t = head;
	while (first and second) {
		if (first->data <= second->data) {
			t->next = first;
			t = t->next;
			first = first->next;
		} else {
			t->next = second;
			t = t->next;
			second = second->next;
		}
		t->next = nullptr;
	}
	if (first) {
		t->next = first;
	}
	if (second) {
		t->next = second;
	}
	return head->next;
}

/*============================================
// Delete Kth node From End
============================================*/

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
	if(!head or K == 0) return head;
	LinkedListNode<int>* d = new LinkedListNode<int>(0);
	d->next = head;
	LinkedListNode<int> * fast = d, *slow = d;
	while(K--){
		fast = fast->next;
	}
	while(fast->next){
		fast = fast->next;
		slow = slow->next;
	}
	slow->next =slow->next->next;
	return d->next;
}

/*============================================
// Add Two Numbers As Linked Lists
============================================*/


Node *addTwoNumbers(Node *head1, Node *head2)
{
    
    int c = 0, sum = 0;
    Node* d = new Node(-1);
    Node* t = d;
    while(head1 and head2){
    	sum = head1->data + head2->data + c;
    	c = sum > 9 ? 1 : 0;
    	head1->data = sum % 10;
    	t->next = head1;
    	t = t->next;
    	head1 = head1->next;
    	head2 = head2->next;
    }
    while(head1){
    	sum = head1->data + c;
    	c = sum > 9 ? 1 : 0;
    	head1->data = sum % 10;
    	t->next = head1;
    	t = t->next;
    	head1 = head1->next;
    	
    }
    while(head2){
    	sum = head2->data + c;
    	c = sum > 9 ? 1 : 0;
    	head2->data = sum % 10;
    	t->next = head2;
    	t = t->next;
    	head2 = head2->next;
    }
    if(c){
    	t->next = new Node(c);
    }
    return d->next;
}

/*============================================
// Delete Node In A Linked List in O(1) sol
============================================*/

void deleteNode(LinkedListNode<int> * node) {
    if(!node) return;
    node ->data = node->next->data;
    node->next = node->next->next;
}