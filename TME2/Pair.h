#include <iostream>
#include <fstream>
#include <regex>
#include <algorithm>
#include <vector>
#include <chrono>
#include <cstddef>
#include <iosfwd>



namespace pr{
    class Pair{
        std::string str;
        int cpt;
    public:
        Pair(std::string str_ori, int cpt_ori=1): str(str_ori), cpt(cpt_ori){}
        std::string Stringer(){
            return str;
        }
        int Inter(){
            return cpt;
        }
        void operator++(){
            cpt++;
        }
    };
}
        
            
