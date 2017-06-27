#ifndef EX4_KIDSROOM_H
#define EX4_KIDSROOM_H

#include <string>
#include "EscapeRoomWrapper.h"

namespace mtm{
    namespace escaperoom {
        class KidsRoom : public EscapeRoomWrapper{
            int age_limit;

        public:
            KidsRoom(char* name,const int& escapeTime,const int&level,
                     const int& maxParticipants, const int& ageLimit);

            void setNewAgeLimit(const int& limit);

            int getAgeLimit() const;

            /**
             * Prints the data of the Room in the following format:
             *
             * "Kids room: <name> (<maxTime>/<level>/<maxPartic>/<ageLimit>)"
             *
             * @param output : the output stream to which the data is printed.
             * @param room : the room whose data is printed.
             */
            friend std::ostream& operator<<(std::ostream& output,
                                            const KidsRoom& room);
        };

        std::ostream& operator<<(std::ostream& output,
                                 const KidsRoom& room);

    } // end of namespace eascaperoom
} // end of namespace mtm


#endif //EX4_KIDSROOM_H
