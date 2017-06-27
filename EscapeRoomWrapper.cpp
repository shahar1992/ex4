#include "EscapeRoomWrapper.h"
#include "Exceptions.h"

using namespace mtm::escaperoom;
using std::vector;

EscapeRoomWrapper::EscapeRoomWrapper(char* name, const int& escapeTime,
                                     const int& level,
                                     const int& maxParticipants):
        escape_room(escapeRoomCreate(name,escapeTime,maxParticipants,level)),
        enigmas(){
    if(!escape_room){
        throw EscapeRoomMemoryProblemException();
    }
}

EscapeRoomWrapper::EscapeRoomWrapper(char* name, const int& level):
    escape_room(escapeRoomCreate(name,DEFAULT_ESCAPE_TIME,DEFAULT_MAX_PARTICIPANTS,level)),
    enigmas(){
    if(!escape_room) {
        throw EscapeRoomMemoryProblemException();
    }
}

EscapeRoomWrapper::EscapeRoomWrapper(const EscapeRoomWrapper& room):
    escape_room(escapeRoomCopy(room.escape_room)),enigmas(room.enigmas) {
    if(!escape_room) {
        throw EscapeRoomMemoryProblemException();
    }
}

EscapeRoomWrapper& EscapeRoomWrapper::operator=(const EscapeRoomWrapper& room){
    if(this == &room) {
        return *this;
    }
    EscapeRoom escape_room = escapeRoomCopy(room.escape_room);
    if(!escape_room) {
        throw EscapeRoomMemoryProblemException();
    }
    escapeRoomDestroy(this->escape_room);
    this->escape_room = escape_room;
    this->enigmas=room.enigmas;
    return *this;
}


bool EscapeRoomWrapper::operator==(const EscapeRoomWrapper& room) const {
    return areEqualRooms(this->escape_room,room.escape_room);
}

bool EscapeRoomWrapper::operator!=(const EscapeRoomWrapper& room) const {
    return !areEqualRooms(this->escape_room,room.escape_room);
}

bool EscapeRoomWrapper::operator<(const EscapeRoomWrapper& room) const {
    return isBiggerRoom(room.escape_room,this->escape_room);
}

bool EscapeRoomWrapper::operator>(const EscapeRoomWrapper& room) const {
    return isBiggerRoom(this->escape_room, room.escape_room);
}

int EscapeRoomWrapper::level() const {
    return getLevel(this->escape_room);
}

void EscapeRoomWrapper::rate(const int& newRate) {
    if(newRate > 5 || newRate < 0) {
        throw EscapeRoomIllegalRateException();
    }
    updateRate(this->escape_room,newRate);
}

EscapeRoomWrapper::~EscapeRoomWrapper() {
    escapeRoomDestroy(this->escape_room);
}

std::ostream& operator<<(std::ostream& output,
                                const EscapeRoomWrapper& room) {
    return output << room.getName() << '(' << room.getMaxTime() << '/' <<
                  room.level() << '/' << room.getMaxParticipants() << ')' ;
}

std::string EscapeRoomWrapper::getName() const{
    return roomGetName(this->escape_room);
}

double EscapeRoomWrapper::getRate() const{
    return roomGetRate(this->escape_room);
}

int EscapeRoomWrapper::getMaxTime() const{
    return roomGetMaxTime(this->escape_room);
}

int EscapeRoomWrapper::getMaxParticipants() const{
    return roomGetMaxParticipants(this->escape_room);
}

void EscapeRoomWrapper::addEnigma(const Enigma& enigma){
    enigmas.push_back(enigma);
}

void EscapeRoomWrapper::removeEnigma(const Enigma& enigma){
    if(this->enigmas.empty()){
        throw EscapeRoomNoEnigmasException();
    }
    for(vector<Enigma>::const_iterator i = this->enigmas.begin() ;
        i != this->enigmas.end() ; i++){
        if(*i == enigma){
            this->enigmas.erase(i);
            return;
        }
    }
    throw  EscapeRoomEnigmaNotFoundException();
}

Enigma EscapeRoomWrapper::getHardestEnigma() const {
    if(this->enigmas.empty()){
        throw EscapeRoomNoEnigmasException();
    }
    Enigma hardest = *enigmas.begin();
    for( vector<Enigma>::const_iterator i=enigmas.cbegin(); i != enigmas.end() ; ++i){
        if(*i > hardest){
            hardest = *i;
        }
    }
    return hardest;
}

vector<Enigma>& EscapeRoomWrapper::getAllEnigmas(){
    return this->enigmas;
}

