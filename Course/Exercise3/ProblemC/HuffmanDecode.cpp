#include <iostream>
#include <string>

struct node
{
    int freq;
    char data;
    node* left;
    node* right;
};


void decode_huff(node *root, std::string s)
{
    std::string ret;
    node *now = root;
    for (char c : s)
    {
        if (c == '0')
        {
            now = now->left;
        }
        else
        {
            now = now->right;
        }
        if (now->left == nullptr && now->right == nullptr)
        {
            ret += now->data;
            now = root;
        }
    }
    std::cout << ret << std::endl;
}

int main()
{
    
    return 0;
}