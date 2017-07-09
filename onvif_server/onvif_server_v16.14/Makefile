INCLUDES = -Iinclude
libonviforg_LIB_SUFFIX = $(LIB_SUFFIX)
##### Change the following for your environment:
COMPILE_OPTS =		$(INCLUDES) -I. -O2 -DSOCKLEN_T=socklen_t -D_LARGEFILE_SOURCE=1 -D_FILE_OFFSET_BITS=64 -DWITH_OPENSSL -DWITH_DOM -DDEBUG
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

ONVIF_SERVER = onvifserver$(EXE)
ALL = $(ONVIF_SERVER)
all:	$(ALL)

.$(C).$(OBJ):
	$(C_COMPILER) -c $(C_FLAGS) $<

.$(CPP).$(OBJ):
	$(CPLUSPLUS_COMPILER) -c $(CPLUSPLUS_FLAGS) $<

ONVIF_SERVER_OBJS = onvif_main.$(OBJ) onvif_api.$(OBJ) onvif_devicemgmt.$(OBJ) 

onvif_main.$(C): include/onvifStub.h
onvif_devicemgmt.$(C): include/onvifStub.h

ONVIF_ORG_DIR = ../../onvif_org_lib/v16_14
ONVIF_ORG_LIB = $(ONVIF_ORG_DIR)/libonvif_org.$(libonviforg_LIB_SUFFIX)
LOCAL_LIBS = $(ONVIF_ORG_LIB)
LIBS = $(LOCAL_LIBS) $(LIBS_FOR_CONSOLE_APPLICATION)

onvifserver$(EXE): $(ONVIF_SERVER_OBJS) $(LOCAL_LIBS)
	$(LINK) $@ $(CONSOLE_LINK_OPTS) $(ONVIF_SERVER_OBJS) $(LIBS)

clean:
	-rm -rf *.$(OBJ) core *.core *~

##### Any additional, platform-specific rules come here:
