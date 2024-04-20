#include <string>
#include <iostream>

enum valute {euro = 20, dollor=18, leuRoman = 4};

void CheckForStatus(valute status)
{
    switch(status) 
    {
    case euro: std::cout << "euro";
        break;
    case dollor: std::cout<<R"(dollar)";
        break;
    case leuRoman: std::cout<<"leu roman";
        break;
    }
}
struct Location
{
    int postCardIndex=0;
};

struct Citizen
{   
    struct Location address;
    int a=23;
    int b=12;
}Alex;

struct Timing
{
    int hours;
    int minutes;
    int seconds;
};

struct Player
{
    int index = 2342;
    std::string name = "Alex";
    std::string surName = "Hack";
}Pupil[2];

void Send1(int ind,std::string nm,std::string surname)
{
    
}
void Send3(struct  Player &obj)
{
    
}
void Send2(struct  Player obj)
{
    
}
void SetInfaPlayer()
{
    for (auto& y : Pupil)
        y.index=0;
    Pupil[0]=Pupil[1];
}
void ChangeTime(Timing &time_s)
{
    if(time_s.seconds>=60)
    {
        time_s.minutes+=time_s.seconds/60;
        time_s.seconds = time_s.seconds%60;
    }
    if(time_s.minutes>=60)
    {
        time_s.hours+=time_s.minutes/60;
        time_s.minutes = time_s.minutes%60;
    }

    std::cout<<"Seconds: "<<time_s.seconds<<"\n";
    std::cout<<"Minutes: "<<time_s.minutes<<"\n";
    std::cout<<"Hours: "<<time_s.hours<<"\n";
}

int main()
{
    struct Player teacher = {12,"Alexia","Petrov"};
    Send1(teacher.index,teacher.name,teacher.surName);
    Send2(teacher);
    Send3(teacher);
    SetInfaPlayer();

    struct Timing obj = {0,133,230};
    ChangeTime(obj);

    Alex.address.postCardIndex=10;

    typedef int nums; 
    nums even[2]={0,1};


    valute Moldova = dollor;
    CheckForStatus(Moldova);

    struct Citizen *cit = &Alex;
    cit->a=10;
    std::cout << cit->a;
    return 0;
}
