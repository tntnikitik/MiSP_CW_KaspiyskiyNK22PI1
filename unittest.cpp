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
        string fpath = "database.txt";
        int port = 33333;
        string lpath = "log.txt";
        server test(fpath, port, lpath);
        CHECK(true);
    }
    TEST(BadPort) {
        string fpath = "database.txt";
        int port = 1000;
        string lpath = "log.txt";
        CHECK_THROW(server test(fpath, port, lpath), std::system_error);
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
        string fpath = "database.txt";
        CHECK_EQUAL(true, userdata == getdata(lpath).get(fpath));
    }
    TEST(GetInvalidUserData) {
        string lpath = "log.txt";
        string fpath = "beb.txt";
        CHECK_THROW(getdata(lpath).get(fpath), read_err);
    }
}
SUITE(HashTest)
{
    TEST(ValidHashGen) {
        md5h test;
        string pass1 = "P@ssW0rd";
        string pass2 = "P@ssW0rd";
        CHECK_EQUAL(true, test.hash(pass1) == test.hash(pass2));
    }
    TEST(StrongHashGen) {
        md5h test;
        string pass1 = "P@ssW0rd";
        string pass2 = "P@ssW0rd1";
        CHECK_EQUAL(false, test.hash(pass1) == test.hash(pass2));
    }
}
SUITE(ErrorLoggingTest)
{
    TEST(ValidLogFile) {
        logger("log.txt", "some trouble");
        CHECK(true);
    }
    TEST(InvalidLogFile) {
        CHECK_THROW(logger("", "some trouble"), log_err);
    }
}
int main(int argc, char **argv)
{
    return UnitTest::RunAllTests();
}
