#include "List.h"

List<int> ids;

void setup()
{

    Serial.begin(115200);

    Serial.println("Starting...");
    for (unsigned long i = 0; i < 100; i++)
    {
        ids.add(i);
    }
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
    delay(10000);
}