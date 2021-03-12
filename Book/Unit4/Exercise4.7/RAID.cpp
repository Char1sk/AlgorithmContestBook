#include <iostream>
#include <string>

char hexes[] {"0123456789ABCDEF"};

std::string toHex(std::string bin)
{
    std::string ret;
    if (bin.size() % 4)
    {
        bin += std::string( 4 - (bin.size() % 4) , '0');
    }
    // std::cout << bin << std::endl;////
    for (int i = 0; i < bin.size()/4; ++i)
    {
        int val = 0;
        for (int j = 0; j < 4; ++j)
        {
            val <<= 1;
            val += bin[i*4+j] - '0';
        }
        ret += hexes[val];
    }
    return ret;
}

int main()
{
    int cases = 0;
    int diskCount;
    int blockSize;
    int blockCount;
    while (std::cin >> diskCount >> blockSize >> blockCount)
    {
        char ctemp;
        std::cin >> ctemp;
        bool evenParity = (ctemp == 'E');
        
        std::string disks[8];
        for (int i = 0; i < diskCount; ++i)
        {
            std::cin >> disks[i];
        }
        
        bool isValid = true;
        std::string data;
        for (int j = 0; j < blockCount; ++j)
        {
            for (int k = 0; k < blockSize; ++k)
            {
                bool isEven = true;
                int xCount = 0;
                for (int i = 0; i < diskCount; ++i)
                {
                    if (disks[i][k+j*blockSize] == '1')
                    {
                        isEven = !isEven;
                    }
                    if (disks[i][k+j*blockSize] == 'x')
                    {
                        ++xCount;
                    }
                }
                
                if ( (xCount > 1) || (xCount == 0 && isEven != evenParity) )
                {
                    isValid = false;
                    goto End;
                }
                
                for (int i = 0; i < diskCount; ++i)
                {
                    if (disks[i][k+j*blockSize] == 'x')
                    {
                        disks[i][k+j*blockSize] = ( (isEven == evenParity) ? '0' : '1');
                        // char toAppend = disks[i][k+j*blockSize];
                        // if (toAppend != 'x')
                        // {
                        //     data += toAppend;
                        // }
                        // else
                        // {
                        //     data += ( (isEven == evenParity) ? '0' : '1');
                        // }
                    }
                }
            }
            
            for (int i = 0; i < diskCount; ++i)
            {
                if (i != j % diskCount)
                {
                    data += disks[i].substr(j*blockSize, blockSize);
                }
            }
        }
        
        End:
        if (isValid)
        {
            printf("Disk set %d is valid, contents are: %s\n", ++cases, toHex(data).c_str());
        }
        else
        {
            printf("Disk set %d is invalid.\n", ++cases);
        }
        
    }
    return 0;
}