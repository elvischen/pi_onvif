#include "onvif_api.h"
#include "onvif.nsmap"

int main(int argc, char **argv)
{
    int iRet = 0;
    SOAP_SOCKET m, s;
    struct soap soap;

    soap_init(&soap);    
    if (argc < 2)
        soap_serve(&soap);
    else
    {
        m = soap_bind(&soap, NULL, atoi(argv[1]), 100);
        if (!soap_valid_socket(m))
        {
            soap_print_fault(&soap, stderr);
            exit(-1);
        }
        fprintf(stderr, "Socket connection successful:master socket = %d\n", m);
        for ( ; ; )
        {
             s = soap_accept(&soap);
             fprintf(stderr, "Socket connection successful: slave socket = %d\n", s);
             if (!soap_valid_socket(s))
             {
                 soap_print_fault(&soap, stderr);
                 exit(-1);
             }
             onvif_serve(&soap);
             soap_end(&soap);
        }
    }

    return iRet;
}
