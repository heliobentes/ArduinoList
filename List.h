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
  void removeAt(int index);
  void toArray(T *&refArray);
  void dispose();

  int find(T item);
  int count();

  T get(int index);


private:
  typedef struct Node
  {
    T item;
    Node *next;
    Node *prev;
  };

  Node *_first;
  Node *_last;
  int _count = 0;
};

#endif