#include "JSON.h"
#include <cstdio>
#include <cstring>

Document document(kObjectType);

JSON::JSON() = default;

void JSON::jsonToDocument(string json) {
    document.Parse(json.c_str());
    cout<<"De json a documento exitosamente!!"<<endl;
}

string JSON::serializeRequest() {
    document.RemoveAllMembers();
    Document::AllocatorType& allocator = document.GetAllocator();
    document.AddMember("request",1, allocator);
    document.AddMember("message","nuevo juego", allocator);

    StringBuffer strbuf;
    Writer<StringBuffer> writer(strbuf);
    document.Accept(writer);

    cout<<"***********************************************************"<<endl;
    std::cout <<strbuf.GetString()<< std::endl;
    cout<<"*****************messageServer******************************************"<<endl;
    return strbuf.GetString();
}

int JSON::getRequest(){
    return document["request"].GetInt();
}

int JSON::getSizeData()
{
    return document["size"].GetInt();    
}

List<string> JSON::getValue1()
{
    List<string> value;
    Value temp = document["value1"].GetArray();
    for(int i = 0; i < temp.Size(); i++){
        value.add(temp[i].GetString());
    }
    return value;   
}

List<string> JSON::getValue2()
{
    List<string> value;
    Value temp = document["value2"].GetArray();
    for(int i = 0; i < temp.Size(); i++){
        value.add(temp[i].GetString());
    }
    return value; 
}

List<string> JSON::getValue3()
{
    List<string> value;
    Value temp = document["value3"].GetArray();
    for(int i = 0; i < temp.Size(); i++){
        value.add(temp[i].GetString());
    }
    return value; 
}

List<string> JSON::getValue4()
{
    List<string> value;
    Value temp = document["value4"].GetArray();
    for(int i = 0; i < temp.Size(); i++){
        value.add(temp[i].GetString());
    }
    return value; 
}

List<string> JSON::getValue5()
{
    List<string> value;
    Value temp = document["value5"].GetArray();
    for(int i = 0; i < temp.Size(); i++){
        value.add(temp[i].GetString());
    }
    return value; 
}

List<string> JSON::getValue6()
{
    List<string> value;
    Value temp = document["value6"].GetArray();
    for(int i = 0; i < temp.Size(); i++){
        value.add(temp[i].GetString());
    }
    return value; 
}

string JSON::serializeInsertMsg(int id, string name, string author, int year, int size,
                           string description) {
    document.RemoveAllMembers();
    Document::AllocatorType& allocator = document.GetAllocator();

    Value nameString(name.c_str(), allocator);
    Value authorString(author.c_str(), allocator);
    Value descriptionString(description.c_str(), allocator);

    document.AddMember("request",1, allocator);
    document.AddMember("id", id, allocator);
    document.AddMember("age", nameString, allocator);
    document.AddMember("author", authorString, allocator);
    document.AddMember("year", year, allocator);
    document.AddMember("size", size, allocator);
    document.AddMember("description", descriptionString, allocator);

    StringBuffer strbuf;
    Writer<StringBuffer> writer(strbuf);
    document.Accept(writer);

    cout<<"***********************************************************"<<endl;
    std::cout <<strbuf.GetString()<< std::endl;
    cout<<"***********************************************************"<<endl;
    return strbuf.GetString();
}

string JSON::serializeDeleteMsg(string deleteMsg){
    document.RemoveAllMembers();
    Document::AllocatorType& allocator = document.GetAllocator();

    Value deleteString(deleteMsg.c_str(), allocator);
    document.AddMember("request", 4, allocator);
    document.AddMember("deleteMsg", deleteString, allocator);

    StringBuffer strbuf;
    Writer<StringBuffer> writer(strbuf);
    document.Accept(writer);

    cout<<"***********************************************************"<<endl;
    std::cout <<strbuf.GetString()<< std::endl;
    cout<<"***********************************************************"<<endl;
    return strbuf.GetString();
}

string JSON::serializeUpdateMsg(string columnName, string value, string condition){
    document.RemoveAllMembers();
    Document::AllocatorType& allocator = document.GetAllocator();

    Value columnNameString(columnName.c_str(), allocator);
    Value valueString(value.c_str(), allocator);
    Value conditionString(condition.c_str(), allocator);

    document.AddMember("request", 3, allocator);
    document.AddMember("columnName", columnNameString, allocator);
    document.AddMember("value", valueString, allocator);
    document.AddMember("condition", conditionString, allocator);

    StringBuffer strbuf;
    Writer<StringBuffer> writer(strbuf);
    document.Accept(writer);

    cout<<"***********************************************************"<<endl;
    std::cout <<strbuf.GetString()<< std::endl;
    cout<<"***********************************************************"<<endl;
    return strbuf.GetString();
}

string JSON::serializeSelectMsg(string columnName){
        document.RemoveAllMembers();
        Document::AllocatorType& allocator = document.GetAllocator();

        Value columnNameString(columnName.c_str(), allocator);

        document.AddMember("request", 3, allocator);
        document.AddMember("columnName", columnNameString, allocator);


        StringBuffer strbuf;
        Writer<StringBuffer> writer(strbuf);
        document.Accept(writer);

        cout<<"***********************************************************"<<endl;
        std::cout <<strbuf.GetString()<< std::endl;
        cout<<"***********************************************************"<<endl;
        return strbuf.GetString();

}
