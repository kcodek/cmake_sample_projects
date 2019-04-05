#include<iostream>
#include<functional>

//using lambda init captures
int main()
{ 
    // 'out' is initialized as a standard reference wrapper around the result value of calling the insertion operator on the 'cout' global variable with the string "hello"
    // '.get()' method dereferences the reference wrapper
    // invoke the lambda
    [out = std::ref(std::cout<<"Hello " ) ](){out.get() << "World\n";}();
    return 0;
}