#include <iostream>
#include <vector>
using namespace std;

template <typename RandomAccess>
void nth_element (  RandomAccess begin 
                    ,RandomAccess index 
                    ,RandomAccess end )
{
    RandomAccess last_little ;
    RandomAccess step = (index == begin) ? ++ begin : begin ;
   if (*step < *index)
            {
                while ( *step < *index 
                        || step == index    
                        && step < end   ) 
                                        ++ step ;
                if(step == end)
                {
                    swap(*index , *(--step));
                    return ;
                }
                last_little = step - 1 ;
            }
    else if (*step == *index)
            {
                last_little = step ;
                while ( *step >= *index 
                        && step < end   ) 
                                        ++ step ;
                if(step != end) 
                {
                    swap(*begin , *step) ;
                    last_little = begin ;
                    
                }
         
            }
   else 
            {
                while ( *step > *index 
                        || step == index  
                        && step < end   ) 
                                        ++ step ;
                if(step == end ) 
                {
                    if(index > begin)
                    swap(*index , *begin) ;
                    return ;
                }
                
                swap(*begin,*step);
                last_little = begin ;
               
            }

    for (step = (step + 1) ; step < end ; ++ step)
        if(*step < *index)
          {  if(++last_little == index) ++ last_little ;
            swap(*(last_little),*step);
          }
         
 
    if(index > last_little) 
        swap(*index ,*(last_little+1));
    else 
        swap(*index ,*(last_little)) ;
}


int main()
{
    vector<int> numbers {9,8,7,6,5,10,-1} ;
    nth_element(numbers.begin(),numbers.begin()+3,numbers.end());

    for (auto var : numbers)
    cout << var << " " ;
    return 0 ;
} 
