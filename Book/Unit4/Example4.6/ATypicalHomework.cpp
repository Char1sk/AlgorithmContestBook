#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

class Student
{
public:
    string sid;
    int cid;
    string name;
    int chinese;
    int math;
    int english;
    int program;
    
    int rank;
    int total;
    
    Student(string s, int c, string n, int ch, int ma, int en, int pr) : 
            sid(s), cid(c), name(n), chinese(ch), math(ma), english(en), program(pr), rank(1), total(ch+ma+en+pr) {}
};

vector<Student> students;

void printMenu()
{
    std::cout << "Welcome to Student Performance Management System (SPMS)." << std::endl
              << std::endl
              << "1 - Add" << std::endl
              << "2 - Remove" << std::endl
              << "3 - Query" << std::endl
              << "4 - Show ranking" << std::endl
              << "5 - Show Statistics" << std::endl
              << "0 - Exit" << std::endl
              << std::endl;
}

void addFunction()
{
    // std::cout << std::endl;
    while (true)
    {
        std::cout << "Please enter the SID, CID, name and four scores. Enter 0 to finish." << std::endl;
        string nsid;
        std::cin >> nsid;
        if (nsid == "0")
        {
            break;
        }
        int ncid;
        string nname;
        int nchinese, nmath, nenglish, nprogram;
        std::cin >> ncid >> nname >> nchinese >> nmath >> nenglish >> nprogram;
        bool hasDuplicate = false;
        for (auto &s : students)
        {
            if (s.sid == nsid)
            {
                hasDuplicate = true;
                break;
            }
        }
        if (hasDuplicate)
        {
            std::cout << "Duplicated SID." << std::endl;
        }
        else
        {
            students.emplace_back(nsid, ncid, nname, nchinese, nmath, nenglish, nprogram);
            Student &newStu = *(students.end()-1);
            for (auto &stu : students)
            {
                if (stu.total > newStu.total)
                {
                    ++newStu.rank;
                }
                if (stu.total < newStu.total)
                {
                    ++stu.rank;
                }
            }
        }
    }
}

void removeFunction()
{
    // std::cout << std::endl;
    while (true)
    {
        std::cout << "Please enter SID or name. Enter 0 to finish." << std::endl;
        string key;
        std::cin >> key;
        if (key == "0")
        {
            break;
        }
        int removeCount = 0;
        if (key[0] >= 'A' && key[0] <= 'Z')
        {
            while (true)
            {
                auto it = std::find_if(students.begin(), students.end(), 
                        [key](const Student &s){return s.name == key;});
                if (it != students.end())
                {
                    int t = it->total;
                    students.erase(it);
                    ++removeCount;
                    for (auto &stu : students)
                    {
                        if (stu.total < t)
                        {
                            --stu.rank;
                        }
                    }
                }
                else
                {
                    break;
                }
            }
            printf("%d student(s) removed.\n", removeCount);
        }
        else
        {
            auto it = std::find_if(students.begin(), students.end(), 
                    [key](const Student &s){return s.sid == key;});
            if (it != students.end())
            {
                int t = it->total;
                students.erase(it);
                ++removeCount;
                for (auto &stu : students)
                {
                    if (stu.total < t)
                    {
                        --stu.rank;
                    }
                }
            }
            printf("%d student(s) removed.\n", removeCount);
        }
        
    }
}

void queryFunction()
{
    // std::cout << std::endl;
    while (true)
    {
        std::cout << "Please enter SID or name. Enter 0 to finish." << std::endl;
        string key;
        std::cin >> key;
        if (key == "0")
        {
            break;
        }
        if (key[0] >= 'A' && key[0] <= 'Z')
        {
            for (auto &stu : students)
            {
                if (stu.name == key)
                {
                    printf("%d %s %d %s %d %d %d %d %d %.2lf\n", stu.rank, stu.sid.c_str(), stu.cid, stu.name.c_str(), 
                            stu.chinese, stu.math, stu.english, stu.program, stu.total, stu.total/4.0+1e-5);
                }
            }
        }
        else
        {
            for (auto &stu : students)
            {
                if (stu.sid == key)
                {
                    printf("%d %s %d %s %d %d %d %d %d %.2lf\n", stu.rank, stu.sid.c_str(), stu.cid, stu.name.c_str(), 
                            stu.chinese, stu.math, stu.english, stu.program, stu.total, stu.total/4.0+1e-5);
                }
            }
        }
    }
}

void rankingFunction()
{
    // std::cout << std::endl;
    std::cout << "Showing the ranklist hurts students' self-esteem. Don't do that." << std::endl;
}

void statisticsFunction()
{
    // std::cout << std::endl;
    int subTotalScore[4] {0};
    int subPassCount[4] {0};
    int passCount[5] {0};
    
    std::cout << "Please enter class ID, 0 for the whole statistics." << std::endl;
    int classID;
    std::cin >> classID;
    int totalNum = 0;
    for (auto &stu : students)
    {
        if (classID == 0 || stu.cid == classID)
        {
            ++totalNum;
            subTotalScore[0] += stu.chinese;
            subTotalScore[1] += stu.math;
            subTotalScore[2] += stu.english;
            subTotalScore[3] += stu.program;
            subPassCount[0] += stu.chinese >= 60;
            subPassCount[1] += stu.math >= 60;
            subPassCount[2] += stu.english >= 60;
            subPassCount[3] += stu.program >= 60;
            ++passCount[(stu.chinese>=60) + (stu.math>=60) + (stu.english>=60) + (stu.program>=60)];
        }
    }
    passCount[3] += passCount[4];
    passCount[2] += passCount[3];
    passCount[1] += passCount[2];
    string subjectNames[4] {"Chinese", "Mathematics", "English", "Programming"};
    for (int i = 0; i < 4; ++i)
    {
        std::cout << subjectNames[i] << std::endl;
        printf("Average Score: %.2lf\n", 1.0*subTotalScore[i]/totalNum+1e-5);
        printf("Number of passed students: %d\n", subPassCount[i]);
        printf("Number of failed students: %d\n\n", totalNum-subPassCount[i]);
    }
    std::cout << "Overall:" << std::endl;
    std::cout << "Number of students who passed all subjects: " << passCount[4] << std::endl;
    std::cout << "Number of students who passed 3 or more subjects: " << passCount[3] << std::endl;
    std::cout << "Number of students who passed 2 or more subjects: " << passCount[2] << std::endl;
    std::cout << "Number of students who passed 1 or more subjects: " << passCount[1] << std::endl;
    std::cout << "Number of students who failed all subjects: " << passCount[0] << std::endl;
    std::cout << std::endl;
}

int main()
{
    // freopen("./in.txt", "r", stdin);
    // freopen("./out.txt", "w", stdout);
    
    while (true)
    {
        printMenu();
        int command;
        std::cin >> command;
        switch (command)
        {
        case 1:
            addFunction();
            break;
        case 2:
            removeFunction();
            break;
        case 3:
            queryFunction();
            break;
        case 4:
            rankingFunction();
            break;
        case 5:
            statisticsFunction();
            break;
        case 0:
            goto End;
            break;
        default:
            break;
        }
    }
    End:
    return 0;
}