#include <fstream>
#include <iostream>
#include <vector>
#include "toml++/toml.h"
#include "spdlog/spdlog.h"

using namespace std;

#ifndef CONFIG_HPP
#define CONFIG_HPP

class RegexConfig {
public:
    vector<string> regex_list;
};

class LarkBotConfig {
public:
    string app_id;
    string app_key;
};

class Config {
public:
    LarkBotConfig lark_bot;
    RegexConfig regex;
};

class ConfigParser {
public:

    Config config_;
    shared_ptr<spdlog::logger> log_;

    ConfigParser(const toml::table& table);

    ConfigParser();

};

extern ConfigParser g_config;
#endif // CONFIG_HPP