#include <iostream>
#include <vector>
using namespace std;

template <typename RandomAccess>
void nth_element(RandomAccess start, RandomAccess element, RandomAccess end) {
   int count{0};
   RandomAccess temp = start ;
    while (true)
     {
      if(++temp == end) break ;
      if(*temp < *element) ++ count ;
     }
   swap(*element , *(start+count)) ;
   return ;
}

int main() {
    std::vector<int> numbers = {4, 1, 2, 5 , 3 ,10 , 0 };
    nth_element(numbers.begin(), numbers.end()-1, numbers.end());
    for (auto var : numbers)
        cout << var << endl;
    return 0;
}
