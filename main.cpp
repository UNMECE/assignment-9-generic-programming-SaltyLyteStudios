#include "Classes.h"

int main()
{
    int list[4] = {2, 3, 4 ,5};
    GenericArray<int>Array(list,4);
    std::cout<<"Original Array: "<<Array;

    Array.addElement(1);
    std::cout<<"\nAdded element {1}: "<<Array;
    std::cout<<"\nsum of array: " << Array.sum();
    std::cout<<"\nmax of array: " << Array.max();
    std::cout<<"\nmin of array: " << Array.min();

    int list2[3] = {7,8,9};
    Array.addElements(list2,3);
    std::cout<<"\nAdded elements{7,8,9} simultaneously: "<<Array;
    
    
    int* list4 = Array.slice(4,6);
    
    GenericArray<int>newArray(Array.slice(4,6),3);
    std::cout<<"\nArray.slice(4,6): " <<newArray;




    return 0;
}