#include <base/fileio.h>
#include <sys/stat.h>
#include <iostream>

using namespace CEGUI::FILEIO;

loadedfile L_FILE(const char* name) {
    loadedfile l;
    struct stat tempstat;
    int size;
    if (stat(name, &tempstat) == 0) {
        size = tempstat.st_size;   
    }
    else {
        std::cerr << "FILE IO ERROR: STAT FUNCTION FAILED IN FUNCTION " << __PRETTY_FUNCTION__ << std::endl;
    }

    std::ifstream tempstream(name, std::ios::in | std::ios::binary);

    tempstream.read(l.buffer, size);

    return l;
}

/*activefile FILE(const char* name, char* buff = nullptr) {
    activefile af;
    struct stat tempstat;
    int size;

    if (stat(name, &tempstat) == 0) {
        size = tempstat.st_size;   
    }
    else {
        std::cerr << "FILE IO ERROR: STAT FUNCTION FAILED" << std::endl;
    }
    

}*/