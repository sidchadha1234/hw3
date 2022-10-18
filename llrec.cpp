#include "llrec.h"
#include <iostream>

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){

  
  
  Node* temp = head;
  head = NULL;

  if(temp!=nullptr){ //check that temp is not null
    if(temp -> val > pivot){//if it is great or equal to pivot, put it in larger
      larger = temp;
      llpivot(temp->next, smaller, larger->next, pivot);  //recursive call to next place in larger and temp or "head"
    }
    else if(temp -> val <= pivot){ //if it is smaller or equal to pivot, put it in smaller
      smaller = temp;
      llpivot(temp->next, smaller->next, larger, pivot); //recursive call to next place in smaller and temp or "head"
    }else{  //otherwise just make both list nulls (something is wildly off course)
        smaller = NULL;
        larger = NULL;
    }
  }

  }


