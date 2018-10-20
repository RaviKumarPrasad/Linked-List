
#include<iostream>
#include<string.h>

using namespace std;


template <typename E>
class SNode {
private:
E elem;
SNode<E>* next;
friend class SLinkedList<E>;
};

template <typename E>
class SLinkedList {
public:
SLinkedList();
~SLinkedList();
bool empty() const;
const E& front() const;
void addFront(const E& e);
void removeFront();
private:
SNode<E>* head;
};

template <typename E>
SLinkedList<E>::SLinkedList()
: head(NULL) { } // constructor
template <typename E>
bool SLinkedList<E>::empty() const
{ return head == NULL; } // is list empty?
template <typename E>
const E& SLinkedList<E>::front() const
{ return head->elem; } // return front element
template <typename E>
SLinkedList<E>::~SLinkedList()
{ while (!empty()) removeFront(); } // destructor
template <typename E>
void SLinkedList<E>::addFront(const E& e) {
SNode<E>* v = new SNode<E>;
v->elem = e;
v->next = head;
head = v;
}
template <typename E>
void SLinkedList<E>::removeFront() {
SNode<E>* old = head;
head = old->next;
delete old;
}
