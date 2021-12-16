#ifndef _STRUCT_H_
#define _STRUCT_H_

struct S_meteo{
    float temp;
    unsigned long pression;
    unsigned short humidity;
};

struct S_geo{
    unsigned int altitude;
};

struct S_data{
    struct S_meteo meteo;
    struct S_geo geo;
    char str_time[20];
};

//une instance commune de data pour tous les fichiers incluants struct.h
struct S_data data;

#endif
