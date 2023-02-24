
#include <boost/json.hpp>
#include <boost/json/src.hpp>
#include <boost/lexical_cast.hpp>

#include <iostream>
#include "include/parser.h"


using namespace boost::json;

 namespace pars
 {   

    std::string Parser::TranslateTextJson(const std::string& text)
    {
        object obj; 
        obj["formula"] = text; 
        // Преобразуем в string
        return  boost::lexical_cast<std::string>(obj);   

    }

 }// namespace pars

