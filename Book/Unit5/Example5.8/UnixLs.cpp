#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    // freopen("./in.txt", "r", stdin);
    // freopen("./out.txt", "w", stdout);
    
    int fileCount;
    while (std::cin >> fileCount)
    {
        int maxLen = 0;
        std::vector<std::string> files;
        for (int i = 0; i < fileCount; ++i)
        {
            std::string stemp;
            std::cin >> stemp;
            files.push_back(stemp);
            if (maxLen < stemp.size())
            {
                maxLen = stemp.size();
            }
        }
        std::sort(files.begin(), files.end());
        
        // (maxLen+2)*col - 2 <= 60
        // col <= 62/(maxlen+2)
        // cnt <= row * col
        int col = 62 / (maxLen+2);
        int row = fileCount / col + bool(fileCount % col);
        // int delta = col * row - fileCount;
        std::cout << std::string(60, '-') << std::endl;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (j != 0 && (i+j*row < fileCount))
                {
                    printf("  ");
                }
                if (i+j*row < fileCount)
                {
                    printf("%-s" ,files[i+j*row].c_str());
                    std::cout << std::string(maxLen-files[i+j*row].size(), ' ') ;
                }
            }
            std::cout << std::endl;
        }
    }
    return 0;
}

// 1   5   9
// 2   6   10
// 3   7
// 4   8