#ifndef CSV_ADAPTER_HPP
#define CSV_ADAPTER_HPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "Person.hpp"

template <class T> 
class CSVStorage
{
private:
    std::string delimeter = ";";
    std::string fileName;
    std::vector<T> data;
    
    bool load();
    void handleLine(const string& line);
    /* data */
public:
    CSVStorage(std::string fileName);
    ~CSVStorage();
    bool Save(); 
    void Append(T* record);
    uint64_t Count();
};

template <class T> 
CSVStorage<T>::CSVStorage(std::string fileName)
{
    this->fileName = fileName; 
    this->load();
}

template <class T> 
bool CSVStorage<T>::load(){
    std::ifstream file(this->fileName);
    std::streambuf* file_buf = file.rdbuf();
    if (file)
    {
        if (!file.fail()){
            std::string line = "";
            char current = 0;
            while (file_buf->in_avail() > 0)
            {  
                current = file_buf->sgetc();
                if (current == '\n')
                {
                    this->handleLine(line);
                    line = "";   
                    std::cerr <<  line;
                }
                else line += current;       
                
                file_buf->snextc();
            }
            if (line != "")     
                this->handleLine(line);
        } 
        file.close();
        return true;
    }
    file.close();
    return false;
}

template <class T>
void CSVStorage<T>::handleLine(const string& line){
    std::vector<string> buffer;
    std::string current = "";
    for (
        auto it = line.cbegin();
        it != line.cend();
        it++
    ) {
        if (std::string(1, *it) == this->delimeter) {
            buffer.push_back(current);
            current = "";  
        } else current +=  *it;
    }
    if (current != "") {
        buffer.push_back(current);
    }
    data.push_back(T::to_object(buffer));
}

template <class T> 
bool CSVStorage<T>::Save(){
    std::ofstream file(this->fileName, ios::out | ios::trunc);
    std::string end = "";
    if (file)
    {   
        for (
            auto it = this->data.begin();
            it != this->data.end();
            it++
        ) {
            file << end << it->to_record(this->delimeter).str();
            end = this->delimeter + "\n";
        }
        file << end;
        file.close();
        return true;
    }
    file.close();
    return false;
}

template <class T>
void CSVStorage<T>::Append(T* record){
    this->data.push_back(*record);
}

template <class T>
uint64_t CSVStorage<T>::Count() {
    return this->data.size();
}

template <class T> 
CSVStorage<T>::~CSVStorage()
{
}

#endif //CSV_ADAPTER_HPP