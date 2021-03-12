#include <iostream>
#include <string>

struct Cube
{
    std::string content;
    char top;
    char bot;
    std::string faces;
    
    bool operator==(const Cube &c)
    {
        // std::cout << (top == c.top) << (bot == c.top) << (faces == c.faces) << std::endl;
        return (top == c.top) && (bot == c.bot) && (faces == c.faces);
    }
    
    Cube(std::string s) : content(s), top(s[0]), bot(s[5])
    {
        faces += s[2];
        faces += s[1];
        faces += s[3];
        faces += s[4];
    }
    void setTop(int t)
    {
        switch (t)
        {
        case 0:
            top = content[0];
            bot = content[5];
            faces = std::string(
                {content[2], content[1], content[3], content[4]});
            break;
        case 1:
            top = content[1];
            bot = content[4];
            faces = std::string(
                {content[0], content[2], content[5], content[3]});
            break;
        case 2:
            top = content[2];
            bot = content[3];
            faces = std::string(
                {content[1], content[0], content[4], content[5]});
            break;
        case 3:
            top = content[3];
            bot = content[2];
            faces = std::string(
                {content[0], content[1], content[5], content[4]});
            break;
        case 4:
            top = content[4];
            bot = content[1];
            faces = std::string(
                {content[0], content[3], content[5], content[2]});
            break;
        case 5:
            top = content[5];
            bot = content[0];
            faces = std::string(
                {content[1], content[2], content[4], content[3]});
            break;
        default:
            break;
        }
    }
    void rotate()
    {
        char ctemp = faces[0];
        faces[0] = faces[1];
        faces[1] = faces[2];
        faces[2] = faces[3];
        faces[3] = ctemp;
    }
};


int main()
{
    std::string line;
    while (std::cin >> line)
    {
        bool isEqual = false;
        Cube cube1(line.substr(0, 6));
        Cube cube2(line.substr(6, 6));
        // std::cout << cube2.top << cube2.faces << cube2.bot << std::endl;
        for (int i = 0; i < 6; ++i)
        {
            cube1.setTop(i);
            for (int j = 0; j < 4; ++j)
            {
                cube1.rotate();
                // std::cout << cube1.top << cube1.faces << cube1.bot << std::endl;
                if (cube1 == cube2)
                {
                    isEqual = true;
                    goto End;
                }
            }
        }
        End:
        std::cout << (isEqual ? "TRUE" : "FALSE") << std::endl;
    }
    return 0;
}