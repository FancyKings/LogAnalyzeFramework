add_rules("mode.debug", "mode.release")

set_languages("c17", "c++23")

-- Build target control log level
if is_mode("debug") then
    add_defines("SPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_DEBUG")
else
    add_defines("SPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_INFO")
end

-- "boost 1.81.0"
add_requires("spdlog v1.11.0",
             "toml++ v3.3.0",
             "backward-cpp v1.6")

-- Compile conf parser as static lib
target("configparser")
    set_kind("shared")
    add_packages("toml++", "spdlog")
    add_files("src/config/*.cpp")

target("logAnaFwk")
    set_kind("binary")
    add_files("src/*.cpp")
    add_packages("spdlog",
                 "toml++",
                 "backward-cpp")
    add_deps("configparser")


add_ldflags("-ldw")
--
-- If you want to known more usage about xmake, please see https://xmake.io
--
-- ## FAQ
--
-- You can enter the project directory firstly before building project.
--
--   $ cd projectdir
--
-- 1. How to build project?
--
--   $ xmake
--
-- 2. How to configure project?
--
--   $ xmake f -p [macosx|linux|iphoneos ..] -a [x86_64|i386|arm64 ..] -m [debug|release]
--
-- 3. Where is the build output directory?
--
--   The default output directory is `./build` and you can configure the output directory.
--
--   $ xmake f -o outputdir
--   $ xmake
--
-- 4. How to run and debug target after building project?
--
--   $ xmake run [targetname]
--   $ xmake run -d [targetname]
--
-- 5. How to install target to the system directory or other output directory?
--
--   $ xmake install
--   $ xmake install -o installdir
--
-- 6. Add some frequently-used compilation flags in xmake.lua
--
-- @code
--    -- add debug and release modes
--    add_rules("mode.debug", "mode.release")
--
--    -- add macro defination
--    add_defines("NDEBUG", "_GNU_SOURCE=1")
--
--    -- set warning all as error
--    set_warnings("all", "error")
--
--    -- set language: c99, c++11
--    set_languages("c99", "c++11")
--
--    -- set optimization: none, faster, fastest, smallest
--    set_optimize("fastest")
--
--    -- add include search directories
--    add_includedirs("/usr/include", "/usr/local/include")
--
--    -- add link libraries and search directories
--    add_links("tbox")
--    add_linkdirs("/usr/local/lib", "/usr/lib")
--
--    -- add system link libraries
--    add_syslinks("z", "pthread")
--
--    -- add compilation and link flags
--    add_cxflags("-stdnolib", "-fno-strict-aliasing")
--    add_ldflags("-L/usr/local/lib", "-lpthread", {force = true})
--
-- @endcode
--

