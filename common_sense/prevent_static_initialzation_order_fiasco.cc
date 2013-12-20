// Use the "construct on first use" idiom, which simply means to wrap your
// static object inside a function. An real-world example that coming from my
// change list (Refactor GlobalShortcutListener of Chromium), is suitable for
// elaborate on this problem.

GlobalShortcutListener* GlobalShortcutListener::GetInstance() {
  CHECK(BrowserThread::CurrentlyOn(BrowserThread::UI));
  static GlobalShortcutListenerX11 *instance =
      new GlobalShortcutListenerX11();
  return instance;
}

// You may be curious about how to delete the instance. The answer is we never
// delete it since the desctructor of GlobalShortcutListener and its subclass do
// nothing serious. Isn't this a memory leak? Mark told me that: A leak is only
// considered to occur when a pointer is lost without deallocating what it
// pointed to.
//
// Reference: https://codereview.chromium.org/109413003/diff/140001/chrome/browser/extensions/global_shortcut_listener_win.cc 
//            http://www.parashift.com/c++-faq-lite/static-init-order-on-first-use.html
//            http://www.parashift.com/c++-faq-lite/static-init-order.html
