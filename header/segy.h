struct segy{
    char TextFileHead [3200];
};

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
};

