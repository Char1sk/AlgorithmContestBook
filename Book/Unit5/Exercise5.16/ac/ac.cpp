#include <bits/stdc++.h>
using namespace std;

#define INIT() ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define For(i,s,t) for (int i = (int)(s); i <= (int)(t); ++i)
#define rFor(i,t,s) for (int i = (int)(t); i >= (int)(s); --i)
#define ForLL(i, s, t) for (LL i = LL(s); i <= LL(t); ++i)
#define rForLL(i, t, s) for (LL i = LL(t); i >= LL(s); --i)
#define foreach(i,c) for (__typeof(c.begin()) i = c.begin(); i != c.end(); ++i)
#define rforeach(i,c) for (__typeof(c.rbegin()) i = c.rbegin(); i != c.rend(); ++i)

#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl

#define LOWBIT(x) ((x)&(-x))

#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define UNIQUE(x) x.erase(unique(x.begin(), x.end()), x.end())
#define REMOVE(x, c) x.erase(remove(x.begin(), x.end(), c), x.end()); // 删去 x 中所有 c
#define TOLOWER(x) transform(x.begin(), x.end(), x.begin(),::tolower);
#define TOUPPER(x) transform(x.begin(), x.end(), x.begin(),::toupper);

#define ms0(a) memset(a,0,sizeof(a))
#define msI(a) memset(a,0x3f,sizeof(a))
#define msM(a) memset(a,-1,sizeof(a))

#define MP make_pair
#define PB push_back
#define ft first
#define sd second

template<typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &p) {
    in >> p.first >> p.second;
    return in;
}

template<typename T>
istream &operator>>(istream &in, vector<T> &v) {
    for (auto &x: v)
        in >> x;
    return in;
}

template<typename T>
ostream &operator<<(ostream &out, vector<T> &v) {
    Rep(i, v.size()) out << v[i] << " \n"[i == v.size() - 1];
    return out;
}

template<typename T1, typename T2>
ostream &operator<<(ostream &out, const std::pair<T1, T2> &p) {
    out << "[" << p.first << ", " << p.second << "]" << "\n";
    return out;
}

inline int gc(){
    static const int BUF = 1e7;
    static char buf[BUF], *bg = buf + BUF, *ed = bg;

    if(bg == ed) fread(bg = buf, 1, BUF, stdin);
    return *bg++;
}

inline int ri(){
    int x = 0, f = 1, c = gc();
    for(; c<48||c>57; f = c=='-'?-1:f, c=gc());
    for(; c>47&&c<58; x = x*10 + c - 48, c=gc());
    return x*f;
}

template<class T>
inline string toString(T x) {
    ostringstream sout;
    sout << x;
    return sout.str();
}

inline int toInt(string s) {
    int v;
    istringstream sin(s);
    sin >> v;
    return v;
}

//min <= aim <= max
template<typename T>
inline bool BETWEEN(const T aim, const T min, const T max) {
    return min <= aim && aim <= max;
}

typedef unsigned int uI;
typedef long long LL;
typedef unsigned long long uLL;
typedef vector< int > VI;
typedef vector< bool > VB;
typedef vector< char > VC;
typedef vector< double > VD;
typedef vector< string > VS;
typedef vector< LL > VL;
typedef vector< VI > VVI;
typedef vector< VB > VVB;
typedef vector< VS > VVS;
typedef vector< VL > VVL;
typedef vector< VVI > VVVI;
typedef vector< VVL > VVVL;
typedef pair< int, int > PII;
typedef pair< LL, LL > PLL;
typedef pair< int, string > PIS;
typedef pair< string, int > PSI;
typedef pair< string, string > PSS;
typedef pair< double, double > PDD;
typedef vector< PII > VPII;
typedef vector< PLL > VPLL;
typedef vector< VPII > VVPII;
typedef vector< VPLL > VVPLL;
typedef vector< VS > VVS;
typedef map< int, int > MII;
typedef unordered_map< int, int > uMII;
typedef map< LL, LL > MLL;
typedef map< string, int > MSI;
typedef map< int, string > MIS;
typedef multiset< int > mSI;
typedef set< int > SI;
typedef stack< int > SKI;
typedef deque< int > DQI;
typedef queue< int > QI;
typedef priority_queue< int > PQIMax;
typedef priority_queue< int, VI, greater< int > > PQIMin;
const double EPS = 1e-8;
const LL inf = 0x7fffffff;
const LL infLL = 0x7fffffffffffffffLL;
const LL mod = 1e9 + 7;
const int maxN = 1e4 + 7;
const LL ONE = 1;
const LL evenBits = 0xaaaaaaaaaaaaaaaa;
const LL oddBits = 0x5555555555555555;

