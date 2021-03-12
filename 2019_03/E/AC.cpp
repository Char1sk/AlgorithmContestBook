#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

struct Student
{
    std::string name;
    int ac_cnt = 0;
    int penalty = 0;
};

bool stu_sort(const Student &s1, const Student &s2)
{
    if(s1.ac_cnt > s2.ac_cnt)
        return true;
    else if(s1.ac_cnt == s2.ac_cnt && s1.penalty < s2.penalty)
        return true;
    else if(s1.ac_cnt == s2.ac_cnt && s1.penalty == s2.penalty && s1.name < s2.name)
        return true;
    else
        return false;
}

Student stu[1000];

int main()
{
    int pro_cnt, pel_per;
    std::cin >> pro_cnt >> pel_per;
    
    int total_cnt = 0;
    while(std::cin >> stu[total_cnt].name)
    {
        for(int i = 0; i != pro_cnt; ++i)
        {
            std::string stemp;
            std::cin >> stemp;
            int pen = std::stoi(stemp);
            if(stemp.find('(') == std::string::npos)
            {
                if(pen > 0)
                {
                    ++stu[total_cnt].ac_cnt;
                    stu[total_cnt].penalty += pen;
                }
            }
            else
            {
                std::istringstream iss(stemp);
                std::getline(iss, stemp, '(');
                std::getline(iss, stemp, ')');
                pen += pel_per * std::stoi(stemp);
                ++stu[total_cnt].ac_cnt;
                stu[total_cnt].penalty += pen;
            }
        }
        // printf("%-10s %2d %4d\n", stu[total_cnt].name.c_str(), stu[total_cnt].ac_cnt, stu[total_cnt].penalty);
        ++total_cnt;
    }
    std::sort(stu, stu+total_cnt, stu_sort);
    for(int i = 0; i != total_cnt; ++i)
    {
        printf("%-10s %2d %4d\n", stu[i].name.c_str(), stu[i].ac_cnt, stu[i].penalty);
    }
    
    
    return 0;
}