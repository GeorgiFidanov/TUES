#include <stack>
#include <iostream>
#include <vector>

using namespace std;

class PC{
    public:
        virtual int energyConsumption (int n1, int n2) = 0;   
};

class Processor: public PC{
    public:
        int cores;
        int frequency;
        int energyConsumption (int cores, int frequency)override{
            return cores * frequency;
        } 
};

class HardDrive: public PC{
    public:
        int size;
        int diskSpeed;
        int energyConsumption (int diskSpeed, int size)override{
            return diskSpeed/1000;
        } 
};

class Ram: public PC{
    public:
        int memorySize;
        int frequency;
        int energyConsumption (int frequency, int memorySize)override{
            return ((memorySize * frequency) / 3000);
        } 
};

class BotNet: public PC{
    private:
        vector<Processor*> stats_pr;
        vector<Ram*> stats_ram;
        vector<HardDrive*> stats_hd;
        
    public:
        stats_pr = vector<Processor*>();

};

int main() {
     
}