/*========================================
// Intersection of Two Linked Lists
========================================*/

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

/*============================================================
// Cycle Detection in a Singly Linked List
==============================================================*/

bool detectCycle(Node *head)
{
	if (!head) return 0;
	Node * d = new Node(0);
	d->next = head;
	Node* fast = head->next, * slow = d;
	while (fast and fast->next) {
		if (fast == slow) {
			return 1;
		}
		fast = fast->next->next;
		slow = slow->next;
	}
	return 0;
}
/*========================================
// Reverse Nodes in k-Group
========================================*/

class Solution {
public:

	int lengthOfLL(ListNode* head) {
		int cnt = 0;
		while (head) {
			cnt++;
			head = head->next;
		}
		return cnt;
	}

	ListNode* reverseKGroup(ListNode* head, int k) {
		if (!head or !head->next) return head;
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* pre = dummy, *cur = dummy , *nex = dummy;
		int length = lengthOfLL(head);
		while (length >= k) {
			cur = pre ->next;
			nex = cur->next;
			for (int i = 1; i < k; i++) {
				cur->next = nex->next;
				nex->next = pre->next;
				pre->next = nex;
				nex = cur->next;
			}
			pre = cur;
			length -= k;
		}
		return dummy->next;
	}
};

//codestudio code using variable size bucket

int lengthOfLL(Node* head) {
	int cnt = 0;
	while (head) {
		cnt++;
		head = head->next;
	}
	return cnt;
}

Node *getListAfterReverseOperation(Node *head, int n, int b[]) {
	// if (!head or !head->next) return head;
	Node* dummy = new Node(0);
	dummy->next = head;
	Node* pre = dummy, *cur = dummy , *nex = dummy;
	int length = lengthOfLL(head);
	int idx = 0;
	while (idx < n and length >0) {
		cur = pre ->next;
		nex = cur->next;
		int rep = length >= b[idx] ? b[idx] : length;
		if (rep == 0) {
			idx++;
			continue;
		}
		for (int i = 1; i < rep; i++) {
			cur->next = nex->next;
			nex->next = pre->next;
			pre->next = nex;
			nex = cur->next;
		}
		pre = cur;
		length -= rep;
		idx++;
	}
	return dummy->next;
}


/*========================================
// Palindrome Linked List
========================================*/


LinkedListNode<int>* reverseLL(LinkedListNode<int> * head) {
	if (!head or !head->next) return head;
	LinkedListNode<int> * prev = nullptr, * cur = head , * nex = nullptr;
	while (cur) {
		nex = cur ->next;
		cur->next = prev;
		prev = cur;
		cur = nex;

	}
	return prev;
}

bool isPalindrome(LinkedListNode<int> *head) {
	if (!head or !head->next) return 1;
	LinkedListNode<int>* dummy = new LinkedListNode<int>(0);
	dummy->next = head;
	LinkedListNode<int>* fast = dummy, * slow = dummy, * start = head, *mid = dummy;
	while (fast and fast->next) {
		slow = slow->next;
		fast = fast ->next->next;
	}
	slow->next = reverseLL(slow->next);
	mid = slow->next;
	while (mid) {
		if (start->data != mid->data) {
			return 0;
		}
		start = start->next;
		mid = mid->next;
	}
	// slow->next = reverseLL(slow->next);
	return 1;
}

/*================================================================================
// Linked List Cycle II detect and find start of cycle
================================================================================*/


Node *firstNode(Node *head) {
	if (!head or !head->next) return nullptr;
	Node* fast = head, *slow = head;
	slow = slow->next;
	fast = fast->next->next;
	while (fast and fast->next) {
		if (fast == slow) {
			break;
		}
		slow = slow->next;
		fast = fast->next->next;
	}
	if (!fast or !fast->next) return nullptr;
	fast = head;
	while (fast != slow) {
		fast = fast->next;
		slow = slow->next;
	}
	return fast;

}

/*========================================
Flatten A Linked List
========================================*/


// merge with while loop
Node * merge(Node* first, Node* second){
	Node* dummy = new Node(0);
	Node * temp = dummy;
	while(first and second){
		if(first->data <= second->data){
			temp->child = first;
			first = first->child;
		} else{
			temp->child = second;
			second = second->child;
		}
		temp->next = nullptr;
		temp = temp->child;
	}
	if(first){
		temp->child = first;
	}
	if(second){
		temp->child = second;
	}
	return dummy->child;
}

//merge with recursion

Node * merge(Node* first, Node* second){
	if(!first) return second;
	if(!second) return first;
	Node * res = nullptr;
	if(first->data <= second->data){
		res = first;
		res->child = merge(first->child, second);
	} else {
		res = second;
		res->child = merge(first, second->child);
	}
	res->next = NULL;
	return res;
}


Node* flattenLinkedList(Node* head) {
	if (!head or !head->next) return head;
	head->next = flattenLinkedList(head->next);
	head = merge(head,head->next);
	return head;
}

/*
Time Complexity: O(N), where N is the total number of nodes present
Reason: We are visiting all the nodes present in the given list.

Space Complexity: O(1)
Reason: We are not creating new nodes or using any other data structure.
*/