#include <string>
#include <iostream>
void Inform(const std::string& message)
{
    std::cout<<":-- "<<message<<"\n";
}

void Error(const std::string& message)
{
    std::cout<<"Error: " << message << "\n";
}


void Warning(const std::string& message)
{
    std::cout<<"Warning: " << message << "\n";
}
