#include <iostream>
#include <vector>
#include <deque>
#include <string>

enum Type
{
    INPUT, NOT, AND, OR, XOR, NAND, NOR
};

struct Node
{
    Type type;
    bool output;
    int indegree;
    bool visited;
    Node() : type(INPUT), output(0), indegree(0), visited(false) {}
    void init()
    {
        if      (type == NOT )
        {
            output = false;//
        }
        else if (type == AND )
        {
            output = true;
        }
        else if (type == OR  )
        {
            output = false;
        }
        else if (type == XOR )
        {
            output = false;
        }
        else if (type == NAND)
        {
            output = false;
        }
        else if (type == NOR )
        {
            output = true;
        }
        else
        {
            output = false;
        }
    }
    void setType(const std::string &s)
    {
        if      (s == "NOT" )
        {
            type = NOT;
        }
        else if (s == "AND" )
        {
            type = AND;
            output = true;
        }
        else if (s == "OR"  )
        {
            type = OR;
            output = false;
        }
        else if (s == "XOR" )
        {
            type = XOR;
            output = false;
        }
        else if (s == "NAND")
        {
            type = NAND;
            output = false;
        }
        else if (s == "NOR" )
        {
            type = NOR;
            output = true;
        }
    }
    void addInput(bool in)
    {
        if      (type == NOT  )
        {
            output = !in;
        }
        else if (type == AND  )
        {
            if (!in)
                output = false;
        }
        else if (type == OR   )
        {
            if (in)
                output = true;
        }
        else if (type == XOR  )
        {
            if (in)
                output = !output;
        }
        else if (type == NAND )
        {
            if (!in)
                output = true;
        }
        else if (type == NOR  )
        {
            if (in)
                output = false;
        }
    }
};

// Type stringToType(const std::string &s)
// {
//     if      (s == "NOT" )   { return NOT;   }
//     else if (s == "AND" )   { return AND;   }
//     else if (s == "OR"  )   { return OR;    }
//     else if (s == "XOR" )   { return XOR;   }
//     else if (s == "NAND")   { return NAND;  }
//     else if (s == "NOR" )   { return NOR;   }
// }

int main()
{
    int queryCnt;
    std::cin >> queryCnt;
    while (queryCnt--)
    {
        int inputCnt, gateCnt;
        std::cin >> inputCnt >> gateCnt;
        int nodeCnt = inputCnt + gateCnt;
        std::vector<std::vector<bool>> graph(nodeCnt, std::vector<bool>(nodeCnt, false));
        std::vector<Node> nodes(nodeCnt);
        for (int g = 0; g < gateCnt; ++g)
        {
            int gIndex = g+inputCnt;
            std::string typestr;
            int indeg;
            std::cin >> typestr >> indeg;
            Node &node = nodes[gIndex];
            node.setType(typestr);
            node.indegree = indeg;
            while (indeg--)
            {
                std::string in;
                std::cin >> in;
                int delta = (in[0]=='O')*inputCnt;
                int index = in[1]-'1';
                graph[delta+index][gIndex] = true;
            }
        }
        
        std::vector<int> sequence(nodeCnt);
        int sequenceCnt = nodeCnt;
        for (int s = 0; s < nodeCnt; ++s)
        {
            for (int n = 0; n < nodeCnt; ++n)
            {
                Node &node = nodes[n];
                if (!node.visited && node.indegree == 0)
                {
                    sequence[s] = n;
                    node.visited = true;
                    for (int o = 0; o < nodeCnt; ++o)
                    {
                        if (graph[n][o])
                        {
                            --nodes[o].indegree;
                        }
                    }
                    --sequenceCnt;
                    break;
                }
            }
        }
        
        int loopCnt;
        std::cin >> loopCnt;
        std::vector<std::deque<bool>> inputs(loopCnt, std::deque<bool>(inputCnt));
        std::vector<std::vector<int>> outputs(loopCnt);
        for (int l = 0; l < loopCnt; ++l)
        {
            for (int i = 0; i < inputCnt; ++i)
            {
                std::cin >> inputs[l][i];
            }
        }
        for (int l = 0; l < loopCnt; ++l)
        {
            int ocnt;
            std::cin >> ocnt;
            while (ocnt--)
            {
                int itemp;
                std::cin >> itemp;
                outputs[l].push_back(inputCnt+itemp-1);
            }
        }
        
        if (sequenceCnt == 0)
        {
            for (int l = 0; l < loopCnt; ++l)
            {
                // init
                for (int g = inputCnt; g < nodeCnt; ++g)
                {
                    nodes[g].init();
                }
                for (int in = 0; in < inputCnt; ++in)
                {
                    nodes[in].output = inputs[l][in];
                }
                for (int s = inputCnt; s < nodeCnt; ++s)
                {
                    int gindex = sequence[s];
                    Node &gate = nodes[gindex];
                    for (int j = 0; j < nodeCnt; ++j)
                    {
                        if (graph[j][gindex])
                        {
                            gate.addInput(nodes[j].output);
                        }
                    }
                }
                for (int iidx = 0; iidx < outputs[l].size(); ++iidx)
                {
                    printf("%d%c", nodes[outputs[l][iidx]].output, (iidx == outputs[l].size()-1 ? '\n' : ' '));
                }
            }
        }
        else
        {
            std::cout << "LOOP" << std::endl;
        }
        
        // std::cout << std::endl;////
    }
    return 0;
}