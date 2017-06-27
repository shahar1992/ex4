#include "Company.h"

using namespace mtm::escaperoom;
using std::vector;

Company::Company(string name, string phoneNumber):name(name),
                                                  number(phoneNumber){}

Company::Company(const Company& company) : name(company.name) ,
                                           number(company.number) ,
                                           escape_rooms(company.escape_rooms){}

Company& Company::operator=(const Company& company){
    if(this == &company){
        return *this;
    }
    this->name = company.name;
    this->number = company.number;
    this->escape_rooms = company.escape_rooms;
    return *this;
}

void Company::createRoom(char* name, const int& escapeTime, const int& level,
                const int& maxParticipants){
    try {
        EscapeRoomWrapper escape_room(name, escapeTime, level, maxParticipants);
        this->escape_rooms.insert(&escape_room);
    }
    catch(...){
        throw CompanyMemoryProblemException();
    }
}

void Company::createScaryRoom(char* name, const int& escapeTime,
                              const int& level, const int& maxParticipants,
                              const int& ageLimit,const int& numOfScaryEnigmas){
    try{
        ScaryRoom escape_room(name,escapeTime,level,maxParticipants,ageLimit,
                              numOfScaryEnigmas);
        this->escape_rooms.insert(&escape_room);
    }
    catch (...){
        throw CompanyMemoryProblemException();
    }
}

void Company::createKidsRoom(char* name,const int& escapeTime, const int& level,
                    const int& maxParticipants, const int& ageLimit){
    try{
        KidsRoom escape_room(name,escapeTime,level,maxParticipants,ageLimit);
        this->escape_rooms.insert(&escape_room);
    }
    catch (...){
        throw CompanyMemoryProblemException();
    }
}

set<EscapeRoomWrapper*> Company::getAllRooms() const{
    return this->escape_rooms;
}

void Company::removeRoom(const EscapeRoomWrapper& room){
    set<EscapeRoomWrapper*>::iterator i = this->escape_rooms.find(&room);
    if(i == this->escape_rooms.end()){
        throw CompanyRoomNotFoundException();
    }
    this->escape_rooms.erase(i);
}

void Company::addEnigma(const EscapeRoomWrapper& room, const Enigma& enigma){
    set<EscapeRoomWrapper*>::iterator i = this->escape_rooms.find(&room);
    if(i == this->escape_rooms.end()){
        throw CompanyRoomNotFoundException();
    }
    this->escape_rooms(i).insert(enigma);
}
