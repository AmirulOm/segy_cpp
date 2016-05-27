#include <iostream>
//#include <cstdint>
#include <cstring>
#include <fstream>


    
//static const struct x EmptyStruct;
// const string BFHeadText [] {
//     "JOB_ID",
//     "LINE_NUM",
//     "REEL_NUM",
//     "NUM_OF_TRACE",
//     "NUM_OF_AUX",
//     "INTERVAL_MS",
//     "INTERVAL_MS_ORI",
//     "NUM_OF_SAMPLES",
//     "NUM_OF_SAMPLES_ORI",
//     "SAMPLE_FORMAT",
//     "ENSEMBLE",
//     "TRACE_SORT",
//     "VERT_SUM",
//     "SWEEP_FREQ_START",
//     "SWEEP_FREQ_END",
//     "SWEEP_LENGTH",
//     "SWEEP_TYPE",
//     "SWEEP_NUM_CHANNEL",
//     "SWEEP_TAPER_LEN_START",
//     "SWEEP_TAPER_LEN_END",
//     "TAPER_TYPE",
//     "CORRELATED",
//     "BINARY_GAIN",
//     "AMP_RECOR",
//     "MEASURE_SYSTEM",
//     "IMPULSE_POLAR",
//     "POLAR_CODE",
//     "UNNASSIGNED1",
//     "SEGY_REV_NUM",
//     "FIXED_LEN",
//     "NUM_EXT_HEAD",
//     "UNNASSIGNED2",
// }

struct binaryFileHeader{
    int JOB_ID;                     //
    int LINE_NUM;
    int REEL_NUM;
    short int NUM_OF_TRACE;
    short int NUM_OF_AUX;
    short int INTERVAL_MS;
    short int INTERVAL_MS_ORI;
    short int NUM_OF_SAMPLES;
    short int NUM_OF_SAMPLES_ORI;
    short int SAMPLE_FORMAT;
    short int ENSEMBLE;
    short int TRACE_SORT;
    short int VERT_SUM;
    short int SWEEP_FREQ_START;
    short int SWEEP_FREQ_END;
    short int SWEEP_LENGTH;
    short int SWEEP_TYPE;
    short int SWEEP_NUM_CHANNEL;
    short int SWEEP_TAPER_LEN_START;
    short int SWEEP_TAPER_LEN_END;
    short int TAPER_TYPE;
    short int CORRELATED;
    short int BINARY_GAIN;
    short int AMP_RECOR;
    short int MEASURE_SYSTEM;
    short int IMPULSE_POLAR;
    short int POLAR_CODE;
    char UNNASSIGNED1 [240];
    short int SEGY_REV_NUM;
    short int FIXED_LEN;
    short int NUM_EXT_HEAD;
    char UNNASSIGNED2 [94];
};

