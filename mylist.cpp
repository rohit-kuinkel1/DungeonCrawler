#include "myList.h"
#include <iostream>
#include <stdexcept>
#include "Level.h"

List::~List()
{
    while(start != nullptr)
    {
        pop_back();
    }
}

bool List::isEmpty()
{
    if(start==nullptr) //if start itself is pointing to nullptr, list is empty
       return true;
    else
       return false;
}

void List::push_back(Level* level)
{
   Node* tmp = new Node(level);
   Node* current = start;

   if( List::isEmpty() ) //when empty, first elem is tmp
   {
       start = tmp;
       Size++;
       return;
   }

   while(current->next != nullptr) //when not empty,iterate through the list and put tmp at last
   {
      current = current->next;
   }
   current->next = tmp;
   tmp->previous = current;
   Size++;
}

void List::push_front(Level* level)
{
    Node* tmp = new Node(level);
    if( isEmpty() ) //when empty, first element is tmp
    {
        start = tmp;
    }
    else if(start->next == nullptr) //if only one item
    {
        start->next = tmp; //not needed (maybe)
        tmp->previous = start;
    }
    else //if several items, push them back and put tmp at the start
    {
        tmp->next = start;
        start->previous = tmp;
        start = tmp;
    }
    Size++;
    return;
}


void List::pop_front()
{
    if(start == nullptr)
    {
        throw out_of_range{"no elements to pop_front"};
    }
    else if(start->next == nullptr)
    {
        delete start;
        start = nullptr;
        Size = 0;
        return;
    }
    else{
        Node* toBeDeleted = start;
        start = start->next;
        start->previous = nullptr;
        delete toBeDeleted;
        Size--;
        return;
    }

}

void List::pop_back()
{
    if(start == nullptr)
    {
        throw out_of_range {"No elements to pop_back"};
    }
    else if(start->next == nullptr)
    {
        delete start;
        start = nullptr;
        Size = 0;
        return;
    }
    else
    {
        Node* current = start;
        while(current->next != nullptr)
        {
            current = current->next;
        }
        current->previous->next = nullptr;
        delete current;
        Size--;
        start->previous = nullptr;
        return;
    }
}

std::size_t List::size()
{
    return Size;
}

void List::erase(Level* level)
{
    Node* tmp = new Node(level);
    Node* current = start;
    bool isFound = true;

    if(start->level == current->level)
    {
        Node* toBeDeleted = start;
        start = start->next;
        start->previous = nullptr;
        delete toBeDeleted;
        Size--;
        return;
    }

    //iterate for the rest
    while( current->level != tmp->level )
    {
        current = current->next;
        if(!current)
        {
            isFound = false;
            break;
        }
    }
    if( isFound )
    {
        current->previous->next = current->next;
        current->next->previous = current->previous;
        delete current;
        Size--;
    }
    return;
}

Level *List::at(int index)
{
    if( (index < 0) || (index >= int(Size)) ) //when index doesnt exist
        throw std::bad_alloc();

    Node* tmp = start;
    if(!index)
        return start->level;
    for(int i = 0; i < index; i++)
    {
        tmp = tmp->next;
    }
    return tmp->level;
}

List::Iterator List::begin()
{
    return Iterator(start);
}

List::Iterator List::end()
{
    return Iterator(nullptr);
}

List::Iterator &List::Iterator::operator++()
{
    if(ptr->next != nullptr)
    {
        ptr = ptr->next;
        return *this;
    }
    else
    {
         throw std::out_of_range("Out of range");
    }

}

List::Iterator &List::Iterator::operator--()
{
    if(ptr->previous != nullptr)
    {
        ptr = ptr->previous;
        return *this;
    }
    else
    {
        throw std::out_of_range("Cant go lower than 0");
    }
}

Level*& List::Iterator::operator*()
{
    return ptr->level;
}

bool List::Iterator::operator==(const List::Iterator& other)
{
    bool isEqual=false;
    if(ptr==other.ptr)
      isEqual= true;

    return isEqual;
}

bool List::Iterator::operator!=(const List::Iterator &other)
{
    bool isEqual=false;
    if(ptr!=other.ptr)
      isEqual= true;

    return isEqual;
}

