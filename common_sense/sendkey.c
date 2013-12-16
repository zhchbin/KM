// Build: g++ sendkey.c -lX11 -lXtst -o sendkey

#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/extensions/XTest.h>
#include <X11/XF86keysym.h>

int keysyms[] =  {
  XF86XK_AudioPlay,  /* Start playing of audio >   */
  XF86XK_AudioStop,  /* Stop playing audio         */
  XF86XK_AudioPrev,  /* Previous track             */
  XF86XK_AudioNext,  /* Next Track                 */
};

int main(int argc, char *argv[]) {
  Display* display = XOpenDisplay(NULL);
  for (int i = 0; i < sizeof(keysyms) / sizeof(keysyms[0]); ++i) {
    int keycode = XKeysymToKeycode(display, keysyms[i]);
    XTestFakeKeyEvent(display, keycode, True, 0);
    XTestFakeKeyEvent(display, keycode, False, 0);
    XFlush(display);
  }

  return 0;
}
