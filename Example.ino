#include "List.h"

List<int> ids;

List<char*> names;

List<int*> arrayOfInts;

void setup()
{

    Serial.begin(115200);

    Serial.println("Starting...");
    for (unsigned long i = 0; i < 100; i++)
    {
        ids.add(i);
    }
    names.add("John Doe");
    int arrayToAdd[] = {1,2,3,4};
    arrayOfInts.add(arrayToAdd);
}

void loop()
{
    Serial.print("Size: ");
    Serial.println(ids.count());
    ids.removeAll(555);
    ids.removeAt(99);
    ids.remove(12);
    ids.add(12345);
    for (unsigned long i = 0; i < ids.count(); i++)
    {
        Serial.println(ids.get(i));
    }
    Serial.print("Size: ");
    Serial.println(ids.count());
    Serial.print("Array: ");
    int *array = ids.toArray();
    for (size_t i = 0; i < ids.count(); i++)
    {
        Serial.print(array[i]);
        Serial.print(" ");
    }
    Serial.println();

   Serial.print("Number of names: ");
   Serial.println(names.count());
    for (unsigned long i = 0; i < names.count(); i++)
    {
        Serial.println(names.get(i));
    }
    Serial.print("Number of arrays: ");
   Serial.println(arrayOfInts.count());
    for (unsigned long i = 0; i < arrayOfInts.count(); i++)
    {
        int arrayToPrint[4];
        
        memcpy(arrayToPrint, arrayOfInts.get(i),4);
        for (int j = 0; j < 4; j++)
        {
            /* code */
    
        Serial.println(arrayToPrint[j]);
            /* code */
        }
        
    }
    delay(10000);
}