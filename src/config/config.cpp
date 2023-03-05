#include "config.hpp"

ConfigParser::ConfigParser(const toml::table& table)
    : config_{}, log_{spdlog::get("g_logger")}
{
    config_.lark_bot.app_id = table["LARK_BOT"]["APPID"].value_or("");
    config_.lark_bot.app_key = table["LARK_BOT"]["APPKEY"].value_or("");
    SPDLOG_LOGGER_DEBUG(log_, "APP ID: {}", config_.lark_bot.app_id);
    SPDLOG_LOGGER_DEBUG(log_, "APP KEY: {}", config_.lark_bot.app_key);
    const auto& regex_list = table["REGEX"]["LIST"];
    if (const toml::array* arr = regex_list.as_array()) {
        for (const auto& item : *arr) {
            auto str = *item.value<string>();
            if (!str.empty()) {
                config_.regex.regex_list.push_back(str);
                SPDLOG_LOGGER_DEBUG(log_, "REGEX: {}", str);
            }
        }
    }
}

ConfigParser::ConfigParser() {
}

ConfigParser g_config{};