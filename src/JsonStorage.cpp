//
//  JsonStorage.cpp
//  JsonStg
//
//  Created by DiCode77.
//

#include "JsonStorage.hpp"

JsonStorage::JsonStorage() : m_json_stg(nlohmann::json::object()){}

JsonStorage::JsonStorage(const std::string &file_name) : JsonStorage::JsonStorage(){
}

void JsonStorage::SetStorageName(const std::string&){
    
}

std::string JsonStorage::GetConfig(const int &format) const{
    return this->m_json_stg.dump(format);
}

void JsonStorage::Clear(){
    this->m_json_stg.clear();
}

void JsonStorage::Refresh(){
}

std::size_t JsonStorage::Size() const{
    return this->m_json_stg.size();
}

bool JsonStorage::Empty() const{
    return this->m_json_stg.empty();
}

bool JsonStorage::IsCheck(const std::string &key) const{
    if (this->m_json_stg.contains(key)){
        return true;
    }
    return false;
}

bool JsonStorage::IsCheck(const std::string &key, const std::string &key2) const{
    if (this->IsCheck(key)){
        if (this->m_json_stg[key].contains(key2)){
            return true;
        }
    }
    return false;
}

bool JsonStorage::Delete(const std::string &key){
    if (IsCheck(key)){
        this->m_json_stg.erase(key);
        return true;
    }
    return false;
}

bool JsonStorage::Delete(const std::string &key, const std::string &key2){
    if (IsCheck(key, key2)){
        this->m_json_stg[key].erase(key);
        return true;
    }
    return false;
}
