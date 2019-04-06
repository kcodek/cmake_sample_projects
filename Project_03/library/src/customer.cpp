#include "customer.h"

void Customer::set_name(const std::string& n)
{
        assert(n.size() > 0);
        name_ = n;
}

std::string& Customer::get_name(){
        return name_;
}

const std::string& Customer::get_name()const{
        return name_;
}


// Customer::Customer(/* args */)
// {
// }

Customer::~Customer()
{
}
