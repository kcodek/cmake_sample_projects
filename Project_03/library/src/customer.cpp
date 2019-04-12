#include "customer.h"

void Customer::set_name(const std::string& n)
{
        assert(n.size() > 0);
        name_ = std::move(n);
}

std::string& Customer::get_name() && {
        return name_;
}

const std::string& Customer::get_name()const& {
        return name_;
}


// Customer::Customer(/* args */)       
// {
// }

Customer::~Customer()
{
}


std::ostream& operator<< (std::ostream& os, const Customer& c ){
    return os << c.get_name();
}