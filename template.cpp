#include <iostream>
#include <vector>
using namespace std ;

template <typename RandomAccess>
void nth_element( RandomAccess start
                , RandomAccess element
                , RandomAccess end )
{
    while(true)
    {
     if(start > --end) break ;

     if( *start > *element )
        if( *element > *end )
           swap( *start , *end );
        else
           swap(*start ,*element) ;
     else 
        if(*element > *end)
          swap(*end ,*element) ;  
     ++start ;
    }
}


int main() {
    std::vector<int> numbers = {3, 7, 2, 1, 5, 6, 4};
    nth_element(numbers.begin(), numbers.begin() + 3, numbers.end());
    for (auto var : numbers)
    cout << var << endl ;
    return 0;
}
