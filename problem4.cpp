// problem4.cpp
#include <iostream>
#include "problem4.hpp"


namespace
{
    int int_cap = 5;
    int dub_cap = 5;

    void CopyIntArray(int* target, int* source, int size)
    {
        for (int i =0; i<size; ++i)
        {
            target[i] = source[i];
        }
    }
    void CopyDoubleArray(double* target, double* source, int size)
    {
        for (int i =0; i<size; ++i)
        {
            target[i] = source[i];
        }
    }
}

DynamicPair::DynamicPair()
    :int_array{new int[int_cap]}, dub_array{new double[dub_cap]}, int_size{0}, dub_size{0}
{
    
}


DynamicPair::DynamicPair(const DynamicPair& to_copy )
    : int_array{to_copy.int_array}, dub_array{to_copy.dub_array}, int_size{0}, dub_size{0}
{
    CopyDoubleArray(to_copy.dub_array,dub_array,this->dub_size);
    CopyIntArray(to_copy.int_array, int_array,this->int_size);
}


DynamicPair& DynamicPair::operator=(const DynamicPair& to_copy)
{
    if (this != &to_copy)
    {
        int* int_new_array = new int[to_copy.int_size];
        double* double_new_array = new double[to_copy.dub_size];
        CopyIntArray(to_copy.int_array,int_array,this->int_size);
        CopyDoubleArray(to_copy.dub_array,dub_array,this->dub_size);

        int_size = to_copy.int_size;
        dub_size = to_copy.dub_size;

        int_array = int_new_array;
        dub_array = double_new_array;

    }
    return *this;
}


void DynamicPair::add_int(const int& integ)
{
    if (integ < 1)
    {
        int_array[int_size] = 1;    
    }
    else
    {
        int_array[int_size] = integ;    
    }
    ++int_size;
    
}

void DynamicPair::add_double(const double& doub)
{
    if (doub >0)
    {
        dub_array[dub_size] = 0;
    }
    else
    {
        dub_array[dub_size] = doub;
    }
}   


int DynamicPair::int_at(const int& integer_index) const
{
    return int_array[integer_index];
}


double DynamicPair::double_at(const double& double_index) const

{
    return dub_array[int(double_index)];
}