struct Time {
    int val = 0; // 总的分钟数

    bool operator< (const Time &x) const {
        return val < x.val;
    }

    bool operator== (const Time &x) const {
        return val == x.val;
    }

    bool operator> (const Time &x) const {
        return val > x.val;
    }

    Time operator+ (const int &k) const {
        Time ret;
        ret.val = val + k;
        return ret;
    }

    Time operator+ (const Time &x) const {
        Time ret;
        ret.val = val + x.val;
        return ret;
    }

    string getString() {
        string ret;
        ret = toString(val / 60) + ":";
        if((val % 60) / 10 == 0) ret += "0";
        ret += toString(val % 60);
        return ret;
    }
};

struct Patient {
    int id;                     // 病人在，名册上的 id
    string name;                 // 病人名字
    int surgeryTime;            // 病人手术时间
    int recoveryTime;            // 病人恢复时间

    int surgeryRoomId;             // 所进行手术的手术室 id
    Time surgeryBeginTime;        // 手术开始时间
    Time surgeryEndTime;        // 手术结束时间

    int recoveryRoomId;            // 所进行恢复的恢复室 id
    Time recoveryBeginTime;        // 恢复开始时间
    Time recoveryEndTime;        // 恢复结束时间

    Patient(int x) : id(x) {}
};

istream& operator >> (istream& in, Patient& x){
    in >> x.name >> x.surgeryTime >> x.recoveryTime;
    return in;
}

ostream& operator << (ostream& out, Patient& x){
    printf("%2d  %-8s  %2d   %5s   %5s     %2d   %5s   %5s", x.id, x.name.c_str(), x.surgeryRoomId, x.surgeryBeginTime.getString().c_str(), x.surgeryEndTime.getString().c_str(), x.recoveryRoomId, x.recoveryBeginTime.getString().c_str(), x.recoveryEndTime.getString().c_str());
    return out;
}

struct Facility {
    int id;                // 设施 id
    string type;        // 设施类型
    int timeUsed;        // 设施被使用的时间
    double usedPercent;    // 使用时间百分比

    Facility(int x, string y) {
        id = x;
        type = y;
        timeUsed = 0;
        usedPercent = 0;
    }
};

ostream& operator << (ostream& out, const Facility& x) {
    printf("%-4s %2d %7d  %6.2f", x.type.c_str(), x.id, x.timeUsed, x.usedPercent);
    return out;
}

struct Event {
    // 1 代表患者可进行手术事件
    // 2 代表患者可进行恢复事件
    // 3 代表手术室空闲事件
    // 4 代表恢复室空闲事件
    int type;
    int idx; // 对应数组下表
    Time time; // 事件可进行时间

    Event(int x, int y, Time z) {
        type = x;
        idx = y;
        time = z;
    }

    bool operator< (const Event &x) const {
        return time > x.time || time == x.time && idx > x.idx;
    }
};

int N;                             // 手术室数量，小于等于 10
vector< Facility > rooms;        // 手术室房间数组
int M;                             // 恢复室数量，小于等于 30
vector< Facility > beds;        // 恢复室床数组
Time startTime;                 // 一天中医院的开始营业时间，整点，24小时格式
Time endTime;                    // 所有手术的结束时间
int totalTime;                    // 手术总持续时间
int tranTime;                     // 手术室转移恢复室时间（分钟）
int surgeryResetTime;            // 手术室准备时间（分钟）
int recoveryResetTime;             // 恢复室准备时间（分钟）
vector< Patient > roster;         // 病人名册
int patientNum;                    // 病人人数
int tmp;

struct RoomCmp {
    bool operator() (int x, int y) {
        return rooms[x].id > rooms[y].id;
    }
};

struct BedCmp {
    bool operator() (int x, int y) {
        return beds[x].id > beds[y].id;
    }
};

struct RecoveryComp {
    bool operator() (int x, int y) {
        if(roster[x].surgeryEndTime == roster[y].surgeryEndTime) return roster[x].surgeryRoomId > roster[y].surgeryRoomId;
        return roster[x].surgeryEndTime > roster[y].surgeryEndTime;
    }
};

