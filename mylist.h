#ifndef LIST_H
#define LIST_H
#include <cstdio>

class Level;

class List
{
public:
    List()=default;
    void push_back(Level* level);
    Level* at(int index);
    void erase(Level* level);
    void push_front(Level* level);
    void pop_back();
    void pop_front();
    bool isEmpty();
    std::size_t size();
    ~List();

    struct Node
    {
        Node(Level* levels)
            : level(levels)
        {}
        Level* level;
        Node* next = nullptr;
        Node* previous = nullptr;
       // ~Node();
    };

    class Iterator
    {
    public:
        Iterator();
        Iterator(Node* ptr)
            : ptr(ptr)
        {}
        Iterator& operator++();
        Iterator& operator--();
        Level*& operator*();
        bool operator==(const Iterator& other);
        bool operator!=(const Iterator& other);
    private:
        Node* ptr;
    };   
    //Level* begin();
    //Level* end();
    Iterator begin();
    Iterator end();
private:
    Node* start = nullptr;
    std::size_t Size = 0;

};

#endif

