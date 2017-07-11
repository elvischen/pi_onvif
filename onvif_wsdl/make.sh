#!/bin/sh
# gsoap版本: 2.8.48

mkdir all
strall="devicemgmt.wsdl"
echo $strall
echo start wsdl2h ...
./wsdl2h -sck  -o all/all.h -Nabc -t./onvif_typemap.dat $strall
cp ./onvif-header.h all/
cd all
cat all.h >> ./onvif-header.h
mv onvif-header.h all.h
cd ..
./soapcpp2 -c -L -w -x  all/all.h -Iimport -Icustom -dall -n -ponvif
