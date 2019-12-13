// Bryan Kim
// bjk3yf
// 09/07/19
// ListItr.cpp

#include <iostream>
#include "ListNode.h"
#include "ListItr.h"
#include "List.h"

using namespace std;

ListItr :: ListItr() {
  current = new ListNode;
}
ListItr:: ListItr(ListNode* theNode) {
  current = theNode;
}
bool ListItr::isPastEnd() const {
  if(current->next == NULL)
    return true;
  else
    return false;
}
bool ListItr::isPastBeginning() const{
  if(current->previous == NULL)
    return true;
  else
    return false;
}
void ListItr:: moveForward(){
  if(current->next!=NULL){
    current = current->next;
    }
}
void ListItr:: moveBackward(){
  if(current->previous!=NULL){
    current = current->previous;
   }
}
int ListItr:: retrieve()const{
  return current->value;
}

