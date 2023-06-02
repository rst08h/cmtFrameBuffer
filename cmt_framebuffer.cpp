#include "cmt_framebuffer.h"
#include <stdlib.h>
#include <stdio.h>
#include "cmt_screen.hpp"

cmtFrameBuffer::cmtFrameBuffer(int width, int hight)
{
	buff.px = (pixel_t *)malloc(sizeof(pixel_t) * width * hight);
	buff.width=width;
	buff.hight=hight;
}

pixel_t cmtFrameBuffer::getPixel(int x, int y)
{
	return *(buff.px + (y * sizeof(pixel_t)) + x);
}

int cmtFrameBuffer::refresh()
{
	return 0;
}
int cmtFrameBuffer::crop(range_t range, pixel_t *buff)
{
	int size = 0;
	if ((range.x1 < range.x2) && (range.y1 < range.y2))
	{
		for (int i = range.y1; i < range.y2; i++)
		{
			for (int j = range.x1; j < range.x1; j++)
			{
				*(buff + size) = getPixel(j, i);
				size++;
			}
		}
	}
	return size;
}

canvas_t cmtFrameBuffer::crop(range_t range)
{
	canvas_t buff;
	buff.width=range.x2-range.x1;
	buff.hight=range.y2-range.y1;
	buff.px =(pixel*) malloc(buff.width*buff.hight);

	int size=0;
	if ((range.x1 < range.x2) && (range.y1 < range.y2))
	{
		for (int i = range.y1; i < range.y2; i++)
		{
			for (int j = range.x1; j < range.x1; j++)
			{
				*(buff.px + size) = getPixel(j, i);
				size++;
			}
		}
	}
	return buff;
}
