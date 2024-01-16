#define SIM_X_SIZE 256
#define SIM_Y_SIZE 256

extern void simSetPixel(long long int x, long long int y, long long int argb);
extern void simFlush();
extern long long int simRand();
extern long long int simAbs(long long int a);

extern void init();
