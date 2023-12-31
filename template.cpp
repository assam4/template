#include <iostream>
#include <vector>
using namespace std;

template <typename RandomAccess>
void nth_element( RandomAccess start
                , RandomAccess element
                , RandomAccess end) 
{
  while (start != end )
    {
    if  (start > element)
        {
        if  (*start < *element)
        {
            swap(*start ,*element);
            while(element != start)
            {
                if(*element > *(element+1))
                swap(*element , *(element+1));
                ++element;
            }
            
        }
    
    }
    else if (start < element)
        {
        if  (*start > *element)
        {
            swap(*start ,*element);
            element = start ;
        }

        }
        ++start ;
    }
}

template <typename RandomAccess>
void n_smallest_elements(RandomAccess start , size_t n ,RandomAccess end)
{
   auto last_element = (start + n) ;
   
   for (auto i = last_element ; i < end ; ++i)
   {
    for(auto j = start ;j != last_element ; ++ j)
    if(*j > *i) swap(*j , *i);

    
   }
   return ;
}

    
int main ()
{
    vector<int> numbers = {1,3,0 ,2 ,10 ,5 ,-1};
    nth_element(numbers.begin(),numbers.begin()+6,numbers.end());
    for(auto var : numbers)
    cout << var << endl; 
    return 0 ;
}

    
int main ()
{
    vector<int> numbers = {1,3,0 ,2 ,10 ,5 ,-1};
    nth_element(numbers.begin(),numbers.begin()+6,numbers.end());
    for(auto var : numbers)
    cout << var << endl; 
    return 0 ;
}


int main() {
    std::vector<int> numbers = {3, 7, 2, 1, 5, 6, 4};
    nth_element(numbers.begin(), numbers.begin() + 3, numbers.end());
    for (auto var : numbers)
    cout << var << endl ;
    return 0;
}
