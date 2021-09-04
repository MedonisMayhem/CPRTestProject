#include <iostream>
#include <cpr\cpr.h>
#include <vector>

int main() {
    cpr::Response request;
    std::string url = "http://httpbin.org/";

    std::vector<cpr::Pair> pair;

    bool unfound = true;
    std::cout << "Please. Input key and value:" << std::endl;
    do
    {
        std::string key;
        std::string value;
        std::cin >> key >> value;

        pair.push_back(cpr::Pair((std::string)key,(std::string)value));

        if(pair[pair.size()-1].key == "post" || pair[pair.size()-1].key == "get")
        {
            unfound = false;
        }
    } while(unfound);

    if(pair[pair.size()-1].key == "post")
    {
        request = cpr::Post(cpr::Url(url + "post"),
                            cpr::Payload(pair.begin(), pair.end()));
    }
    else if (pair[pair.size()-1].key == "get")
    {
        std::string quest = "get?";
        for(auto&& str : pair)
            quest+= str.key + "=" + str.value + "&";
        quest.pop_back();

        std::cout << quest << std::endl;
        request = cpr::Get(cpr::Url(url + quest));
    }
    else
    {
        std::cerr << "Wrong! Incorrect work with the vector index." << std::endl;
    }

    std::cout << request.text << std::endl;
}
