#include "info_log_context.h"

namespace ngxplus {

const std::string InfoLogContext::INFO_LOG_NAME_DEFAULT("error.log");

// singlet
InfoLogContext* info_log_context = nullptr;

} // ngxplus
