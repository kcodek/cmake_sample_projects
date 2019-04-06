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

std::ostream& operator<< (std::ostream& os, const Customer& c ){
    return os << c.get_name();
}
