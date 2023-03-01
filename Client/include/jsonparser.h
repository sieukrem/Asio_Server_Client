#pragma once


#include <iostream>



namespace Serf
{
    class jsonparser
    {
    public:
        std::string TranslateTextJson(const std::string& key, const std::string& text);

        std::string TranslateJsonText(const std::string& key,const std::string& jsontext);

        std::string GetParsText(std::string& jsontext, const std::string &message);

    };
} // namespace pars
