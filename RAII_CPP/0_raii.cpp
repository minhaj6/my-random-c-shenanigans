#include <iostream>
#include <memory>

// struct with constructor and destructor
struct Resource{
    Resource() { std::cout << "Resource object created!\n"; }
    ~Resource() { std::cout << "Resource object destroyed!\n"; }
};

int main() {
    /* non raii approach */
    Resource *r1 = new Resource; 
    // some code
    delete r1; // free the resource 
        
    
    /* smart pointer approach */
    std::unique_ptr<Resource> r2(new Resource);
    // both constructor and destructor is called

    return 0;
}