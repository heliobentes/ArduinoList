<h1 align="center">Arduino List</h1>

<div align="center">

[![Status](https://img.shields.io/badge/status-active-success.svg)]()
[![GitHub Issues](https://img.shields.io/github/issues/heliobentes/ArduinoList)](https://github.com/heliobentes/ArduinoList/issues)
[![GitHub Pull Requests](https://img.shields.io/github/issues-pr/heliobentes/ArduinoList)](https://github.com/heliobentes/ArduinoList/pulls)
[![License](https://img.shields.io/badge/license-Apache-blue.svg)](/LICENSE)

</div>

---

<p align="center"> A Simple List Implementation for Arduino
    <br> 
</p>

- [About](#about)
- [Getting Started](#getting_started)
- [Usage](#usage)
- [TODO](#todo)
- [Authors](#authors)

## About <a name = "about"></a>

This is a very simple implementation of Linked Lists on C++ for Arduino. It was created for those who need to have a more flexible way to work with multiple data than regular arrays.

Arrays sometimes can be dificult to have its size increased. Using Lists you can have any number of items as your SRAM allows.

## Getting Started <a name = "getting_started"></a>

Here you can find how to install and know more about what is supported or not.

### Installing

1.  Download the zip file
2.  Open Arduino IDE
3.  Go to "Sketch => Include Library => Add .ZIP Library..."
4.  Select the Downloaded zip file

### Data types supported

- array - <b>LIMITED</b> support
- bool - Supported
- boolean - Supported
- byte - Supported
- char - Supported
- double - Supported
- float - Supported
- int - Supported
- long - Supported
- short - Supported
- size_t - Supported
- string - <b>NOT</b> supported (yet)
- String() - <b>NOT</b> supported (yet)
- unsigned char - Supported
- unsigned int - Supported
- unsigned long - Supported
- void - NOT supported
- word - Supported
- class - ??? Not tested
- struct - ??? Not tested

## Usage <a name="usage"></a>

After adding the library to your Arduino IDE, include it as follow:

### Basic usage

```
#include <List.h>

//List of ints
List<int> ids;

//List of floats
List<float> prices;

//List of strings
List<char*> names;

void setup() {
  //Adding an id
  ids.add(14);

  //adding a price
  prices.add(12.34);

  //adding a name
  names.add("John Doe");

}

void loop() {
  // put your main code here, to run repeatedly:

}
```

### Methods

- <b>List</b>: Class constructor

  - params:
    - any class type
  - return: nothing

  ```
  //Instantiating a new int List
  List<int> ids;

  //Instantiating a new float List
  List<float> prices;

  //Instantiating a new char array List
  List<char*> ids;

  //Instantiating a new int array List
  List<int*> ids;
  ```

- <b>add</b>: Adding a new element to the end of the List
  - params:
    - item any - The element to insert to the list
  - return: nothing
  ```
  //Adding 123 to the end of the list
  ids.add(123);
  ```
- <b>remove</b>: Remove the first occurence of the item in the List
  - params:
    - item any - The element to be removed from the list
  - return: nothing
  ```
  //Removing the first occurence of 123
  ids.remove(123);
  ```
- <b>removeAll</b>: Remove all occurences of the item in the List
  - params:
    - item any - The element to be removed from the list
  - return: nothing
  ```
  //Removing all ocurrences of 123
  ids.removeAll(123);
  ```
- <b>removeAt</b>: Remove the item on the position defined by the provided index from the List
  - params:
    - index unsigned long - The index to remove from the list
  - return: nothing
  ```
  //Removing the first element
  ids.removeAt(0);
  ```
- <b>get</b>: Getting the element at the provided index
  - params:
    - index unsigned long - The index to retrieve the value. Must be greater than 0 and lass than the number of items in the list
  - return:
    - any - The item
  ```
  //Getting the first element
  int element = ids.get(0);
  ```
- <b>find</b>: Find the index for the given element
  - params:
    - item any - The element to find in the list
  - return:
    - unsigned long - The index of the element. Returns -1 if not found;
  ```
  //Finding the index of 123
  int index = ids.find(123);
  ```
- <b>count</b>: Counting the number of items in the list
  - params: none
  - return:
    - unsigned long - Number of items
  ```
  //Counting the number of itens in the list
  int size = ids.count();
  ```
- <b>toArray</b>: Converts the list into an array
  - params:
    - &array - The array with all list items
  - return: none
  ```
  //Converting to array
  int *idsArray = new int [ids.count()];
  ids.toArray(idsArray);
  //Remember do dispose your array after use
  delete [] idsArray;
  ```
- <b>dispose</b>: Dispose the List to free memory
  - params: none
  - return: none
  ```
  //Free memory
  ids.dispose();
  ```

## Examples

```
#include "List.h"

List<int> ids;

void setup()
{
    //Starting the serial communication
    Serial.begin(9600);

    //Adding 20 numbers to the list
    for (int i = 0; i < 20; i++)
    {
        ids.add(i);
    }
    //Adding more 20 numbers to the list
    for (int i = 0; i < 20; i++)
    {
        ids.add(i);
    }
}

void loop()
{
    //Adding a single item
    ids.add(157);

    //Removing the first number 12 of the list
    ids.remove(12);

    //Removing all number 12 from the list
    ids.removeAll(12);

    //Removing the element on the position 7
    ids.removeAt(7);

    //Getting the size of the list
    int size = ids.count();

    //Looping all elements
    for (int i = 0; i < size; i++)
    {
        Serial.println(ids.get(i));
    }

    //Converting the list to an array
    int *array = ids.toArray();

    delay(10000);
}
```

## TODO <a name = "todo"></a>

- Support to Strings
- Test with struct
- Test with class

## Authors <a name = "authors"></a>

- [@heliobentes](https://github.com/heliobentes) - Idea & Initial work
