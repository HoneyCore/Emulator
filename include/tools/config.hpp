#ifndef CONFIG_HPP
#define CONFIG__HPP

#include "general.hpp"
#include <fstream>

typedef struct config
{
    uint64 disk_size;
    uint64 ram_size;
    std::string disk_filename;
} config;

class ConfigTools
{
    public:
        void parse_config_file(int fd);
        int open_config_file(std::string filename);
};

#endif