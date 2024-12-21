#include <gsl/gsl>
#include <gsl/pointers>
#include <iostream>

int main(int /*unused*/, char ** /*unused*/)
{
    std::cout << "Hello, from Phonons!\n";

    const int VAL = 42;
    gsl::owner<int *> ptr = new int(VAL);
    std::cout << "ptr: " << *ptr << '\n';
    delete ptr;

    return 0;
}
