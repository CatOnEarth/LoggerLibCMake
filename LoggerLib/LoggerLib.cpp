/*! \mainpage LoggerLib
 *
 * This Logger will help you to easy create logs
 *
 */




#include "LoggerLib.h"

int CreateErrorLog(const char* path_log              , 
				   const char* name_module           , 
				   _ERROR_INFO__ err_info            ,
				   _LOCATION_STRUCT_CALL__ first_call, 
	               _LOCATION_STRUCT_CALL__ error_call) {

    time_t seconds = time(NULL);
    tm* timeinfo   = localtime(&seconds);

    fprintf(stderr, "\n\nERROR CODE: %d"
                     "\nERROR TEXT: %s"
                     "\n\tCOMPILE TIME: %s %s"
                     "\n\tCURRENT TIME: %s"
                     "\tMODULE: %s"
                     "\n\t\t\tFILENAME: %s"
                     "\n\t\t\tFUNCTION: %s"
                     "\n\t\t\tLINE: %d"
                     "\n\t\t\tFILENAME: %s"
                     "\n\t\t\tFUNCTION: %s"
                     "\n\t\t\tLINE: %d\n",
                     err_info.err_code__, 
                     err_info.err_text__, 
                     __DATE__, 
                     __TIME__, 
                     asctime(timeinfo), 
                     name_module, 
                     first_call.filename__, 
                     first_call.func_name__, 
                     first_call.line__, 
                     error_call.filename__, 
                     error_call.func_name__, 
                     error_call.line__);

    FILE* file_log = fopen(path_log, "a+");
    if (file_log == nullptr) {
        printf("\n\nERROR CODE: %d"
               "\nERROR TEXT: %s"
               "\n\tTIME: %s"
               "\n\tMODULE: %s", 
               -1, 
               "Cannot open log file", 
               asctime(timeinfo), 
               name_module);
        return -1;
    }

    setvbuf(file_log, (char*)NULL, _IONBF, 0);
    fprintf(file_log, "\n\nERROR CODE: %d"
                      "\nERROR TEXT: %s"
                      "\n\tCOMPILE TIME: %s %s"
                      "\n\tCURRENT TIME: %s"
                      "\tMODULE: %s"
                      "\n\t\t\tFILENAME: %s"
                      "\n\t\t\tFUNCTION: %s"
                      "\n\t\t\tLINE: %d"
                      "\n\t\t\tFILENAME: %s"
                      "\n\t\t\tFUNCTION: %s"
                      "\n\t\t\tLINE: %d\n",
                      err_info.err_code__,
                      err_info.err_text__,
                      __DATE__,
                      __TIME__,
                      asctime(timeinfo),
                      name_module,
                      first_call.filename__,
                      first_call.func_name__,
                      first_call.line__,
                      error_call.filename__,
                      error_call.func_name__,
                      error_call.line__);
    fclose(file_log);

    char buffer_cmd[128] = "";
    snprintf(buffer_cmd, sizeof(buffer_cmd), "start %s", path_log);

    system(buffer_cmd);

    return 0;
}

int CreateWarnLog(const char* path_log             , 
	              const char* name_module          , 
	              _WARN_INFO__ warn_info           ,   
	              _LOCATION_STRUCT_CALL__ warn_call) {

    time_t seconds = time(NULL);
    tm* timeinfo   = localtime(&seconds);

    fprintf(stderr, "\n\nWARN CODE: %d"
                    "\nWARN TEXT: %s"
                    "\n\tCOMPILE TIME: %s %s"
                    "\n\tCURRENT TIME: %s"
                    "\n\tMODULE: %s"
                    "\n\t\t\tFILENAME: %s"
                    "\n\t\t\tFUNCTION: %s"
                    "\n\t\t\tLINE: %d\n",
                    warn_info.warn_code__, 
                    warn_info.warn_text__, 
                    __DATE__, 
                    __TIME__, 
                    asctime(timeinfo), 
                    name_module, 
                    warn_call.filename__, 
                    warn_call.func_name__, 
                    warn_call.line__);

    FILE* file_log = fopen(path_log, "a+");
    if (file_log == nullptr) {
        fprintf(stderr, "\n\nERROR CODE: %d"
                        "\nERROR TEXT: %s"
                        "\n\tTIME: %s"
                        "\n\tMODULE: %s", 
                        -1, 
                        "Cannot open log file", 
                        asctime(timeinfo), 
                        name_module);
        printf("\n\nERROR CODE: %d"
               "\nERROR TEXT: %s"
               "\n\tTIME: %s"
               "\n\tMODULE: %s",
                -1,
                "Cannot open log file",
                asctime(timeinfo),
                name_module);
        return -1;
    }

    setvbuf(file_log, (char*)NULL, _IONBF, 0);
    fprintf(file_log,  "\n\nWARN CODE: %d"
                       "\nWARN TEXT: %s"
                       "\n\tCOMPILE TIME : %s %s"
                       "\n\tCURRENT TIME : %s"
                       "\tMODULE: %s"
                       "\n\t\tFILENAME: %s"
                       "\n\t\t\tFUNCTION: %s"
                       "\n\t\t\tLINE: %d\n",
                        warn_info.warn_code__, 
                        warn_info.warn_text__, 
                        __DATE__,
                        __TIME__, 
                        asctime(timeinfo), 
                        name_module, 
                        warn_call.filename__, 
                        warn_call.func_name__, 
                        warn_call.line__);

    fclose(file_log);

    char buffer_cmd[128] = "";
    snprintf(buffer_cmd, sizeof(buffer_cmd), "start %s", path_log);

    system(buffer_cmd);

    return 0;
}

int CreateInfoLog(const char* path_log   , 
				  const char* name_module, 
	              const char* info_text  ) {
    time_t seconds = time(NULL);
    tm* timeinfo = localtime(&seconds);

    fprintf(stderr, "\n\nINFO: %s\n\n", info_text);

    FILE* file_log = fopen(path_log, "a+");
    if (file_log == nullptr) {
        printf("\n\nERROR CODE: %d\nERROR TEXT: %s\n\tTIME: %s\n\tMODULE: %s", -1, "Cannot open log file", asctime(timeinfo), name_module);
        return -1;
    }

    setvbuf(file_log, (char*)NULL, _IONBF, 0);
    fprintf(file_log, "\n\nINFO: %s\n\n", info_text);

    fclose(file_log);

    char buffer_cmd[128] = "";
    snprintf(buffer_cmd, sizeof(buffer_cmd), "start %s", path_log);

    system(buffer_cmd);

    return 0;
}
