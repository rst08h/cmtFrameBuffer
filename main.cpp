//
//  main.cpp
//  cmt_display
//
//  Created by เอกพจน์ ศักดิ์เรืองฤทธิ์ on 24/5/2566 BE.
//

#include <iostream>
#include "cmt_framebuffer.h"
#include  <stdio.h>


int main(int argc, const char * argv[]) {
    // insert code here...
    struct pixel p;
    std::cout << "Hello, World!\n";
    cmtFrameBuffer *fb = new cmtFrameBuffer(32,32);
    p=fb->getPixel(0,0);
    printf("%d %d %d\n",p.red,p.green,p.blue);
    return 0;
}