struct traceHeader {
    int TRACE_SEQ_GLOBAL;
    int TRACE_SEQ_LOCAL;
    int ORI_RECORD_NUM;
    int TRACE_NUM_FIELD;
    int SOURCE_POINT;
    int ENSEMBLE_NUM;
    int ENS_TRACE_NUM;
    short int TRACE_CODE;
    short int NUM_VERT_SUM;
    short int NUM_HORZ_SUM;
    short int DATA_USE;
    int DIST_CENT_RECV;
    int RECV_GRP_ELEV;
    int SURF_ELEV_SRC;
    int SOURCE_DEPTH;
    int DATUM_ELEV_RECV;
    int DATUM_ELAV_SRC;
    int WATER_DEPTH_SRC;
    int WATER_DEPTH_GRP;
    short int SCALE_DEPTH;
    short int SCALE_COOR;
    int SRC_COOR_X;
    int SRC_COOR_Y;
    int GRP_COOR_X;
    int GRP_COOR_Y;
    short int COOR_UNIT;
    short int WEATHER_VEL;
    short int SWEATHER_VEL;
    short int UPHOLE_T_SRC;
    short int UPHOLE_T_GRP;
    short int SRC_STA_CORRC;
    short int GRP_STA_CORRC;
    short int TOTAL_STA;
    short int LAG_TIME_A;
    short int LAG_TIME_B;
    short int DELAY_T;
    short int MUTE_T_STRT;
    short int MUTE_T_END;
    short int NUM_OF_SAMPL;
    short int SAMPLE_INTRVL;
    short int GAIN_TYPE;
    short int GAIN_CONST;
    short int GAIN_INIT;
    short int CORRLTD;
    short int SWEEP_FREQ_START;
    short int SWEEP_FREQ_END;
    short int SWEEP_LENGTH;
    short int SWEEP_TYPE;
    short int SWEEP_TAPER_LEN_START;
    short int SWEEP_TAPER_LEN_END;
    short int TAPER_TYPE;
    short int ALIAS_FREQ;
    short int ALIAS_SLOPE;
    short int NOTCH_FREQ;
    short int NOTCH_SLOPE;
    short int LOWCUT_FREQ;
    short int HIGHCUT_FREQ;
    short int LOWCUT_SLOPE;
    short int HIGHCUT_SLOPE;
    short int YEAR;
    short int DAY;
    short int HOUR;
    short int MINUTE;
    short int SECOND;
    short int TIME_CODE;
    short int WEIGHT_FACT;
    short int GEOPHNE_ROLL;
    short int GEOPHNE_TRACE;
    short int GEOPHNE_LAST;
    short int GAP_SIZE;
    short int OVER_TRAVEL;
    int ENS_COOR_X;
    int ENS_COOR_Y;
    int INLINE;
    int CROSS;
    int SHOOTPOINT;
    short int SHOOTPOINT_SCALE;
    short int TRACE_UNIT;
    char TRANSD_CONST [6];
    short int TRANSD_UNIT;
    short int TRACE_IDENT;
    short int SCALE_TIME;
    short int SRC_ORIENT;
    char SRC_DIRECTION [6];
    char SRC_MEASUREMT [6];
    short int SRC_UNIT;
    char UNNASSIGNED1 [6];
};

class segy
{
public:
    segy();
    ~segy();
    void OpenFile(std::string);
    void SaveFile();
    void CloseFile();
    void GetAllTrace();
    void ReadAllTrace();
    void SetTrace();
    int toLitteEnd(int);
    short int toLitteEnd(short int);
    unsigned char TFileHead_ [3200];
    binaryFileHeader BFileHead_;
    unsigned char ExTFileHead_ [3200];
    traceHeader traceHeader_;
    float *Trace_;
    
    std::string filename_;
    std::fstream in_;
private:
    // char TFileHead_ [3200];
    
   
};

segy::segy()
{
}

segy::~segy()
{
}

int segy::toLitteEnd(int a){
    short int tmp1=(a>>16);
    short int tmp2=(a* 0x0000FFFF);
    tmp2 = toLitteEnd(tmp2);
    tmp1 = toLitteEnd(tmp1);
    
    int b = (int)tmp2;
    b = b << 16;
    b = b | (int)tmp1;
    // tmp1 = (a>>16);
    // tmp2 = a* 0x0000FFFF;
    return b;
}

short int segy::toLitteEnd(short int a){
    short int tmp = a>>8;
    return (a<<8) | (tmp);
}

void segy::OpenFile(std::string fl)
{
    char temp [400];
    filename_ = fl;
    in_.open(filename_.c_str(),std::ifstream::in);
    memset( TFileHead_, '\0', sizeof(char) * 3200 );
    in_.read((char *)TFileHead_, sizeof(TFileHead_));
    in_.read(temp, sizeof(temp));
    std::memcpy(&BFileHead_,temp,sizeof(temp));
    
    //while(is.eof()){
    in_.read(temp, sizeof(traceHeader_));
    std::memcpy(&traceHeader_,temp,sizeof(traceHeader_));
    //}
}