/*
  List.cpp - List implementation for Arduino
  Created by Helio Bentes, January 28, 2021.
*/
#include "Arduino.h"
#include "List.h"
template <class T>
List<T>::List()
{
}

/**
 * Adding a new element to the end of the List
 * @param item any - The element to insert to the list
 **/
template <class T>
void List<T>::add(T item)
{
  //creating a new element
  Node *node = new Node();
  node->item = item;
  node->next = NULL;
  node->prev = NULL;
  //if the list is empty
  if (_count == 0)
  {
    _first = node;
  }
  else
  {
    //Setting the new element's prev as the last existent element
    node->prev = _last;
    //seting the new element as next for the last
    _last->next = node;
  }
  //changing the last element to the new one
  _last = node;
  //Incrementing the counter
  _count++;
}

/**
 * Remove the first occurence of the item in the List
 * @param item any - The element to be removed from the list
 **/
template <class T>
void List<T>::remove(T item)
{
  unsigned long index = find(item);
  if (index >= 0)
  {
    removeAt(index);
  }
}

/**
 * Remove all occurences of the item in the List
 * @param item any - The element to be removed from the list
 **/
template <class T>
void List<T>::removeAll(T item)
{
  unsigned long index = find(item);

  while (index != -1)
  {
    index = find(item);
    removeAt(index);
  }
}

/**
 * Remove the item on the position defined by the provided index from the List
 * @param index unsigned long - The index to remove from the list
 **/
template <class T>
void List<T>::removeAt(unsigned long index)
{
  //execute only if list is not empty and the index is inside the bounds
  if (_count > 0 && index >= 0 && index < _count)
  {
    //interacting until the index
    Node *node = _first;
    
    for (unsigned long i = 0; i < index; i++)
    {
      node = node->next;
    }
    node->next->prev = node->prev;
    node->prev->next = node->next;

    if(index==0){
      _first = node->next;
    }
    if(index==_count-1){
      _last = node->prev;
    }
    delete node;
    _count--;
  }
}
/**
 * Getting the element at the provided index
 * @return any - The item
 * @param index unsigned long - The index to retrieve the value. Must be greater than 0 and lass than the number of items in the list
 **/
template <class T>
T List<T>::get(unsigned long index)
{
  //returning null if list is empty or the index is outside the bounds
  if (_count == 0 || index < 0 || index >= _count)
    return NULL;

  //interacting until the index
  Node *node = _first;
  for (unsigned long i = 0; i < index; i++)
  {
    node = node->next;
  }
  return node->item;
}

/**
 * Find the index for the given element
 * @param item any - The element to find in the list
 * @return unsigned long - The index of the element. Returns -1 if not found;
 **/
template <class T>
unsigned long List<T>::find(T item)
{
  //interacting until the index
  Node *node = _first;
  if (node->item == item)
    return 0;
  for (unsigned long i = 0; i < _count - 1; i++)
  {
    node = node->next;
    if (node->item == item)
      return i + 1;
  }
  return -1;
}

/**
 * Counting the number of items in the list
 * @return unsigned long - Number of items
 **/
template <class T>
unsigned long List<T>::count()
{
  return _count;
}

/**
 * Parse the list into array
 * @return T aray - The array with all list items
 **/
template <class T>
T *List<T>::toArray()
{
  T *array = new T[_count];
  Node *node = _first;
  array[0] = node->item;
  for (unsigned long i = 0; i < _count - 1; i++)
  {
    node = node->next;
    array[i + 1] = node->item;
  }
  return array;
}
// template void List<int>::add(int);
// No need to call this TemporaryFunction() function,
// it's just to avoid link error.
void TemporaryFunction()
{
  List<int> TempObj;
}