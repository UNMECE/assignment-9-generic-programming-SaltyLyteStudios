#include <iostream>

template <typename DataType>
class GenericArray
{
    private:
        DataType** Array;
        int sizeofArray;
    public:

    GenericArray(DataType initialArray[], int size)
    {
        //std::cout<< "size: " << size <<"\n";
        this->Array = (DataType**)malloc(size*sizeof(DataType*));
        for (int i = 0; i < size; i++)
        {
            this->Array[i] = (DataType*)malloc(sizeof(DataType));
            this->Array[i] = &initialArray[i];
        }
        this->sizeofArray = size;
    }
    void addElement(DataType element)
    {
        //std::cout<<sizeofArray;
        DataType* element_ptr = (DataType*)malloc(sizeof(DataType));
        element_ptr[0] = element;
        DataType** newArray = (DataType**)malloc((sizeofArray + 1)*sizeof(DataType*));
        for (int i = 0; i < sizeofArray; i++)
        {
            newArray[i] = (DataType*)malloc(sizeof(DataType));
            newArray[i] = this->Array[i];
        }
        delete(this->Array);
        this->Array = (DataType**)malloc((sizeofArray + 1)*sizeof(DataType*));
        for (int i = 0; i < sizeofArray; i++)
        {
            this->Array[i] = (DataType*)malloc(sizeof(DataType));
            this->Array[i] = newArray[i];
        }
        delete(newArray);
        this->Array[sizeofArray] = element_ptr;
        this->sizeofArray = sizeofArray + 1;
        //delete(newArray);
    }
    void addElements(DataType* elements, int size)
    {
        DataType** newArray = (DataType**)malloc((sizeofArray + size)*sizeof(DataType*));
        for (int i = 0; i < sizeofArray; i++)
        {
            newArray[i] = (DataType*)malloc(sizeof(DataType));
            newArray[i] = this->Array[i];
        }
        delete(this->Array);
        this->Array = (DataType**)malloc((sizeofArray + size)*sizeof(DataType*));
        for (int i = 0; i < sizeofArray; i++)
        {
            this->Array[i] = (DataType*)malloc(sizeof(DataType));
            this->Array[i] = newArray[i];
        }
        for (int i = 0; i < size; i++)
        {
            this->Array[sizeofArray + i] = (DataType*)malloc(sizeof(DataType));
            this->Array[sizeofArray + i][0] = elements[i];
        }
        delete(newArray);
        this->sizeofArray = sizeofArray + size;      
    }
    DataType at(int location)
    {
        return Array[location][0];
    }
    int size()
    {
        //std::cout<<sizeofArray;
        return sizeofArray;
    }

    DataType sum()
    {
        DataType sum = 0;
        for (int i = 0; i < sizeofArray; i++)
        {
            sum = sum + Array[i][0];
        }
        return sum;
    }

    DataType max()
    {
        DataType max = Array[0][0];
        for (int i = 0; i < sizeofArray; i++)
        {
            if (max < Array[i][0])
            {
                max = Array[i][0];
            }
            
        }
        return max;
        
    }
    DataType min()
    {
        DataType min = Array[0][0];
        for (int i = 0; i < sizeofArray; i++)
        {
            if (min > Array[i][0])
            {
                min = Array[i][0];
            }
            
        }
        return min;
        
    }
    DataType* slice(int first, int last)
    {
        DataType* sliceArray = (DataType*)malloc(sizeof(DataType)*(last - first));
        for (int i = 0; i <= (last - first); i++)
        {
            sliceArray[i] = Array[first-1 + i][0];
            // std::cout<<"\nsliceArray["<< i << "] = " << sliceArray[i];
            // std::cout<<" Array["<< i << "][0] = " << Array[first-1 + i][0];
        }
        return sliceArray;
        
    }
    friend std::ostream& operator<<(std::ostream& os, GenericArray Array)
    {
        os<<"{ ";
        for (int i = 0; i < Array.size(); i++)
        {
            os<< Array.at(i) << " ";
        }
        os << "}";
        return os;
    }
};


