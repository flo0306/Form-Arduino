#include <stdio.h>

struct S_meteo{
    float temp;
    uint32_t pression;
    uint8_t humidity;
};

struct S_gyro{
    float gx, gy, gz;
    float ix, iy, iz;
};

struct S_data{
    struct S_meteo meteo;
    struct S_gyro gyro;
};

union U_S_data{
    struct S_data s;
    uint8_t b[sizeof(struct S_data)];
};

void viewUnionOfS_Data(struct S_data structData){
    union U_S_data usd;
    usd.s=structData;
    
    for(int i=0;i<sizeof(struct S_data);i++){
        printf("%d;", usd.b[i]);
    }
    printf("\n");
}

void setTemperature(struct S_data *d){
    //(*m).temp=27.0F; syntaxe identique que celle du dessous
    d->meteo.temp=27.0F;
    d->meteo.temp=25.0F;
    d->meteo.pression=120000.0F;
    d->meteo.humidity=80.0F;
}

void setGyro(struct S_data *d){
    d->gyro.gx=1.0F;
    d->gyro.gy=2.0F;
    d->gyro.gz=3.0F;
    d->gyro.ix=4.0F;
    d->gyro.iy=5.0F;
    d->gyro.iz=6.0F;
}

int main(int argc, const char * argv[]) {
    
    struct S_data data;
    data.meteo.temp=0.0F;
    data.meteo.pression=0.0F;
    data.meteo.humidity=0.0F;
    data.gyro.gx=0.0F;
    data.gyro.gy=0.0F;
    data.gyro.gz=0.0F;
    data.gyro.ix=0.0F;
    data.gyro.iy=0.0F;
    data.gyro.iz=0.0F;
    
    setTemperature(&data);
    setGyro(&data);
    viewUnionOfS_Data(data);
    printf("%.2f;%6u;%2d;%.3f;%.3f;%.3f;%.3f;%.3f;%.3f\n",data.meteo.temp,data.meteo.pression,data.meteo.humidity,data.gyro.gx,data.gyro.gy,data.gyro.gz,data.gyro.ix,data.gyro.iy,data.gyro.iz);
    return 0;
}
