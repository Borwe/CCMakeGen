#include <genFolders.h>
#include <boost/filesystem.hpp>

GenFolders::GenFolders(std::string &location):home_location_(location){
}

GenFolders::GenFolders(std::string &&location):home_location_(location){
    
}

bool GenFolders::generateIncludesDir(){
    //if the includes dir already existed
    //then do nothing
    if(this->includesDirExists()){
        return true;
    }
    
    //if location actually exists
    //but includes dir doesn't
    //then go ahead and create it.
    if(this->locationIsValid()){
        boost::filesystem::path home_path_include(home_location_+"/include");
        boost::filesystem::create_directory(home_path_include);
        return true;
    }
    return false;
}

bool GenFolders::locationIsValid(){
    //check if file given is even a location or not
    boost::filesystem::path dir(this->home_location_);
    if(boost::filesystem::is_directory(dir)){
        return true;
    }
    return false;
}

bool GenFolders::includesDirExists(){
    if(this->locationIsValid()){
        //now check if it contains a directory with include folder
        //or not if so, then return true, otherwise just fail
        std::string includes_dir=this->home_location_+"/include";
        if(boost::filesystem::is_directory(boost::filesystem::path(includes_dir))){
            return true;
        }
    }
    return false;
}
