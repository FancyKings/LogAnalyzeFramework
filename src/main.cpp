#include <iostream>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "config/config.hpp"

#define BACKWARD_HAS_DW 1
#define BACKWARD_HAS_BACKTRACE 1
#include "backward/backward.hpp"

// Use for stack trace
namespace backward{
    backward::SignalHandling sh;
}

// Use for speed up std::ios
static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

using namespace std;

void prepare_enviroment() {
    auto log = spdlog::stdout_color_mt("g_logger");
    log->set_pattern("[%C-%m-%d %H:%M:%S.%e] [%P %t] [%^%l%$] %s:%# %!() %v");
    log->set_level(spdlog::level::debug);
    if (log == nullptr) {
        cout << "log is null" << endl;
        return;
    }
    SPDLOG_LOGGER_INFO(log, "prepare_enviroment");
    toml::table config_table;
    try {
        config_table = toml::parse_file("../../../../config/settings.toml");
        g_config = ConfigParser(config_table);
    }
    catch (const toml::parse_error& err) {
        SPDLOG_LOGGER_ERROR(log, "parse config file error: {}", err.what());
    }
}

int main(int argc, char** argv)
{
    prepare_enviroment();
    auto log = spdlog::get("g_logger");
    SPDLOG_LOGGER_INFO(log, "lark appid: {}", g_config.config_.lark_bot.app_id);
    return 0;
}
