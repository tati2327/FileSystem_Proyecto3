#ifndef JSON_H
#define JSON_H

#include <iostream>
#include "include/rapidjson/allocators.h"
#include "include/rapidjson/stringbuffer.h"
#include "include/rapidjson/document.h"
#include "include/rapidjson/writer.h"
#include "List.h"
#include "QString"

using namespace rapidjson;
using namespace std;

class JSON {
    public:
        JSON();
        void jsonToDocument(string json);

        string serializeRequest();
        string serializeInsertMsg(int id, string name, string author, int year, int size, string description);
        string serializeDeleteMsg(string deleteMsg);
        string serializeUpdateMsg(string columnName, string value, string condition);
        string serializeSelectMsg(string columnName);

        int getRequest();
        int getSizeData();
        List<string> getValue1();
        List<string> getValue2();
        List<string> getValue3();
        List<string> getValue4();
        List<string> getValue5();
        List<string> getValue6();
};

#endif // JSON_H