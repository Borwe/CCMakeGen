/**
 * Used for generating folders
 * of a C++ project
 * that uses CMake
 */

#include <string>

class GenFolders{
public:
    //Delete copy constructors
    GenFolders(const GenFolders &)=delete;
    GenFolders(const GenFolders &&)=delete;
    GenFolders *operator=(const GenFolders &&)=delete;

    /**
     * Generate a GenFolders with a location
     * of where to base it from
     */
    GenFolders(std::string &location);
    GenFolders(std::string &&location);

    /**
     * Reports whether an include's directory exists
     * or not
     */
    bool includesDirExists();

    bool generateIncludesDir();
    
    /**
     * Reports true if the home_location_ exists
     * otherwise returns false
     */
    bool locationIsValid();

private:
    std::string home_location_;
};
