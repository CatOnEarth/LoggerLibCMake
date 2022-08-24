#pragma once
#define _CRT_SECURE_NO_WARNINGS


/*-----------------------------INCLUDE------------------------------------------------------------*/


#include <iostream>
#include <ctime>


/*-----------------------------DEFINE-------------------------------------------------------------*/


#define LOCATION__          __FILE__, __func__, __LINE__
#define LOCATION_VAR__(var) __FILE__, __func__, __LINE__, #var


/*-----------------------------STRUCT-------------------------------------------------------------*/


/** Struct save description error */
struct _ERROR_INFO__ {
    /** Error code */
    int         err_code__ = 0;
    /** Error text */
    const char* err_text__ = nullptr;
};

/** Struct save description warning*/
struct _WARN_INFO__ {
    /** Warning code */
    int         warn_code__ = 0;
    /** Warning text */
    const char* warn_text__ = nullptr;
};

/** Struct to save location */
struct _LOCATION_STRUCT_CALL__ {
    /** Filename */
    const char* filename__  = "";
    /** Function name */
    const char* func_name__ = "";
    /** Line in file */
    int         line__      = -1;
};

/** Struct to save location */
struct _LOCATION_VAR_CALL_STRUCT__ {
    /** Filename */
    const char* filename__  = "";
    /** Function name */
    const char* func_name__ = "";
    /** Line in file */
    int         line__      = -1;
    /** Var name */
    const char* var_name__  = "";
};


/*----------------------------ERROR LOG-------------------------------------------------------------*/


/** Function create error log
* @param path_log Path to error log file
* @param name_module Module, where error was detected
* @param err_info information about error
* @param first_call Information about first call method
* @param error_call Information about last call method before error
* @return -1 If can't create/open log file
* @return 0  If log create successful
*/
int CreateErrorLog(const char* path_log               ,
                   const char* name_module            ,
                   _ERROR_INFO__ err_info             ,
                   _LOCATION_STRUCT_CALL__ first_call ,
                   _LOCATION_STRUCT_CALL__ error_call);


/*---------------------------------WARN LOG---------------------------------------------------*/


/** Function create warning log
* @param path_log Path to warn log file
* @param name_module Module, where error was detected
* @param warn_info information about warning
* @param warn_call Information about last call method before warning
* @return -1 If can't create/open log file
* @return 0  If log create successful
*/
int CreateWarnLog(const char* path_log              ,  
                  const char* name_module           ,  
                  _WARN_INFO__ warn_info            , 
                  _LOCATION_STRUCT_CALL__ warn_call);


/*--------------------------------------INFO LOG----------------------------------------------*/


/** Function create info log
* @param path_log Path to warn log file
* @param name_module Module, where error was detected
* @param info_text information
* @return -1 If can't create/open log file
* @return 0  If log create successful
*/
int CreateInfoLog(const char* path_log   , 
                  const char* name_module, 
                  const char* info_text );
