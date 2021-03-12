#include <iostream>
#include <string>

struct Time
{
    int hour;
    int minute;
    
    Time(int h = 0, int m = 0) : hour(h), minute(m) {}
    Time& operator+= (int i)
    {
        minute += i;
        int h = minute / 60;
        minute -= h * 60;
        hour += h;
        return *this;
    }
    Time operator+ (int i)
    {
        Time ret(*this);
        ret += i;
        return ret;
    }
    Time &operator++ ()
    {
        *this += 1;
        return *this;
    }
};

struct Person
{
    std::string name;
    Time opeBegin;
    int opeUse;
    int opeNum;
    Time recBegin;
    int recUse;
    int recNum;
    int needTime = -1;
};

struct Room
{
    bool canUse;
    bool isAvailable;
    int needTime;
    int usedTime;
    int index;
    Room() : canUse(true), isAvailable(true), needTime(0), usedTime(0), index(-1) {}
};


int main()
{
    // freopen("./in.txt", "r", stdin);
    // freopen("./out.txt", "w", stdout);
    
    int opeCount, recCount, peoCount;
    int transTime, opeTime, recTime;
    int startHour;
    while(std::cin >> opeCount >> recCount >> startHour >>
         transTime >> opeTime >> recTime >> peoCount)
    {
        Time nowTime(startHour);
        int totalMinutes = 0;
        int waitPeople = peoCount;
        int opePeople = 0;
        int trnPeople = 0;
        int recPeople = 0;
        
        Person people[104];
        Room operatingRooms[14];
        Room recoveryRooms[34];
        
        for (int i = 0; i < peoCount; ++i)
        {
            std::cin >> people[i].name >> people[i].opeUse >> people[i].recUse;
        }
        
        while (waitPeople || opePeople || trnPeople || recPeople)
        {
            for (int i = 0; i < opeCount; ++i)
            {
                auto &room = operatingRooms[i];
                if (room.needTime == 0)
                {
                    // clear done
                    if (room.isAvailable)
                    {
                        if (waitPeople)
                        {
                            auto &person = people[peoCount-waitPeople];
                            person.opeNum = i;
                            person.opeBegin = nowTime;
                            
                            room.isAvailable = false;
                            room.needTime = person.opeUse;
                            room.usedTime += person.opeUse;
                            room.index = peoCount-waitPeople;
                            
                            --waitPeople;
                            ++opePeople;
                        }
                    }
                    // use done
                    else
                    {
                        room.isAvailable = true;
                        
                        auto &person = people[room.index];
                        person.needTime = transTime;
                        for (int j = 0; j < recCount; ++j)
                        {
                            auto &rroom = recoveryRooms[j];
                            if (rroom.canUse)
                            {
                                person.recNum = j;
                                
                                rroom.canUse = false;
                                
                                break;
                            }
                        }
                        
                        room.needTime = opeTime;
                        room.index = -1;
                        
                        --opePeople;
                        ++trnPeople;
                    }
                }
                if (room.needTime != 0)
                {
                    --room.needTime;
                }
            }
            
            for (int i = 0; i < peoCount; ++i)
            {
                auto &person = people[i];
                if (person.needTime == 0)
                {
                    --person.needTime;
                    person.recBegin = nowTime;
                    
                    auto &room = recoveryRooms[person.recNum];
                    room.isAvailable = false;
                    room.needTime = person.recUse;
                    room.usedTime += person.recUse;
                    
                    --trnPeople;
                    ++recPeople;
                }
                if (person.needTime > 0)
                {
                    --person.needTime;
                }
            }
            
            for (int i = 0; i < recCount; ++i)
            {
                auto &room = recoveryRooms[i];
                if (room.needTime == 0 && !room.isAvailable)
                {
                    room.isAvailable = true;
                    room.needTime = recTime;
                }
                if (room.needTime != 0)
                {
                    --room.needTime;
                    if (room.needTime == 0 && !room.isAvailable)
                    {
                        --recPeople;
                    }
                    if (room.needTime == 0 && room.isAvailable)
                    {
                        room.canUse = true;
                    }
                }
            }
            
            ++totalMinutes;
            ++nowTime;
        }
        
        printf(" Patient          Operating Room          Recovery Room\n");
        printf(" #  Name     Room#  Begin   End      Bed#  Begin    End\n");
        printf(" ------------------------------------------------------\n");
        for (int i = 0; i < peoCount; ++i)
        {
            auto &person = people[i];
            Time opeBeg = person.opeBegin;
            Time opeEnd = opeBeg + person.opeUse;
            Time recBeg = person.recBegin;
            Time recEnd = recBeg + person.recUse;
            printf("%2d  %-8s  %2d   %2d:%02d   %2d:%02d     %2d   %2d:%02d   %2d:%02d\n", 
                    i+1, person.name.c_str(), person.opeNum+1, opeBeg.hour, opeBeg.minute, opeEnd.hour,
                    opeEnd.minute, person.recNum+1, recBeg.hour, recBeg.minute, recEnd.hour, recEnd.minute);
            
        }
        
        std::cout << std::endl;
        
        printf("Facility Utilization\n");
        printf("Type  # Minutes  % Used\n");
        printf("-------------------------\n");
        for (int i = 0; i < opeCount; ++i)
        {
            auto &room = operatingRooms[i];
            printf("Room %2d    %4d  %6.2lf\n", i+1, room.usedTime, 100.0*room.usedTime/totalMinutes);
        }
        for (int i = 0; i < recCount; ++i)
        {
            auto &room = recoveryRooms[i];
            printf("Bed  %2d    %4d  %6.2lf\n", i+1, room.usedTime, 100.0*room.usedTime/totalMinutes);
        }
        
        std::cout << std::endl;
    }
    return 0;
}