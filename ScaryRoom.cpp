#include "ScaryRoom.h"
#include "Exceptions.h"

using namespace mtm::escaperoom;

ScaryRoom::ScaryRoom(char* name, const int& escapeTime, const int& level,
          const int& maxParticipants, const int& ageLimit,
          const int& numOfScaryEnigmas) : EscapeRoomWrapper::EscapeRoomWrapper(
            name,escapeTime,level,maxParticipants), age_limit(ageLimit),
            num_of_scary_enigmas(numOfScaryEnigmas){}

void ScaryRoom::setNewAgeLimit(const int& limit){
    if(limit < 0){
        throw ScaryRoomIllegalAgeLimit();
    }
    this->age_limit = limit;
}

void ScaryRoom::incNumberOfScaryEnigmas(){
    this->num_of_scary_enigmas++;
}

int ScaryRoom::getAgeLimit(){
    return this->age_limit;
}

std::ostream& operator<<(std::ostream& output, const ScaryRoom& room) {
    return output << room.getName() << '(' << room.getMaxTime() << '/' <<
                  room.getName() << '/' << room.getMaxParticipants() << '/' <<
                  room.age_limit << ')';
}

