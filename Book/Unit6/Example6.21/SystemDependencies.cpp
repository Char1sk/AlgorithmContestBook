#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

std::map<std::string, std::vector<std::string>> dependList;
std::map<std::string, std::vector<std::string>> supportList;
std::list<std::string> installList;
std::map<std::string, bool> inplicitList;

void install(const std::string &toInstall, bool isExplicit)
{
    for (auto &s : dependList[toInstall])
    {
        install(s, false);
    }
    
    if (std::find(installList.begin(), installList.end(), toInstall) == installList.end())
    {
        installList.push_back(toInstall);
        if (!isExplicit)
        {
            inplicitList[toInstall] = true;
        }
        std::cout << "   Installing " << toInstall << std::endl;
    }
    else if(isExplicit)
    {
        std::cout << "   " << toInstall << " is already installed." << std::endl;
    }
}

void remove(const std::string &toRemove, bool isExplicit)
{
    if (std::find(installList.begin(), installList.end(), toRemove) == installList.end())
    {
        if (isExplicit)
        {
            std::cout << "   " << toRemove << " is not installed." << std::endl;
        }
        return;
    }
    
    for (auto &s : supportList[toRemove])
    {
        if (std::find(installList.begin(), installList.end(), s) != installList.end())
        {
            if (isExplicit)
            {
                std::cout << "   " << toRemove << " is still needed." << std::endl;
            }
            return;
        }
    }
    
    installList.remove(toRemove);
    inplicitList[toRemove] = false;
    std::cout << "   Removing " << toRemove << std::endl;
    
    // if (toRemove == "BROWSER")
    // {
    //     // std::cout << "????????????" << std::endl;////
    // }
    
    for (auto &s : dependList[toRemove])
    {
        if (inplicitList[s])
        {
            remove(s, false);
        }
    }
}

int main()
{
    std::string line;
    while (std::getline(std::cin, line))
    {
        std::cout << line << std::endl;
        if (line == "END")
        {
            dependList.clear();
            supportList.clear();
            installList.clear();
            inplicitList.clear();
            continue;
        }
        std::istringstream iss(line);
        std::string cmd;
        iss >> cmd;
        if (cmd == "DEPEND")
        {
            std::string key;
            iss >> key;
            std::string val;
            while (iss >> val)
            {
                dependList[key].push_back(val);
                supportList[val].push_back(key);
            }
        }
        if (cmd == "INSTALL")
        {
            std::string item;
            iss >> item;
            install(item, true);
        }
        if (cmd == "REMOVE")
        {
            std::string item;
            iss >> item;
            remove(item, true);
        }
        if (cmd == "LIST")
        {
            for (auto &s : installList)
            {
                std::cout << "   " << s << std::endl;
            }
        }
    }
    return 0;
}