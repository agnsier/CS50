/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include <string.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
 // n is number of values
bool search(int value, int values[], int n)
{   
    if (n < 0)
    // TODO: implement a searching algorithm
    { 
       return false;
    }
    else
    {
       
        int array_ending = n-1;
        int array_beggining = 0;

        while (array_ending >= array_beggining)
        {
            int middlepoint = (array_beggining + array_ending) / 2;
         
        if (values[middlepoint] == value)
        
            return true;
        
        else if (values[middlepoint] > value)
            array_ending = middlepoint - 1;
        else
            array_beggining = middlepoint + 1;
        }
    }

    return false;
}
    
/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int temporary;
    //itereting through array 
    for (int i = 0; i < n; i++)
    {   //smalest  index is i 
        int smallest_index = i;
        //checking next number in i+1
        for (int j = i+1; j < n; j++)
        {
            if (values[smallest_index] > values[j])
                smallest_index = j;
        }
        // Swap values;
        temporary = values[smallest_index];
        values[smallest_index] = values[i];
        values[i] = temporary;
     
    }
}