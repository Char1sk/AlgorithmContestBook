#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int main()
{
    int total_num = 0;
    while ( (std::cin >> total_num) && total_num )
    {
        vector<int> students;
        for (int i = 0; i < total_num; i++)
        {
            int temp;
            std::cin >> temp;
            students.push_back(temp);
        }
        
        int temp_candy1 = 0;
        int temp_candy2 = 0;
        int round = 0;
        while (*std::max_element(students.begin(), students.end()) != *std::min_element(students.begin(), students.end()))
        {
            for (int i = 0; i < total_num; ++i)
            {
                students[i] /= 2;
                temp_candy1 = students[i];
                students[i] += temp_candy2;
                temp_candy2 = temp_candy1;
            }
            students[0] += temp_candy2;
            for (int i = 0; i < total_num; ++i)
            {
                students[i] += students[i] % 2;
            }
            temp_candy1 = 0;
            temp_candy2 = 0;
            ++round;
        }
        std::cout << round << ' ' << students[0] << std::endl;
    }
    
    return 0;
}