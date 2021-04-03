#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int arr1[] = {1, 1, 1, 2};
    do
    {
        for (int i : arr1)
        {
            printf("%d ", i);
        }
        printf("\n");
    } while (std::next_permutation(arr1, arr1+4));
    std::cout << "END" << std::endl;
    
    std::vector<int> arr2 = {1, 1, 1, 4, 4, 5};
    do
    {
        for (int i : arr2)
        {
            printf("%d ", i);
        }
        printf("\n");
    } while (std::next_permutation(arr2.begin(), arr2.end()));
    std::cout << "END" << std::endl;
    
    return 0;
}