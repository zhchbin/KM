/**********************************************************\

  Auto-generated MediaKeys.h

  This file contains the auto-generated main plugin object
  implementation for the MediaKeys project

\**********************************************************/
#ifndef H_MediaKeysPLUGIN
#define H_MediaKeysPLUGIN

#include "PluginWindow.h"
#include "PluginEvents/MouseEvents.h"
#include "PluginEvents/AttachedEvent.h"

#include <Windows.h>

#include "PluginCore.h"

class MediaKeysAPI;

// A macro to disallow the copy constructor and operator= functions
// This should be used in the private: declarations for a class
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&);               \
  void operator=(const TypeName&)

class MediaKeysWatcher {
 public:
  explicit MediaKeysWatcher(boost::shared_ptr<MediaKeysAPI> media_keys_api);
  ~MediaKeysWatcher();

 private:
  // Instance that owns the hook. We only allow one instance to hook the mouse
  // at a time.
  static MediaKeysWatcher* instance_;

  // Key callbacks from the hook.
  static LRESULT CALLBACK KeyHook(int n_code, WPARAM w_param, LPARAM l_param);

  void Unhook();

  boost::shared_ptr<MediaKeysAPI> media_keys_api_;
  HHOOK key_hook_;

  DISALLOW_COPY_AND_ASSIGN(MediaKeysWatcher);
};

FB_FORWARD_PTR(MediaKeys)
class MediaKeys : public FB::PluginCore
{
public:
    static void StaticInitialize();
    static void StaticDeinitialize();

public:
    MediaKeys();
    virtual ~MediaKeys();

public:
    void onPluginReady();
    void shutdown();
    virtual FB::JSAPIPtr createJSAPI();
    // If you want your plugin to always be windowless, set this to true
    // If you want your plugin to be optionally windowless based on the
    // value of the "windowless" param tag, remove this method or return
    // FB::PluginCore::isWindowless()
    virtual bool isWindowless() { return true; }

    BEGIN_PLUGIN_EVENT_MAP()
        EVENTTYPE_CASE(FB::MouseDownEvent, onMouseDown, FB::PluginWindow)
        EVENTTYPE_CASE(FB::MouseUpEvent, onMouseUp, FB::PluginWindow)
        EVENTTYPE_CASE(FB::MouseMoveEvent, onMouseMove, FB::PluginWindow)
        EVENTTYPE_CASE(FB::MouseMoveEvent, onMouseMove, FB::PluginWindow)
        EVENTTYPE_CASE(FB::AttachedEvent, onWindowAttached, FB::PluginWindow)
        EVENTTYPE_CASE(FB::DetachedEvent, onWindowDetached, FB::PluginWindow)
    END_PLUGIN_EVENT_MAP()

    /** BEGIN EVENTDEF -- DON'T CHANGE THIS LINE **/
    virtual bool onMouseDown(FB::MouseDownEvent *evt, FB::PluginWindow *);
    virtual bool onMouseUp(FB::MouseUpEvent *evt, FB::PluginWindow *);
    virtual bool onMouseMove(FB::MouseMoveEvent *evt, FB::PluginWindow *);
    virtual bool onWindowAttached(FB::AttachedEvent *evt, FB::PluginWindow *);
    virtual bool onWindowDetached(FB::DetachedEvent *evt, FB::PluginWindow *);
    /** END EVENTDEF -- DON'T CHANGE THIS LINE **/

private:
  boost::shared_ptr<MediaKeysAPI> media_keys_api_;
  boost::scoped_ptr<MediaKeysWatcher> media_keys_watcher_;
};


#endif

