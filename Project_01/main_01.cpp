#include<iostream>
#include<fstream>
#include<iomanip>

using std::cout;


int main(){

    std::cout<<"Hello World!"<< std::endl;

    // http://www.cplusplus.com/forum/unices/118708/
    // uint8_t val;
    char val;
    std::ifstream file;

    file.open("test.txt");
    file.read(&val,sizeof(uint8_t));  // read 1 byte from the file
    std::cout << std::hex << std::setw(2) << std::setfill('0') << int(val);  // print it as 2-digit hex // ex: Z=0x5a


    return 0;
}