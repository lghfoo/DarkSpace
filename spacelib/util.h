#ifndef UTIL_H
#define UTIL_H
#include<string>
#include<sstream>
#include<qstring.h>
class Util{
public:
    template<typename T>
    static QString addressAsString(T obj){
        std::ostringstream oss;
        oss << &obj;
        return QString::fromStdString(oss.str());
    }
};

#endif // UTIL_H
