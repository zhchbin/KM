/**********************************************************\

  Auto-generated MediaKeysAPI.cpp

\**********************************************************/

#include "JSObject.h"
#include "variant_list.h"
#include "DOM/Document.h"
#include "global/config.h"

#include "MediaKeysAPI.h"

FB::variant MediaKeysAPI::OnMediaKeys(const int vk_code)
{
    fire_onMediaKeys(vk_code);
    return FB::variant(vk_code);
}

///////////////////////////////////////////////////////////////////////////////
/// @fn MediaKeysPtr MediaKeysAPI::getPlugin()
///
/// @brief  Gets a reference to the plugin that was passed in when the object
///         was created.  If the plugin has already been released then this
///         will throw a FB::script_error that will be translated into a
///         javascript exception in the page.
///////////////////////////////////////////////////////////////////////////////
MediaKeysPtr MediaKeysAPI::getPlugin()
{
    MediaKeysPtr plugin(m_plugin.lock());
    if (!plugin) {
        throw FB::script_error("The plugin is invalid");
    }
    return plugin;
}