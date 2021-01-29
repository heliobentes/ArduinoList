/*
  List.h - List implementation for Arduino
  Created by Helio Bentes, January 28, 2021.
*/
#ifndef List_h
#define List_h

template <class T>
class List
{
public:
  List();
  
  void add(T item);
  void remove(T item);
  void removeAll(T item);
  void removeAt(unsigned long index);
  
  unsigned long find(T item);
  unsigned long count();
  
  T get(unsigned long index);
  
  T * toArray();

private:
  typedef struct Node
  {
    T item;
    Node *next;
    Node *prev;
  };

  Node *_first;
  Node *_last;
  unsigned long _count = 0;
};

#endif