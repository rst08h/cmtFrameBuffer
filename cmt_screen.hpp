//
//  cmt_screen.hpp
//  cmt_display
//
//  Created by เอกพจน์ ศักดิ์เรืองฤทธิ์ on 25/5/2566 BE.
//

#ifndef cmt_screen_hpp
#define cmt_screen_hpp

#include <stdio.h>
#include "cmt_framebuffer.h"

class cmtScreen{
public:
    int group_col; // จำนวน column ก่อนขึ้นแถวใหม่ในแผง
    cmtScreen(range_t dimention,int group_col);
private:
    range_t dimention;
    
    
};

#endif /* cmt_screen_hpp */
