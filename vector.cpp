#include <iostream>
#include <vector>


int main()
{
   std::vector<int> vect{ 10, 20, 30 };
   for (int x : vect)
        std::cout << x << " ";
}