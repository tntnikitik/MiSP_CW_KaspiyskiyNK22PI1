#include <UnitTest++/UnitTest++.h>
#include "headers/server.hpp"
#include "headers/errorhandler.hpp"
#include "headers/getdata.hpp"
#include "headers/md5hash.hpp"

using namespace std;
struct Server_fixture {
    server * pointer;
    Server_fixture()
    {
        pointer = new server("/home/stud/Desktop/kursach/kursachCode/SERVER/database.txt", 33333, "log.txt");
    }
    ~Server_fixture()
    {
        delete pointer;
    }
};
SUITE(ServerTests)
{
    TEST(ServerConstructor) {
        string fpath = "/home/stud/Desktop/kursach/kursachCode/SERVER/database.txt";
        int port = 33333;
        string lpath = "log.txt";
        server test(fpath, port, lpath);
        CHECK(true);
    }
}
SUITE(GetDataTests)
{
    TEST(GetDataConstructor) {
        string lpath = "database.txt";
        getdata test(lpath);
        CHECK(true);
    }
    TEST(GetUserData) {
        string lpath = "log.txt";
        map <string, string> userdata;
        userdata["user"] = "P@ssW0rd";
        string fpath = "/home/stud/Desktop/kursach/kursachCode/SERVER/database.txt";
        CHECK_EQUAL(true, userdata == getdata(lpath).get(fpath));
    }
}
SUITE(ErrorhandlerTests)
{
    TEST(ErrorhandlerConstructor) {
        string lpath = "log.txt";
        int exitCode = 1;
        bool critical = false;
        errorhandler test(lpath, "some trouble here", exitCode, critical);
        CHECK(true);
    }
}
int main(int argc, char **argv)
{
    return UnitTest::RunAllTests();
}
