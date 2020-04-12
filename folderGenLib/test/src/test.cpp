#define BOOST_TEST_MODULE folderGenTest
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <genFolders.h>

BOOST_AUTO_TEST_CASE(checkFoldersExist){
    GenFolders genF("./");
    BOOST_ASSERT(genF.locationIsValid()==true);

    GenFolders genF2("/home/brian/shittasdsadasdasdasd");
    BOOST_ASSERT(genF2.locationIsValid()==false);

    //now try create include dir on ./
    BOOST_ASSERT(genF.generateIncludesDir()==true);
}
