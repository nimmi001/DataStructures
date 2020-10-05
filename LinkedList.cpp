// LL of integers - tail,size,insert,delete,eleAtPos,reverse, print

#include "bits/stdc++.h"
using namespace std;

using ll = long long;

struct node
{
	ll val;
	node* next;
	node(ll x) : val(x), next(NULL) {}
};

using N = struct node*;

N getTail(N head)
{
	if(!head)
	return head;
	N tail = head;
	while(tail -> next)
	tail = tail -> next;
	return tail;
}

ll getSize(N head)
{
	N temp = head;
	ll sz = 0;
	while(temp)
	{
		temp = temp -> next;
		sz++;
	}
	return sz;
}

// pos index is 1 based
N insertion(N head, ll val, ll pos)
{
	N nn = new node(val);
//	if(pos < 1 || pos > getSize(head) + 1) return head;
	if(pos == 1)
	{
	    nn -> next = head;
		head = nn;
		return head;
	}
	ll cnt = 1;
	N temp = head;
	while(cnt < pos - 1)
	{
		temp = temp -> next;
		cnt++;
	}
	nn -> next = temp -> next;
	temp -> next = nn;
	return head;
}

//pos is 1 based index
N deletion(N head, ll pos)
{
	if(!head) return head;
//	if(pos < 1 || pos > getSize(head)) return head;
	if(pos == 1)
	{
		N toBeDeleted = head;
		head = head -> next;
		delete toBeDeleted;
		return head;
	}
	N temp = head;
	ll cnt = 1;
	while(cnt < pos - 1)
	{
		temp = temp -> next;
		cnt++;
	}
	N toBeDeleted = temp -> next;
	temp -> next = toBeDeleted -> next;
	delete toBeDeleted;
	return head;
}

// pos is 1 based index
ll getElement(N head, ll pos)
{
//	if(pos < 1 || pos > size(head)) return -1;
	ll cnt = 1;
	N temp = head;
	while(cnt != pos)
	{
		temp = temp -> next;
		cnt++;
	}
	return temp -> val;
}

N reverse(N head)
{
	N cur = head, prev = NULL, next;
	while(cur)
	{
		next = cur -> next;
		cur -> next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}

void print(N head)
{
	while(head)
	{
		cout << head -> val << " ";
		head = head -> next;
	}
	cout << endl;
	return;
}

int main()
{
	N head = NULL; // -
	head = insertion(head, 1, 1); // 1
	head = insertion(head, 3, 2); // 1 - 3
	head = insertion(head, 2, 2); // 1 - 2 - 3
	print(head); // 1 - 2 - 3
	head = deletion(head, 1); // 2 - 3
	print(head); // 2 - 3
	cout << getSize(head) << endl; // 2
	head = insertion(head, 1, 1); //1 - 2 - 3
	cout << getTail(head) -> val << endl; // 3
	cout << getElement(head, 2) << endl; // 2
	head = deletion(head, 2); // 1 - 3
	print(head); // 1 - 3
	head = reverse(head); // 3 - 1
	print(head); // 3 - 1
	return 0;
}
