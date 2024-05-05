#ifndef LIST_H
#define LIST_H
#ifndef BASIC_LIB
#define BASIC_LIB
	#include <iostream>
	#include <stdexcept>
#endif 

template <typename T>
class List {
public:
    // Parameterized constructor
    List(int max=200);
    // Destructor
    ~List();
    // Copy constructor
    List(const List &other);
    // Methods
    List<T>& operator=(const List& other);
    bool operator==(const List& other) const;
    T& operator[](int index);
    void append(T item);
    void resize(int new_size);
    void remove(T item);
    void insert(T item, int index);
    int size() const;
    bool is_empty() const;
    bool is_full() const;
    void clear();
    List<T>& display() const;
    List& get_list() const;
    
private:
    T *list;
    int length;
    int max_size;
};

#include "List.cpp"
#endif