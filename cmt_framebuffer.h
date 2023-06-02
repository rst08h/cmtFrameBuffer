#ifndef cmt_framebuffer_h
#define cmt_framebuffer_h
#include "cmt_screen.hpp"

#define MAX_SCREEN  8

struct pixel
{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

struct range
{
    unsigned short x1;
    unsigned short x2;
    unsigned short y1;
    unsigned short y2;
};



typedef struct range range_t;
typedef struct pixel pixel_t;

struct canvas
{
    int width; // ความกว้าง
    int hight; // ความสูง
    pixel_t *px; // pixel
};

typedef struct canvas canvas_t;

class cmtFrameBuffer
{
public:
    canvas_t buff;
    cmtScreen *screen[MAX_SCREEN];
    cmtFrameBuffer(int width, int hight);
    struct pixel getPixel(int x, int y);
    int refresh();

private:

    int crop(range_t range,pixel_t *buff);
    canvas_t crop(range_t range);
};

#endif
