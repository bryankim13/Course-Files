// Bryan Kim
// bjk3yf
// 09.07.19
// List.cpp

#include "ListNode.h"
#include "List.h"
#include "ListItr.h"
using namespace std;

List :: List() {
  count = 0;
  head = new ListNode;
  tail = new ListNode;
  head->next = tail;
  tail->previous = head;
  }
List :: ~List(){
  makeEmpty();
  delete head;
  delete tail;
}
List::List(const List& source) {      // Copy Constructor
    head=new ListNode;
    tail=new ListNode;
    head->next=tail;
    tail->previous=head;
    count=0;
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {       // deep copy of the list

      insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

List& List::operator=(const List& source) { //Equals operator
    if (this == &source)
        return *this;
    else {
        makeEmpty();
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

bool List :: isEmpty() const {
  if(count==0)
    return true;
  else
    return false;
}
void List :: makeEmpty(){
  ListItr pHolder=head->next;
  while(!pHolder.isPastEnd()){
    remove(pHolder.current->value);
    pHolder.moveForward();
  }
}
ListItr List :: first(){
  ListItr pHolder=head->next;
  return pHolder;
}
ListItr List :: last(){
  ListItr pHolder=tail->previous;
  return pHolder;
}
void List :: insertAfter(int x, ListItr position){
  if(position.current!=tail){
    ListItr pHolder=position.current->next;
    position.current->next = new ListNode;
    position.current->next->value = x;
    position.current->next->next = pHolder.current;
    position.current->next->previous = position.current;
    pHolder.current->previous = position.current->next;
    count++;
  }
}
void List :: insertBefore(int x, ListItr position){
  if(position.current!=head){
    ListItr pHolder=position.current->previous;
    position.current->previous = new ListNode;
    position.current->previous->value = x;
    position.current->previous->next = position.current;
    position.current->previous->previous = pHolder.current;
    pHolder.current->next = position.current->previous;
    count++;
  }
}
void List :: insertAtTail(int x){
  ListItr pHolder=tail->previous;
  pHolder.current->next = new ListNode;
  pHolder.current->next->value = x;
  pHolder.current->next->next = tail;
  pHolder.current->next->previous = tail->previous;
  tail->previous = pHolder.current->next;
  count++;
}
void List :: remove(int x){
  if(count!=0){
    ListItr pHolder = find(x);
    if(!pHolder.isPastEnd()){
    pHolder.current->previous->next = pHolder.current->next;
    pHolder.current->next->previous = pHolder.current->previous;
    delete pHolder.current;
    count--;
    }
  }
}
 
ListItr List :: find(int x){
  ListItr pHolder=first();
    while(!pHolder.isPastEnd()){
      if(pHolder.current->value == x){
	return  pHolder;
      }
      pHolder.moveForward();
    }
    return head;
}


int List :: size()const {
  return count;
}

void printList(List& source, bool direction){
  if(source.size()!=0){
    if(direction){
      ListItr pHolder=source.first();
      while(!pHolder.isPastEnd()){
	cout << pHolder.retrieve() << endl;
	pHolder.moveForward();
      }
    }
    else{
      ListItr lHolder=source.last();
      while(!lHolder.isPastBeginning()){
	cout << lHolder.retrieve() << endl;
        lHolder.moveBackward();
      }
    }
  }
}
