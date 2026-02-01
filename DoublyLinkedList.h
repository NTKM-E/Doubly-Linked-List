//
//  DoublyLinkedList.h
//
//  Blank version of file for assignment
//
//  Last Updated: 9/10/2025
//

#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#include "ListType.h"

using namespace std;

template <class Type>
class DoublyLinkedList: public ListType<Type> {
public:
    /** DO NOT EDIT  print */
    void print(bool forward) const ;
      //Function to output the data contained in each node.
      //If argument is true list prints forward
    // If forward is false list prints in reverse
    
    /** DO NOT EDIT  search */
    bool search(const Type& searchItem) const;
      //Function to determine whether searchItem is in the list.
      // Returns true if searchItem is in the

    void insertFirst(const Type& newItem);
      //Function to insert newItem at the beginning of the list.
      //newItem becomes head and count is incremented by 1.

    void insertLast(const Type& newItem);
      //Function to insert newItem at the end of the list.
      //newItem becomes tail and count is incremented by 1.
    
    void insertNode(const Type& newItem, int index);
      //Function to insert newItem at the given index.
      // If index is out of range print error
      //newItem becomes element at index and all other elements are shifted.
      // count is incremented by one.
    
    Type replace(const Type& newItem, int index);
      //Function to replace existing item at index with newItem.
      //Returns item that was originally at index
      // If index is out of range print error

    void deleteNode(const Type& deleteItem);
      //Function to delete deleteItem from the list.
      //Postcondition: If found, the node containing
      //               deleteItem is deleted from the list
      //               and count is decremented by 1.
    
};

// This is a very simple version of print to enable students to print
// as much as possible even if some things are working incorrectly during development
template <class Type>
void DoublyLinkedList<Type>::print(bool forward) const
{
    NodeType<Type> *current;
    if (forward){
        current = this->head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
    } else {
        current = this->tail;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->prev;
        }
    }
    cout << endl;
}

template <class Type>
bool DoublyLinkedList<Type>::
                   search(const Type& searchItem) const
{
    NodeType<Type> *current;
    current = this->head;

    while (current != nullptr )
        if (current->data == searchItem)
            return true;
        else{
            current = current->next;
        }
            
    return false;
}

template <class Type>
void DoublyLinkedList<Type>::insertFirst(const Type& newItem){
    
    //TODO: COMPLETE THIS FUNCTION!
    NodeType<Type>* newNode = new NodeType<Type>;
    newNode->data = newItem;
    newNode->prev = nullptr;    

    if (head != nullptr) {
        this->head->prev = newNode;
    }
    newNode->next = head;
    this->head = newNode;
    this->count++;
}

template <class Type>
void DoublyLinkedList<Type>::insertLast(const Type& newItem){
    //TODO: COMPLETE THIS FUNCTION!
    NodeType<Type>* newNode = new NodeType<Type>;
    newNode->data = newItem;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (tail != nullptr) {
        newNode->prev = tail;
        this->tail->next = newNode;
    }
    else {
        this->head = newNode;
    }
    
    this->tail = newNode;
    this->count++;

}

template <class Type>
void DoublyLinkedList<Type>::insertNode(const Type& newItem, int index){
    
    if (index > count-1) {
    
        cout << "Index is too high, not inserted, please use insert at tail or use an index until "<< this->count << "to insert before the tail!" << endl;
        return;
    }
    if (index < 0) {

        cout << "Index is too low, not inserted, please use insert at head or use  index 0 to insert at head"<< endl;
        return;
    }
    NodeType<Type>* newNode = new NodeType<Type>;
    newNode->data = newItem;
    NodeType<Type>* current;
    current = this->head;

    if (current == nullptr) {
        cout << "List has no head, please create one" << endl;
        return;

    }

    int currentIndex=0;
    // I am assuming the index starts from 0!
    

    while (current != nullptr && currentIndex != index)
    {
        current = current->next;
        currentIndex++;
    }
    newNode->next = current;
    
    if (current->prev != nullptr) {
        newNode->prev = current->prev;
        newNode->prev->next = newNode;
    }
    else {
        //if at head
        newNode->prev = nullptr;
        this->head = newNode;
    }
    newNode->next->prev = newNode;
    this->count++;

}

template <class Type>
Type DoublyLinkedList<Type>::replace(const Type& newItem, int index){

        if (index > count-1) {

            cout << "Index is too high, Not replaced" << endl;
            return Type();
            //because it returns a type i need to return something, I looked online an
        }
        if (index < 0) {

            cout << "Index is too low, Not replaced" << endl;
            return Type();
        }
    NodeType<Type>* current;
    current = this->head;
    if (current == nullptr) {
        cout << "List has no head, please create one" << endl;
        return Type();

    }
    int currentIndex = 0;
    Type data;


    while (current != nullptr && currentIndex != index)
    {
        current = current->next;
        currentIndex++;
    }
    
    data = current->data;
    current->data = newItem;
    return data; 

}

template <class Type>
void DoublyLinkedList<Type>::deleteNode(const Type& deleteItem){
    //TODO: COMPLETE THIS FUNCTION!

}

#endif /* DoublyLinkedList_h */
