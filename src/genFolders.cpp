#include <genFolders.h>

GenFolders::GenFolders(std::string &location):home_location_(location){

}

bool GenFolders::incluesDirExists(){
    //check if file given is even a location or not
    boost::filesystem::path dir(this->home_location_);
    if(boost::filesystem::is_directory(dir)){
        //now check if it contains a directory with include folder
        //or not if so, then return true, otherwise just fail
        std::string includes_dir=this->home_location_+"/include";
        if(boost::filesystem::is_directory(boost::filesystem::path(includes_dir))){
            return true;
        }
    }
    return false;
}
