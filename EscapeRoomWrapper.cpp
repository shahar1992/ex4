#include "EscapeRoomWrapper.h"
using namespace mtm::escaperoom;

EscapeRoomWrapper::EscapeRoomWrapper(char* name, const int& escapeTime,
                                     const int& level,
                                     const int& maxParticipants):
        escape_room(escapeRoomCreate(name,escapeTime,maxParticipants,level)){
    if(!escape_room){
    }
}

EscapeRoomWrapper::EscapeRoomWrapper(char* name, const int& level):
    escape_room(escapeRoomCreate(name,60,6,level)) {
    if(!escape_room) {
    }
}

EscapeRoomWrapper::EscapeRoomWrapper(const EscapeRoomWrapper& room):
    escape_room(escapeRoomCopy(room.escape_room)) {
    if(!escape_room) {
    }
}

EscapeRoomWrapper& EscapeRoomWrapper::operator=(const EscapeRoomWrapper& room){
    if(this == &room) {
        return *this;
    }
    EscapeRoom escape_room = escapeRoomCopy(room.escape_room);
    if(!escape_room) {
    }
    escapeRoomDestroy(this->escape_room);
    this->escape_room = escape_room;
    return *this;
}


bool operator==(const EscapeRoomWrapper& room) const {

}

bool operator!=(const EscapeRoomWrapper& room) const;
bool operator<(const EscapeRoomWrapper& room) const;
bool operator>(const EscapeRoomWrapper& room) const;

bool operator<=(const EscapeRoomWrapper& room) const = delete;
bool operator>=(const EscapeRoomWrapper& room) const = delete;

// return the level of the Escape Room.
//
int level() const;

// the method changes the rate according to the rate given.
//
// @param newRate : the new rate accepted to the room.
//@throws EscapeRoomIllegalRateException in case of illegal rate
// parameter.
void rate(const int& newRate);

// Destructor for EscapeRoomWrapper
~EscapeRoomWrapper();

// Prints the data of the Room in the following format:
//
//     "<name> (<maxTime>/<level>/<maxParticipants>)"
//
// @param output : the output stream to which the data is printed.
// @param room : the room whose data is printed.
friend std::ostream& operator<<(std::ostream& output,
                                const EscapeRoomWrapper& room);

//Function returns the name of the EscapeRoom.
//
std::string getName() const;

//Function returns the rate of the EscapeRoom.
//
double getRate() const;

//Function returns the maximum escape time of the EscapeRoom.
//
int getMaxTime() const;

//Function returns the number of participants allowed in the EscapeRoom.
//
int getMaxParticipants() const;

};

std::ostream& operator<<(std::ostream& output,
                         const EscapeRoomWrapper& room);