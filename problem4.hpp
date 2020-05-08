// problem4.hpp

class DynamicPair
{


public:

    // constructor
    DynamicPair();

    // Copy Constructor
    DynamicPair(const DynamicPair& to_copy);
    
    DynamicPair& operator=(const DynamicPair& to_copy);
 
    void add_int(const int& integ );
    void add_double(const double& doub);

    int int_at(const int& integ_index) const;
    double double_at(const double& double_index) const;


private:
    int* int_array;
    double* dub_array;
    int int_size, dub_size;
};