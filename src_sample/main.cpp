#include <iostream>

#include "../header/segy.h"

	static const unsigned char e2a[256] = {
          0,  1,  2,  3,156,  9,134,127,151,141,142, 11, 12, 13, 14, 15,
         16, 17, 18, 19,157,133,  8,135, 24, 25,146,143, 28, 29, 30, 31,
        128,129,130,131,132, 10, 23, 27,136,137,138,139,140,  5,  6,  7,
        144,145, 22,147,148,149,150,  4,152,153,154,155, 20, 21,158, 26,
         32,160,161,162,163,164,165,166,167,168, 91, 46, 60, 40, 43, 33,
         38,169,170,171,172,173,174,175,176,177, 93, 36, 42, 41, 59, 94,
         45, 47,178,179,180,181,182,183,184,185,124, 44, 37, 95, 62, 63,
        186,187,188,189,190,191,192,193,194, 96, 58, 35, 64, 39, 61, 34,
        195, 97, 98, 99,100,101,102,103,104,105,196,197,198,199,200,201,
        202,106,107,108,109,110,111,112,113,114,203,204,205,206,207,208,
        209,126,115,116,117,118,119,120,121,122,210,211,212,213,214,215,
        216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,
        123, 65, 66, 67, 68, 69, 70, 71, 72, 73,232,233,234,235,236,237,
        125, 74, 75, 76, 77, 78, 79, 80, 81, 82,238,239,240,241,242,243,
         92,159, 83, 84, 85, 86, 87, 88, 89, 90,244,245,246,247,248,249,
         48, 49, 50, 51, 52, 53, 54, 55, 56, 57,250,251,252,253,254,255
};

int main () {
	std::cout << sizeof(binaryFileHeader) << " "<< sizeof(segy) << " "<< sizeof(traceHeader)<< std::endl;
	
	segy sgy;
	sgy.OpenFile("velocity.segy");
	
	// std::cout << sgy.TFileHead_[1];
	



    // for (size_t i = 0; i < 400; i++)
	// {
	// 	// std::cout << e2a[(int) (sgy.TFileHead_[i])];
    //     printf("%i", sgy.BFileHead_.JOB_ID);
	// } 
    
    // printf("%i \n", sgy.BFileHead_.JOB_ID              );
    // printf("%i \n", sgy.BFileHead_.LINE_NUM    );
    // printf("%i \n", sgy.BFileHead_.REEL_NUM    );
    // printf("%hi \n", sgy.BFileHead_.NUM_OF_TRACE    );
    // printf("%hi \n", sgy.BFileHead_.NUM_OF_AUX  );
    printf("%hi \n", sgy.toLitteEnd(sgy.BFileHead_.INTERVAL_MS)     );
    printf("%hi \n", sgy.toLitteEnd(sgy.traceHeader_.TRACE_SEQ_GLOBAL)     );
    printf("%hi \n", sgy.toLitteEnd(sgy.traceHeader_.SCALE_COOR)     );
    // printf("%hi \n", sgy.BFileHead_.INTERVAL_MS_ORI     );
    // printf("%hi \n", sgy.BFileHead_.NUM_OF_SAMPLES  );
    // printf("%hi \n", sgy.BFileHead_.NUM_OF_SAMPLES_ORI  );
    // printf("%hi \n", sgy.BFileHead_.SAMPLE_FORMAT   );
    // printf("%hi \n", sgy.BFileHead_.ENSEMBLE    );
    // printf("%hi \n", sgy.BFileHead_.TRACE_SORT  );
    // printf("%hi \n", sgy.BFileHead_.VERT_SUM    );
    // printf("%hi \n", sgy.BFileHead_.SWEEP_FREQ_START    );
    // printf("%hi \n", sgy.BFileHead_.SWEEP_FREQ_END  );
    // printf("%hi \n", sgy.BFileHead_.SWEEP_LENGTH    );
    // printf("%hi \n", sgy.BFileHead_.SWEEP_TYPE  );
    // printf("%hi \n", sgy.BFileHead_.SWEEP_NUM_CHANNEL   );
    // printf("%hi \n", sgy.BFileHead_.SWEEP_TAPER_LEN_START   );
    // printf("%hi \n", sgy.BFileHead_.SWEEP_TAPER_LEN_END     );
    // printf("%hi \n", sgy.BFileHead_.TAPER_TYPE  );
    // printf("%hi \n", sgy.BFileHead_.CORRELATED  );
    // printf("%hi \n", sgy.BFileHead_.BINARY_GAIN     );
    // printf("%hi \n", sgy.BFileHead_.AMP_RECOR   );
    // printf("%hi \n", sgy.BFileHead_.MEASURE_SYSTEM  );
    // printf("%hi \n", sgy.BFileHead_.IMPULSE_POLAR   );
    // printf("%hi \n", sgy.BFileHead_.POLAR_CODE  );
    // printf("%hi \n", sgy.BFileHead_.SEGY_REV_NUM    );
    // printf("%hi \n", sgy.BFileHead_.FIXED_LEN   );
    // printf("%hi \n", sgy.BFileHead_.NUM_EXT_HEAD    );
    
}