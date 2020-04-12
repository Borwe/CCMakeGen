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

    /**
     * Returns true if succesfully created includes
     * dir or if it already existed so no need to recreate
     */
    bool generateIncludesDir();

    /**
     * Checks whether the src dir exists or not,
     * returns tru if so, false if not
     */
    bool srcDirExists();

    bool generateSrcDir();
    
    /**
     * Reports true if the home_location_ exists
     * otherwise returns false
     */
    bool locationIsValid();

private:
    std::string home_location_;
};
