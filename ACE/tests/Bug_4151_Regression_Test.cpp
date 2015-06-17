
//=============================================================================
/**
 *  @file   Bug_4151_Regression_Test.cpp 
 *
 *  Tests stream initialization after previous failed service initializatoin
 *
 *  @author Stanislav Ravas <ravas@tind.sk>
 */
//=============================================================================


#include "test_config.h"
#include "ace/Init_ACE.h"
#include "ace/Service_Config.h"
#include "ace/Log_Msg.h"

int
run_main (int argc, ACE_TCHAR *argv[])
{
    int r = 0;

    ACE::init();

    ACE_START_TEST (ACE_TEXT ("Bug_4151_Regression_Test"));

    ACE_Service_Config::open(argc, argv, ACE_DEFAULT_LOGGER_KEY, 0, 1, 1);
    ACE_Service_Config::process_file("Bug_4151_Regression_Test.conf");

    bool mod1 = (ACE_Service_Config::instance()->find("mod1") == 0);
    bool mod2 = (ACE_Service_Config::instance()->find("mod2") == 0); 

    if(!mod1)
        ACE_ERROR((LM_ERROR, ACE_TEXT("Module mod1 not loaded!\n")));

    if(!mod2)
        ACE_ERROR((LM_ERROR, ACE_TEXT("Module mod2 not loaded!\n")));

    r = (mod1 && mod2) ? 0 : 1;

    ACE_Service_Config::fini_svcs();
    ACE_Service_Config::close();

    ACE_END_TEST;

    ACE::fini();
    return r;
}