priority_queue< Event > Q;                          // 活动队列
QI surgeryQ;                                        // 等待手术队列
priority_queue< int, VI, RecoveryComp > recoveryQ;     // 等待恢复队列
priority_queue< int, VI, RoomCmp > roomQ;            // 手术室空闲队列
priority_queue< int, VI, BedCmp > bedQ;                // 恢复室空闲队列

void init() {
    rooms.clear();
    beds.clear();
    endTime = startTime;
    roster.clear();

    while(!Q.empty()) Q.pop();
    while(!surgeryQ.empty()) surgeryQ.pop();
    while(!recoveryQ.empty()) recoveryQ.pop();
    while(!roomQ.empty()) roomQ.pop();
    while(!bedQ.empty()) bedQ.pop();
}

bool readData() {
    if(!(cin >> N >> M >> tmp >> tranTime >> surgeryResetTime >> recoveryResetTime >> patientNum)) return false;
    startTime.val = tmp * 60;

    init();

    Rep(i, N) rooms.PB(Facility(i + 1, "Room"));
    Rep(i, M) beds.PB(Facility(i + 1, "Bed"));

    Rep(i, patientNum) {
        roster.PB(Patient(i + 1));
        cin >> roster[i];
    }

    return true;
}

void printSheet() {
    printf(" Patient          Operating Room          Recovery Room\n");
    printf(" #  Name     Room#  Begin   End      Bed#  Begin    End\n");
    printf(" ------------------------------------------------------\n");
    Rep(i, patientNum) cout << roster[i] << endl;

    cout << endl;

    printf("Facility Utilization\n");
    printf("Type  # Minutes  % Used\n");
    printf("-------------------------\n");
    Rep(i, N) {
        if(totalTime) rooms[i].usedPercent = 100.0 * rooms[i].timeUsed / totalTime;
        cout << rooms[i] << endl;
    }
    Rep(i, M) {
        if(totalTime) beds[i].usedPercent = 100.0 * beds[i].timeUsed / totalTime;
        cout << beds[i] << endl;
    }
}

void solve() {
    Time nowTime;
    Rep(i, patientNum) Q.push(Event(1, i, startTime));
    Rep(i, N) Q.push(Event(3, i, startTime));
    Rep(i, M) Q.push(Event(4, i, startTime));

    while(!Q.empty()) {
        nowTime = Q.top().time;

        while(!Q.empty() && nowTime == Q.top().time) { // 把这个时间到到达的活动全取出来
            Event e = Q.top(); Q.pop();

            switch(e.type) {
                case 1:{
                    surgeryQ.push(e.idx);
                    break;
                }
                case 2:{
                    recoveryQ.push(e.idx);
                    break;
                }
                case 3:{
                    roomQ.push(e.idx);
                    break;
                }
                case 4:{
                    bedQ.push(e.idx);
                    break;
                }
                default:{
                    assert(false);
                }
            }
        }

        // 如果有人等待做手术并且有手术室可用，就分配手术室
        while(!surgeryQ.empty() && !roomQ.empty()) {
            int pid = surgeryQ.front(); surgeryQ.pop();
            int rid = roomQ.top(); roomQ.pop();
            Patient &p = roster[pid];
            Facility &f = rooms[rid];

            p.surgeryRoomId = f.id;
            p.surgeryBeginTime = nowTime;
            p.surgeryEndTime = p.surgeryBeginTime + p.surgeryTime;

            f.timeUsed += p.surgeryTime;

            Q.push(Event(2, pid, p.surgeryEndTime));
            Q.push(Event(3, rid, p.surgeryEndTime + surgeryResetTime));
        }

        // 如果有人等待恢复并且有恢复室可用，就分配恢复室
        while(!recoveryQ.empty() && !bedQ.empty()) {
            int pid = recoveryQ.top(); recoveryQ.pop();
            int bid = bedQ.top(); bedQ.pop();
            Patient &p = roster[pid];
            Facility &f = beds[bid];

            p.recoveryRoomId = f.id;
            p.recoveryBeginTime = nowTime + tranTime;
            p.recoveryEndTime = p.recoveryBeginTime + p.recoveryTime;

            f.timeUsed += p.recoveryTime;

            endTime = max(endTime, p.recoveryEndTime);

            Q.push(Event(4, bid, p.recoveryEndTime + recoveryResetTime));
        }
    }
}

int main() {
    freopen("MyOutput.txt","w",stdout);
    freopen("input.txt","r",stdin);
    //INIT();
    while(readData()) {
        solve();
        totalTime = endTime.val - startTime.val;
        printSheet();
        cout << endl;
    }
    return 0;
}