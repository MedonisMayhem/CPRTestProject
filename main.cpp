#include <iostream>
#include <cpr\cpr.h>

int main() {
    std::string foo;
    std::cin >> foo;

    std::string animal;
    std::cin >> animal;

    std::string bar;
    std::cin >> bar;


    std::cout << "post or get" << std::endl;
    std::string command;
    std::cin >> command;


    cpr::Response request;
    std::string url = "http://httpbin.org/";

    bool unfound;
    do
    {
        unfound = false;
        if(command == "post")
        {
            request = cpr::Post(cpr::Url(url + command),
                                cpr::Multipart{{"foo", foo}, {"animal", animal}, {"bar", bar}});
        }
        else if (command == "get")
        {
            request = cpr::Get(cpr::Url(url + "get?foo=" + foo + "&animal=" + animal + "&bar=" + bar));
        }
        else
        {
            unfound = true;
        }
    } while(unfound);

    std::cout << request.text << std::endl;
}
