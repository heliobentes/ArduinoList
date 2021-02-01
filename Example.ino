#include "List.h"

List<int> ids;

List<char*> names;

List<int*> arrayOfInts;

int count = 0;

void setup()
{

    Serial.begin(115200);

    Serial.println("Starting...");
    for (int i = 0; i < 600; i++)
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
    //ids.removeAll(555);
    //ids.removeAt(0);
    //ids.remove(0);
    for (int i = 0; i < 10; i++)
    {
        ids.add(count++);
    }
    for (int i = 0; i < ids.count(); i++)
    {
        Serial.println(ids.get(i));
    }
    Serial.print("Size: ");
    Serial.println(ids.count());
    Serial.print("Array: ");
    int *idsArray = new int [ids.count()];
    ids.toArray(idsArray);
    for (size_t i = 0; i < ids.count(); i++)
    {
        Serial.print(idsArray[i]);
        Serial.print(" ");
    }
    Serial.println();
    //Remember do dispose your array after use
    delete [] idsArray;

   Serial.print("Number of names: ");
   Serial.println(names.count());
    for (int i = 0; i < names.count(); i++)
    {
        Serial.println(names.get(i));
    }
    Serial.print("Number of arrays: ");
   Serial.println(arrayOfInts.count());
    for (int i = 0; i < arrayOfInts.count(); i++)
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
    //Remember do dispose your List after use
    ids.dispose();
    delay(1000);
}