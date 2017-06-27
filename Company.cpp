#include "Company.h"
#include <typeinfo>

using namespace mtm::escaperoom;
using std::vector;
using std::ostream;
using std::endl;

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
    EscapeRoomWrapper room_to_find = room;
    set<EscapeRoomWrapper*>::iterator i =this->escape_rooms.find(&room_to_find);
    if(i == this->escape_rooms.end()){
        throw CompanyRoomNotFoundException();
    }
    this->escape_rooms.erase(i);
}

void Company::addEnigma(const EscapeRoomWrapper& room, const Enigma& enigma){
    this->getRoom(room).addEnigma(enigma);
}

void Company::removeEnigma(const EscapeRoomWrapper& room, const Enigma& enigma){
    try{
        this->getRoom(room).removeEnigma(enigma);
    }
    catch (EscapeRoomNoEnigmasException& e){
        throw CompanyRoomHasNoEnigmasException();
    }
    catch (EscapeRoomEnigmaNotFoundException& e){
        throw CompanyRoomEnigmaNotFoundException();
    }
}


void Company::addItem(const EscapeRoomWrapper& room, const Enigma& enigma,
             const string& element){
    try {
        this->getRoom(room).getEnigma(enigma).addElement(element);
    }
    catch (EscapeRoomException& e){
        throw CompanyRoomEnigmaNotFoundException();
    }
}

void Company::removeItem(const EscapeRoomWrapper& room, const Enigma& enigma,
                const string& element){
    try{
        this->getRoom(room).getEnigma(enigma).removeElement(element);
    }
    catch(EnigmaNoElementsException& e){
        throw CompanyRoomEnigmaHasNoElementsException();
    }
    catch(EnigmaElementNotFoundException& e){
        throw CompanyRoomEnigmaElementNotFoundException();
    }
    catch (EscapeRoomEnigmaNotFoundException& e){
        throw CompanyRoomEnigmaNotFoundException();
    }
}

set<EscapeRoomWrapper*> Company::getAllRoomsByType(RoomType type) const{
    set<EscapeRoomWrapper*> temp_set;
    for(set<EscapeRoomWrapper*>::iterator i = this->escape_rooms.begin() ;
            i != this->escape_rooms.end() ; ++i){
        if(typeid(*(*i)) == typeid(type)){
            temp_set.insert(*i);
        }
    }
    return temp_set;
}

EscapeRoomWrapper* Company::getRoomByName(const string& name) const{
    for(set<EscapeRoomWrapper*>::iterator i = this->escape_rooms.begin() ;
        i != this->escape_rooms.end() ; ++i){
        if((*i)->getName() == name){
            return *i;
        }
    }
    throw CompanyRoomNotFoundException();
}


std::ostream& mtm::escaperoom::operator<<(std::ostream& output, const Company& company){
    output << company.getName() << ":" << company.getNumber() << endl;
    for(set<EscapeRoomWrapper*>::iterator i = company.getAllRooms().begin() ;
            i != company.getAllRooms().end() ; ++i){
        output << *i << endl;
    }
    return output;
}


EscapeRoomWrapper& Company::getRoom(const EscapeRoomWrapper& room){
    EscapeRoomWrapper room_to_find = room;
    set<EscapeRoomWrapper*>::iterator i =this->escape_rooms.find(&room_to_find);
    if(i == this->escape_rooms.end()){
        throw CompanyRoomNotFoundException();
    }
    return *(*i);
}

string Company::getName() const{
    return this->name;
}

string Company::getNumber() const {
    return this->number;
}