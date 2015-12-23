
/***********************************************
  File name		: log.h
  Create date	: 2015-12-17 23:12
  Modified date : 2015-12-18 02:28
  Author		: zmkeil, alibaba.inc
  Express : 
    Usually, log module is first inited,
    if error, write into stderr
  
 **********************************************/
#ifndef NGXPLUS_LOG
#define NGXPLUS_LOG

extern "C" {
#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_log.h>
}
#include "common.h"

namespace ngxplus {

#define NGX_LOG_LEVEL_STDERR    0
#define NGX_LOG_LEVEL_EMERG     1
#define NGX_LOG_LEVEL_ALERT     2
#define NGX_LOG_LEVEL_CRIT      3
#define NGX_LOG_LEVEL_ERROR     4
#define NGX_LOG_LEVEL_WARN      5
#define NGX_LOG_LEVEL_NOTICE    6
#define NGX_LOG_LEVEL_INFO      7
#define NGX_LOG_LEVEL_DEBUG     8

class Log 
{
public:
    bool init();
    bool init(const std::string& name);
    bool init(const std::string& name, int level);

    void comlog_write(int level, const char* fmt, ...);

    void comlog_write_core(int level, const char* fmt, va_list args);

private:
    ngx_open_file_t _file;
    int _level;

private:
    const static char* LOG_PATH;
    const static int MAX_ERROR_STR = 500;
};

} // ngxplus
#endif
