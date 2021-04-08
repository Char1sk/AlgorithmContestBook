#include <iostream>
#include <string>
#include <vector>
#include <list>

struct Node
{
    bool isDirectory;
    int fileSize;
    int childMax;
    int totalMax;
    std::string name;
    std::list<Node*> children;
    Node() {}
    Node(bool b, int s, int cm, int tm, const std::string &n) : 
            isDirectory(b), fileSize(s), childMax(cm), totalMax(tm), name(n) {}
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

int main()
{
    int cmdCnt = 0;
    std::cin >> cmdCnt;
    Node *root = new Node(true, 0, 0, 0, "");
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
            for (const std::string &s : pathFiles)
            {
                for (Node *np : now->children)
                {
                    if (np->name == s)
                    {
                        
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
            
            break;
        }
        case 'Q':
        {
            
            break;
        }
        default:
            break;
        }
        std::cout << (isSuccess ? 'Y' : 'N') << std::endl;
    }
    return 0;
}