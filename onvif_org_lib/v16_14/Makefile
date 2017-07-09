INCLUDES = -Iinclude
##### Change the following for your environment:
COMPILE_OPTS =		$(INCLUDES) -I. -O2 -DSOCKLEN_T=socklen_t -D_LARGEFILE_SOURCE=1 -D_FILE_OFFSET_BITS=64
C =			c
C_COMPILER =		cc
C_FLAGS =		$(COMPILE_OPTS) $(CPPFLAGS) $(CFLAGS)
CPP =			cpp
CPLUSPLUS_COMPILER =	c++
CPLUSPLUS_FLAGS =	$(COMPILE_OPTS) -Wall -DBSD=1 $(CPPFLAGS) $(CXXFLAGS)
OBJ =			o
LINK =			c++ -o
LINK_OPTS =		-L. $(LDFLAGS)
CONSOLE_LINK_OPTS =	$(LINK_OPTS)
LIBRARY_LINK =		ar cr 
LIBRARY_LINK_OPTS =	
LIB_SUFFIX =			a
LIBS_FOR_CONSOLE_APPLICATION =
LIBS_FOR_GUI_APPLICATION =
EXE =
##### End of variables to change

NAME = libonvif_org
ONVIF_ORG_LIB = $(NAME).$(LIB_SUFFIX)
ALL = $(ONVIF_ORG_LIB)
all:	$(ALL)

OBJS = onvifC.$(OBJ) onvifServer.$(OBJ) onvifClient.$(OBJ) duration.$(OBJ) stdsoap2.$(OBJ)

$(ONVIF_ORG_LIB): $(OBJS)
	$(LIBRARY_LINK)$@ $(LIBRARY_LINK_OPTS) $(OBJS)

.$(C).$(OBJ):
	$(C_COMPILER) -c $(C_FLAGS) $<

.$(CPP).$(OBJ):
	$(CPLUSPLUS_COMPILER) -c $(CPLUSPLUS_FLAGS) $<

onvifServer.$(C): include/onvifH.h
include/onvifH.h: include/onvifStub.h 
include/onvifStub.h: include/stdsoap2.h
onvifClient.$(C): include/onvifH.h
onvifC.$(C): include/onvifH.h
stdsoap2.$(C): include/stdsoap2.h
duration.$(C): include/onvifH.h

clean:
	-rm -rf *.$(OBJ)

##### Any additional, platform-specific rules come here:
