#include <iostream>
#include <cmath>

int factors[1000005];
int sumFactors[1000005];

// bool isPrime(int num)
// {
//     for (int i = 2; i <= std::sqrt(num); ++i)
//     {
//         if (num % i == 0)
//         {
//             return false;
//         }
//     }
//     return true;
// }

int main()
{
    // freopen("a.txt", "w", stdout);//
    factors[1] = 1;
    factors[2] = 1;
    sumFactors[0] = 1;
    sumFactors[1] = 1;
    sumFactors[2] = factors[2];
    for(int i = 3; i <= 1000000; ++i)
    {
        bool isPrime = true;
        for (int j = 2; j <= std::sqrt(i); j++)
        {
           if (i % j == 0)
           {
               factors[i] = factors[j] + factors[i/j];
               isPrime = false;
               break;
           }
        }
        if (isPrime)
        {
            factors[i] = 1;
        }
        sumFactors[i] = sumFactors[i-1] + factors[i];
    }
    
    int input;
    while(std::cin >> input)
    {
        std::cout << sumFactors[input] << std::endl;
    }
    
    return 0;
}