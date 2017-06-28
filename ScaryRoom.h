#ifndef EX4_SCARYROOM_H
#define EX4_SCARYROOM_H

#include <string>
#include "EscapeRoomWrapper.h"


namespace mtm{
    namespace escaperoom {

        class ScaryRoom : public EscapeRoomWrapper{

            int age_limit;
            int num_of_scary_enigmas;

        public:
            /**
             *      Constructs a new Scary Room with the specified data.
             *
             * @param name : the name of the Scary room.
             * @param escapeTime : the maximal escape time allowed in the room.
             * @param level : the level of the escape room.
             * @param maxParticipants : the maximal participants allowed in the
             *                          room.
             * @param ageLimit : the minimal age allowed to enter the room.
             * @param numOfScaryEnigmas : number of scary enigmas in the room.
             */
            ScaryRoom(char* name, const int& escapeTime, const int& level,
            const int& maxParticipants, const int& ageLimit,
                      const int& numOfScaryEnigmas);

            /**
             * Set a new age limit in the room.
             *
             * @param limit : the age limit to set.
             */
            void setNewAgeLimit(const int& limit);

            /**
             * increase number of scary enigmas in the room by 1.
             */
            void incNumberOfScaryEnigmas();

            int getAgeLimit() const;

            /**
             * Prints the data of the Room in the following format:
             *
             * "Scary room: <name> (<maxTime>/<level>/<maxPartic>/<ageLimit>)"
             *
             * @param output : the output stream to which the data is printed.
             * @param room : the room whose data is printed.
             */
            friend std::ostream& operator<<(std::ostream& output,
                                            const ScaryRoom& room);

            ~ScaryRoom()= default;
        };


        std::ostream& operator<<(std::ostream& output,
                                 const ScaryRoom& room);

    } // end of namespace eascaperoom
} // end of namespace mtm


#endif //EX4_SCARYROOM_H
