#include "KidsRoom.h"
#include "Exceptions.h"

using std::string;
using namespace mtm::escaperoom;

KidsRoom::KidsRoom(char* name,const int& escapeTime,const int&level,
         const int& maxParticipants, const int& ageLimit):
            EscapeRoomWrapper(name,escapeTime,level,maxParticipants),
            age_limit(ageLimit){}

void KidsRoom::setNewAgeLimit(const int& limit){
    if(limit < 0){
        throw KidsRoomIllegalAgeLimit();
    }
    this->age_limit = limit;
}

int KidsRoom::getAgeLimit() const{
    return this->age_limit;
}

std::ostream& operator<<(std::ostream& output, const KidsRoom& room){
    return output << room.getName() << '(' << room.getMaxTime() << '/' <<
                 room.level() << '/' << room.getMaxParticipants() << '/' <<
                 room.getAgeLimit() << ')';
}