#include <iostream>
#include <string>
#include <list>
#include <map>
#include <algorithm>

struct Book
{
    std::string name;
    std::string author;
    
    Book() : name(""), author("") {}
    Book(const std::string &n, const std::string &a) : name(n), author(a) {}
    
};

bool operator< (const Book &b1, const Book &b2)
{
    return (b1.author < b2.author) || (b1.author == b2.author && b1.name < b2.name);
}

int main()
{
    // freopen("./in.txt", "r", stdin);
    // freopen("./out.txt", "w", stdout);
    
    std::list<Book> shelve;
    std::map<std::string, std::string> nameToAuthor;
    std::string stemp;
    while (std::getline(std::cin, stemp) && stemp != "END")
    {
        int index = stemp.find('"', 1);
        std::string nm(stemp, 0, index+1);
        std::string ah(stemp, index+5);
        shelve.emplace_back(nm, ah);
        nameToAuthor[nm] = ah;
    }
    shelve.sort();
    
    std::list<Book> buffer;
    while ((std::cin >> stemp) && stemp != "END")
    {
        if (stemp == "BORROW")
        {
            getchar();
            std::getline(std::cin, stemp);
            shelve.remove_if( [stemp](const Book &b){ return b.name == stemp; } );
        }
        if (stemp == "RETURN")
        {
            getchar();
            std::getline(std::cin, stemp);
            buffer.emplace_back(stemp, nameToAuthor[stemp]);
        }
        if (stemp == "SHELVE")
        {
            buffer.sort();
            while (!buffer.empty())
            {
                auto prev = shelve.end();
                auto it = shelve.begin();
                bool isLast = true;
                for ( ; it != shelve.end(); prev = it, ++it)
                {
                    if (buffer.front() < *it)
                    {
                        if (prev == shelve.end())
                        {
                            printf("Put %s first\n", buffer.front().name.c_str());
                        }
                        else
                        {
                            printf("Put %s after %s\n", buffer.front().name.c_str(), prev->name.c_str());
                        }
                        shelve.insert(it, buffer.front());
                        buffer.pop_front();
                        isLast = false;
                        break;
                    }
                }
                if (isLast)
                {
                    if (shelve.empty())
                    {
                        printf("Put %s first\n", buffer.front().name.c_str());
                    }
                    else
                    {
                        printf("Put %s after %s\n", buffer.front().name.c_str(), prev->name.c_str());
                    }
                    shelve.insert(it, buffer.front());
                    buffer.pop_front();
                }
            }
            std::cout << "END" << std::endl;
        }
        
    }
    
    return 0;
}