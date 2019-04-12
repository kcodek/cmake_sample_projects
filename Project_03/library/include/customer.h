#ifndef CUSTOMER_H
#define CUSTOMER_H

#include<iostream>
#include<string>
#include <cassert>

class Customer
{
private:
    /* data */
    std::string name_;
public:
    // Customer(const std::string& n):name_{n}{
    //     assert(n.size() > 0);
    // }

    Customer(const std::string& n):name_{std::move(n)}{
        assert(n.size() > 0);
    }
    void set_name(const std::string& n);
    std::string& get_name () && ;
    const std::string& get_name ()const& ;
    ~Customer();
    
    friend std::ostream& operator<< (std::ostream& os, const Customer& c);
};



/*
Inline functions are parsed by the compiler, whereas macros are expanded by the preprocessor.       
In The preprocessor macrosthere is no type-checking. While inline functions are actual functions, 
so compiler can keep an eye on type-checking issues to help debugging.
// without inline  Error: ld: 1 duplicate symbol for architecture x86_64
*/
// inline std::ostream& operator<< (std::ostream& os, const Customer& c ){
//     return os << c.get_name();
// }

#endif // CUSTOMER_H