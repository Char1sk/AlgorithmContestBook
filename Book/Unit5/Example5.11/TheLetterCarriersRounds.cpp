#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

std::pair<std::string, std::string> parseAddress(const std::string &addr)
{
    int index = addr.find('@');
    std::string s1(addr, 0, index);
    std::string s2(addr, index+1);
    return {s1, s2};
}

int main()
{
    // freopen("./in.txt", "r", stdin);
    // freopen("./out.txt", "w", stdout);
    
    std::map<std::string, std::string> peopleToPlace;
    std::string designation;
    while ((std::cin >> designation) && designation != "*")
    {
        std::string place;
        int peopleCount;
        std::cin >> place >> peopleCount;
        while (peopleCount--)
        {
            std::string name;
            std::cin >> name;
            peopleToPlace[name] = place;
        }
    }
    
    std::string sender;
    while ((std::cin >> sender) && sender != "*")
    {
        auto senderPair = parseAddress(sender);
        std::string senderName = senderPair.first;
        std::string senderPlace = senderPair.second;
        
        std::vector<std::pair<std::string, std::string>> recievers;
        std::set<std::pair<std::string, std::string>> noRepeat;
        std::string reciever;
        while ((std::cin >> reciever) && reciever != "*")
        {
            auto pa = parseAddress(reciever);
            if (noRepeat.find(pa) == noRepeat.end())
            {
                noRepeat.insert(pa);
                recievers.push_back(pa);
            }
        }
        
        std::vector<std::string> data;
        std::string line;
        getchar();
        while ((std::getline(std::cin, line)) && line != "*")
        {
            data.push_back(line);
        }
        
        std::set<std::string> places;
        for (int i = 0; i < recievers.size(); ++i)
        {
            auto &p = recievers[i];
            if (places.find(p.second) == places.end())
            {
                places.insert(p.second);
                printf("Connection between %s and %s\n", senderPlace.c_str(), p.second.c_str());
                printf("     HELO %s\n", senderPlace.c_str());
                printf("     250\n");
                printf("     MAIL FROM:<%s@%s>\n", senderName.c_str(), senderPlace.c_str());
                printf("     250\n");
                
                bool hasUser = false;
                for (int j = i; j < recievers.size(); ++j)
                {
                    auto &rp = recievers[j];
                    if (rp.second == p.second)
                    {
                        printf("     RCPT TO:<%s@%s>\n", rp.first.c_str(), rp.second.c_str());
                        if (peopleToPlace[rp.first] == p.second)
                        {
                            hasUser = true;
                            printf("     250\n");
                        }
                        else
                        {
                            printf("     550\n");
                        }
                    }
                }
                
                if (hasUser)
                {
                    printf("     DATA\n");
                    printf("     354\n");
                    for (auto &s : data)
                    {
                        printf("     %s\n", s.c_str());
                    }
                    printf("     .\n");
                    printf("     250\n");
                }
                
                printf("     QUIT\n");
                printf("     221\n");
            }
        }
    }
    return 0;
}