#ifndef FILEIO_H
#define FILEIO_H

#include <fstream>

namespace CEGUI {
    namespace FILEIO {
        struct loadedfile { // a struct with the whole file loaded into the buffer
            int bytes;
            const char* name;
            char* buffer; // can be specified (or not)
        };

        struct activefile {
            int bytes;
            const char* name;
            char* buffer;
            std::fstream stream;
        };

        loadedfile L_FILE(const char* name); // loads the whole file into the struct
             
        activefile FILE(const char* name, char* buff = nullptr); // "active file" is a file that has a stream reading/writing to it
    };
};



#endif