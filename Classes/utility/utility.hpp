//
//  utility.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/24.
//
//

#ifndef utility_hpp
#define utility_hpp

#include <stdio.h>

inline int stringToint(const std::string& str){
    int number = 0;
    sscanf(str.c_str(), "%d", &number);
    return number;
}
inline float stringToFloat(const std::string& str){
    float number = 0.0;
    sscanf(str.c_str(), "%f", &number);
    return number;
}
inline double stringToDouble(const std::string& str){
    double number = 0.0;
    sscanf(str.c_str(), "%lf", &number);
    return number;
}

inline std::string intToString(int number){
    std::size_t length = 0;
    int numberTemp = number;
    do {
        ++length;
        numberTemp /= 10;
    }while (numberTemp > 0);
    char str[length];
    sprintf(str, "%d", number);
    return std::string(str);
}
inline std::string floatToString(float number){
    std::size_t length = 0;
    int numberInt = static_cast<int>(number);
    do {
        ++length;
        numberInt /= 10;
    } while (numberInt > 0);
    length += 5;
    char str[length];
    sprintf(str, "%f", number);
    return std::string(str);
}
inline std::string doubleToString(double number){
    std::size_t length = 0;
    int numberInt = static_cast<int>(number);
    do {
        ++length;
        numberInt /= 10;
    } while(numberInt > 10);
    length += 10;
    char str[length];
    sprintf(str, "%lf", number);
    return std::string(str);
}


#endif /* utility_hpp */
