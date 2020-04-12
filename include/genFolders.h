/**
 * Used for generating folders
 * of a C++ project
 * that uses CMake
 */

#include <boost/filesystem.hpp>
#include <string>

class GenFolders{
public:
    /**
     * Generate a GenFolders with a location
     * of where to base it from
     */
    GenFolders(std::string &location);

    /**
     * Reports whether an include's directory exists
     * or not
     */
    bool incluesDirExists();
    

private:
    std::string home_location_;
};
