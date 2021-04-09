#include <iostream>
#include <string>
#include <vector>
#include <list>

struct Node
{
    bool isDirectory;
    int fileSize;
    int childNow;
    int totalNow;
    int childMax;
    int totalMax;
    std::string name;
    std::list<Node*> children;
    Node() : isDirectory(0), fileSize(0), childNow(0), totalNow(0), childMax(0), totalMax(0), name("") {}
    Node(bool b, int s, const std::string &n) : 
            isDirectory(b), fileSize(s), childNow(0), totalNow(0), childMax(0), totalMax(0), name(n) {}
};

void getPathFiles(std::vector<std::string> &pathFiles, const std::string &path)
{
    std::string nowStr;
    for (int i = 1; i < path.size(); ++i)
    {
        char c = path[i];
        if (c == '/')
        {
            pathFiles.push_back(nowStr);
            nowStr.clear();
        }
        else
        {
            nowStr += c;
        }
    }
    pathFiles.push_back(nowStr);
}

void clearFile(Node *n)
{
    for (Node *p : n->children)
    {
        clearFile(p);
    }
    delete n;
}

int main()
{
    int cmdCnt = 0;
    std::cin >> cmdCnt;
    Node *root = new Node(true, 0, "");
    while (cmdCnt--)
    {
        char cmd;
        std::cin >> cmd;
        bool isSuccess = true;
        switch (cmd)
        {
        case 'C':
        {    
            std::string filePath;
            int fileSize;
            std::cin >> filePath >> fileSize;
            std::vector<std::string> pathFiles;
            getPathFiles(pathFiles, filePath);
            
            Node *now = root;
            std::vector<Node*> history;
            for (auto it = pathFiles.begin(); it != pathFiles.end(); ++it)
            {
                history.push_back(now);
                const std::string &s = *it;
                bool canNew = true;
                // check all children
                for (Node *&np : now->children)
                {
                    if (np->name == s)
                    {
                        canNew = false;
                        // change directory
                        if (np->isDirectory)
                        {
                            // failed
                            if (it == pathFiles.end()-1)
                            {
                                isSuccess = false;
                            }
                            // go on
                            else
                            {
                                now = np;
                            }
                        }
                        else
                        {
                            // check storage
                            if (it == pathFiles.end()-1)
                            {
                                bool canReplace = true;
                                for (Node *hp : history)
                                {
                                    if (hp->totalMax != 0 && hp->totalNow - np->fileSize + fileSize > hp->totalMax || 
                                        hp == now && hp->childMax != 0 && hp->childNow - np->fileSize + fileSize > hp->childMax)
                                    {
                                        isSuccess = false;
                                        canReplace = false;
                                        break;
                                    }
                                }
                                if (canReplace)
                                {
                                    for (Node *hp : history)
                                    {
                                        hp->totalNow -= np->fileSize;
                                        hp->totalNow += fileSize;
                                        if (hp == now)
                                        {
                                            hp->childNow -= np->fileSize;
                                            hp->childNow += fileSize;
                                        }
                                    }
                                    delete np;
                                    np = new Node(0, fileSize, s);
                                }
                            }
                            // failed
                            else
                            {
                                isSuccess = false;
                            }
                        }
                        break;
                    }
                }
                if (!isSuccess)
                {
                    break;
                }
                // no such file
                if (canNew)
                {
                    bool canTouch = true;
                    for (Node *hp : history)
                    {
                        if (hp->totalMax != 0 && hp->totalNow + fileSize > hp->totalMax || 
                            it == pathFiles.end()-1 && hp->childMax != 0 && hp->childNow + fileSize > hp->childMax)
                        {
                            isSuccess = false;
                            canTouch = false;
                            break;
                        }
                    }
                    if (canTouch)
                    {
                        for (Node *hp : history)
                        {
                            hp->totalNow += fileSize;
                            if (it == pathFiles.end()-1 && hp == history.back())
                            {
                                hp->childNow += fileSize;
                            }
                        }
                        Node *last = now;
                        do
                        {
                            int sz = 0;
                            if (it+1 == pathFiles.end())
                            {
                                sz = fileSize;
                            }
                            Node *next =  new Node(!(it == pathFiles.end()-1), sz, *it);
                            next->totalNow += fileSize;
                            if (it+2 == pathFiles.end())
                            {
                                next->childNow += fileSize;
                            }
                            last->children.push_back(next);
                            last = next;
                            ++it;
                        } while (it != pathFiles.end());
                        // last->childNow += fileSize;
                        break;
                    }
                }
            }
            // 路径文件是否存在
                // 是文件，则替换
                        // 查看配额是否足够
                // 是目录，则不替换，失败
            // 路径文件不存在(部分)
                // 尝试创建沿途文件
                    // 查看是否与普通文件冲突
                        // 查看是否配额足够
            break;
        }
        case 'R':
        {
            std::string filePath;
            std::cin >> filePath;
            std::vector<std::string> pathFiles;
            getPathFiles(pathFiles, filePath);
            
            Node *now = root;
            std::vector<Node*> history;
            bool canDelete = true;
            int delChild = 0, delTotal = 0;
            std::list<Node*>::iterator toErase;
            for (auto it = pathFiles.begin(); it != pathFiles.end(); ++it)
            {
                history.push_back(now);
                const std::string &s = *it;
                // for (Node *&np : now->children)
                for (auto nit = now->children.begin(); nit != now->children.end(); ++nit)
                {
                    Node *np = *nit;
                    if (np->name == s)
                    {
                        if (it == pathFiles.end()-1)
                        {
                            delTotal = np->totalNow;
                            if (!np->isDirectory)
                            {
                                delChild = np->childNow;
                            }
                            toErase = nit;
                            clearFile(np);
                        }
                        else
                        {
                            if (np->isDirectory)
                            {
                                now = np;
                            }
                            else
                            {
                                canDelete = false;
                            }
                        }
                        break;
                    }
                    else
                    {
                        canDelete = false;
                        break;
                    }
                }
                if (!canDelete)
                {
                    break;
                }
            }
            if (canDelete)
            {
                for (Node *p : history)
                {
                    if (p == history.back())
                    {
                        p->childNow -= delChild;
                        p->children.erase(toErase);
                    }
                    p->totalNow -= delTotal;
                }
            }
            break;
        }
        case 'Q':
        {
            std::string filePath;
            int newChild, newTotal;
            std::cin >> filePath >> newChild >> newTotal;
            std::vector<std::string> pathFiles;
            getPathFiles(pathFiles, filePath);
            
            if (filePath == "/")
            {
                if ((newChild == 0 || root->childNow <= newChild) && 
                    (newTotal == 0 || root->totalNow <= newTotal))
                {
                    root->childMax = newChild;
                    root->totalMax = newTotal;
                }
                else
                {
                    isSuccess = false;
                }
                break;
            }
            
            Node *now = root;
            // bool canChange = true;
            for (auto it = pathFiles.begin(); it != pathFiles.end(); ++it)
            {
                const std::string &s = *it;
                for (Node *np : now->children)
                {
                    if (np->name == s)
                    {
                        if (it == pathFiles.end()-1)
                        {
                            if (np->isDirectory && 
                                (newChild == 0 || np->childNow <= newChild) && 
                                (newTotal == 0 || np->totalNow <= newTotal))
                            {
                                np->childMax = newChild;
                                np->totalMax = newTotal;
                            }
                            else
                            {
                                isSuccess = false;
                                // canChange = false;
                            }
                        }
                        else
                        {
                            if (np->isDirectory)
                            {
                                now = np;
                            }
                            else
                            {
                                isSuccess = false;
                                // canChange = false;
                            }
                        }
                        break;
                    }
                }
                if (!isSuccess || now->children.empty())
                {
                    isSuccess = false;
                    break;
                }
            }
            // if (canChange)
            // {
            //     for (Node *p : history)
            //     {
            //         if (p == history.back())
            //         {
            //             p->childNow -= delChild;
            //             p->children.erase(toErase);
            //         }
            //         p->totalNow -= delTotal;
            //     }
            // }
            break;
        }
        default:
            break;
        }
        std::cout << (isSuccess ? 'Y' : 'N') << std::endl;
    }
    return 0;
}