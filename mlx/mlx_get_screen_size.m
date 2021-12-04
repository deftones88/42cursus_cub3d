

#import <Cocoa/Cocoa.h>
#import <OpenGL/gl3.h>
//#import <AppKit/NSOpenGLView.h>

#include "mlx.h"

int mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey)
{
    NSRect e = [[NSScreen mainScreen] frame];
    *sizex = (int)e.size.height;
    *sizey = (int)e.size.width;
    return (0);
}
