/**********************************************************\

  Auto-generated MediaKeysAPI.h

\**********************************************************/

#include <string>
#include <sstream>
#include <boost/weak_ptr.hpp>
#include "JSAPIAuto.h"
#include "BrowserHost.h"
#include "MediaKeys.h"

#ifndef H_MediaKeysAPI
#define H_MediaKeysAPI

class MediaKeysAPI : public FB::JSAPIAuto
{
public:
    ////////////////////////////////////////////////////////////////////////////
    /// @fn MediaKeysAPI::MediaKeysAPI(const MediaKeysPtr& plugin, const FB::BrowserHostPtr host)
    ///
    /// @brief  Constructor for your JSAPI object.
    ///         You should register your methods, properties, and events
    ///         that should be accessible to Javascript from here.
    ///
    /// @see FB::JSAPIAuto::registerMethod
    /// @see FB::JSAPIAuto::registerProperty
    /// @see FB::JSAPIAuto::registerEvent
    ////////////////////////////////////////////////////////////////////////////
    MediaKeysAPI(const MediaKeysPtr& plugin, const FB::BrowserHostPtr& host) :
        m_plugin(plugin), m_host(host)
    {}

    ///////////////////////////////////////////////////////////////////////////////
    /// @fn MediaKeysAPI::~MediaKeysAPI()
    ///
    /// @brief  Destructor.  Remember that this object will not be released until
    ///         the browser is done with it; this will almost definitely be after
    ///         the plugin is released.
    ///////////////////////////////////////////////////////////////////////////////
    virtual ~MediaKeysAPI() {};

    MediaKeysPtr getPlugin();
    
    // Event helpers
    FB_JSAPI_EVENT(onMediaKeys, 1, (const int));

    // Method test-event
    FB::variant OnMediaKeys(int vkCode);

private:
    MediaKeysWeakPtr m_plugin;
    FB::BrowserHostPtr m_host;

    std::string m_testString;
};

#endif // H_MediaKeysAPI

