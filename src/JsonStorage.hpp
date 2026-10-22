//
//  JsonStorage.hpp
//  JsonStg
//
//  Created by DiCode77.
//

#ifndef JsonStorage_hpp
#define JsonStorage_hpp

#include <nlohmann/json.hpp>
#include <fstream>

class JsonStorage{
    nlohmann::json m_json_stg;
    std::ofstream  m_file;
public:
    JsonStorage();
    JsonStorage(const std::string&);
    
    void SetStorageName(const std::string&);

    template <typename Templ> bool Add(const std::string&, const Templ&);
    template <typename Templ> bool Edit(const std::string&, const Templ&);
    
    template <typename Templ> bool Add(const std::string&,  const std::string&, const Templ&);
    template <typename Templ> bool Edit(const std::string&, const std::string&, const Templ&);
    
    std::string GetConfig(const int& = -1) const;
    
    template <typename Templ> Templ Get(const std::string&);
    template <typename Templ> Templ Get(const std::string&, const std::string&);
    
    void Clear();
    void Refresh();
    std::size_t Size() const;
    bool Empty() const;
    
    bool IsCheck(const std::string&) const;
    bool IsCheck(const std::string&, const std::string&) const;
    
    bool Delete(const std::string&);
    bool Delete(const std::string&, const std::string&);
};

template <typename Templ>
bool JsonStorage::Add(const std::string &key, const Templ &val){
    if (!this->IsCheck(key)){
        this->m_json_stg[key] = val;
        return true;
    }
    return false;
}

template <typename Templ>
bool JsonStorage::Edit(const std::string &key, const Templ &val){
    if (this->IsCheck(key)){
        this->m_json_stg[key] = val;
        return true;
    }
    return false;
}

template <typename Templ>
bool JsonStorage::Add(const std::string &key,  const std::string &key2, const Templ &val){
    if (!this->IsCheck(key, key2)){
        this->m_json_stg[key][key2] = val;
        return true;
    }
    return false;
}

template <typename Templ>
bool JsonStorage::Edit(const std::string &key, const std::string &key2, const Templ &val){
    if (this->IsCheck(key, key2)){
        this->m_json_stg[key][key2] = val;
        return true;
    }
    return false;
}

template <typename Templ>
Templ JsonStorage::Get(const std::string &key){
    if (IsCheck(key)){
        if (!this->m_json_stg[key].is_object()){
            return this->m_json_stg[key].get<Templ>();
        }
    }
    return {};
}

template <typename Templ>
Templ JsonStorage::Get(const std::string &key, const std::string &key2){
    if (IsCheck(key, key2)){
        return this->m_json_stg[key][key2].get<Templ>();
    }
    return {};
}

#endif /* JsonStorage_hpp */
