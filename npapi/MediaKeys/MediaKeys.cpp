/**********************************************************\

  Auto-generated MediaKeys.cpp

  This file contains the auto-generated main plugin object
  implementation for the MediaKeys project

\**********************************************************/

#include "MediaKeys.h"

#include "MediaKeysAPI.h"

// static 
MediaKeysWatcher* MediaKeysWatcher::instance_ = NULL;

MediaKeysWatcher::MediaKeysWatcher(boost::shared_ptr<MediaKeysAPI> media_keys_api)
    : media_keys_api_(media_keys_api),
      key_hook_(NULL) {
  // Only one instance can be active at a time.
  if (instance_)
    instance_->Unhook();

  key_hook_ = SetWindowsHookEx(WH_KEYBOARD_LL, &KeyHook, NULL, 0L);

  if (key_hook_)
    instance_ = this;
}

MediaKeysWatcher::~MediaKeysWatcher() {
  Unhook();
}

// static
LRESULT CALLBACK MediaKeysWatcher::KeyHook(int n_code,
                                            WPARAM w_param,
                                            LPARAM l_param) {
  if (w_param == WM_KEYDOWN) {
    int vkCode = ((KBDLLHOOKSTRUCT*)l_param)->vkCode;
    if (vkCode >= VK_VOLUME_MUTE && vkCode <= VK_MEDIA_PLAY_PAUSE) {
      instance_->media_keys_api_->OnMediaKeys(vkCode);
    } 
  }

  return CallNextHookEx(instance_->key_hook_, n_code, w_param, l_param);
}

void MediaKeysWatcher::Unhook() {
  if (instance_ != this)
    return;

  UnhookWindowsHookEx(key_hook_);
  key_hook_ = NULL;
  instance_ = NULL;
}

///////////////////////////////////////////////////////////////////////////////
/// @fn MediaKeys::StaticInitialize()
///
/// @brief  Called from PluginFactory::globalPluginInitialize()
///
/// @see FB::FactoryBase::globalPluginInitialize
///////////////////////////////////////////////////////////////////////////////
void MediaKeys::StaticInitialize()
{
    // Place one-time initialization stuff here; As of FireBreath 1.4 this should only
    // be called once per process
}

///////////////////////////////////////////////////////////////////////////////
/// @fn MediaKeys::StaticInitialize()
///
/// @brief  Called from PluginFactory::globalPluginDeinitialize()
///
/// @see FB::FactoryBase::globalPluginDeinitialize
///////////////////////////////////////////////////////////////////////////////
void MediaKeys::StaticDeinitialize()
{
    // Place one-time deinitialization stuff here. As of FireBreath 1.4 this should
    // always be called just before the plugin library is unloaded
}

///////////////////////////////////////////////////////////////////////////////
/// @brief  MediaKeys constructor.  Note that your API is not available
///         at this point, nor the window.  For best results wait to use
///         the JSAPI object until the onPluginReady method is called
///////////////////////////////////////////////////////////////////////////////
MediaKeys::MediaKeys()
{
}

///////////////////////////////////////////////////////////////////////////////
/// @brief  MediaKeys destructor.
///////////////////////////////////////////////////////////////////////////////
MediaKeys::~MediaKeys()
{
    // This is optional, but if you reset m_api (the shared_ptr to your JSAPI
    // root object) and tell the host to free the retained JSAPI objects then
    // unless you are holding another shared_ptr reference to your JSAPI object
    // they will be released here.
    releaseRootJSAPI();
    m_host->freeRetainedObjects();
}

void MediaKeys::onPluginReady()
{
  media_keys_watcher_.reset(new MediaKeysWatcher(media_keys_api_));
}

void MediaKeys::shutdown()
{
    // This will be called when it is time for the plugin to shut down;
    // any threads or anything else that may hold a shared_ptr to this
    // object should be released here so that this object can be safely
    // destroyed. This is the last point that shared_from_this and weak_ptr
    // references to this object will be valid
}

///////////////////////////////////////////////////////////////////////////////
/// @brief  Creates an instance of the JSAPI object that provides your main
///         Javascript interface.
///
/// Note that m_host is your BrowserHost and shared_ptr returns a
/// FB::PluginCorePtr, which can be used to provide a
/// boost::weak_ptr<MediaKeys> for your JSAPI class.
///
/// Be very careful where you hold a shared_ptr to your plugin class from,
/// as it could prevent your plugin class from getting destroyed properly.
///////////////////////////////////////////////////////////////////////////////
FB::JSAPIPtr MediaKeys::createJSAPI()
{
  media_keys_api_ = boost::make_shared<MediaKeysAPI>(
      FB::ptr_cast<MediaKeys>(shared_from_this()),
      m_host);

  return media_keys_api_;
}

bool MediaKeys::onMouseDown(FB::MouseDownEvent *evt, FB::PluginWindow *)
{
    return false;
}

bool MediaKeys::onMouseUp(FB::MouseUpEvent *evt, FB::PluginWindow *)
{
    return false;
}

bool MediaKeys::onMouseMove(FB::MouseMoveEvent *evt, FB::PluginWindow *)
{
    return false;
}
bool MediaKeys::onWindowAttached(FB::AttachedEvent *evt, FB::PluginWindow *)
{
    return false;
}

bool MediaKeys::onWindowDetached(FB::DetachedEvent *evt, FB::PluginWindow *)
{
    return false;
}

