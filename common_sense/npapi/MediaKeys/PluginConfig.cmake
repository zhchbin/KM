#/**********************************************************\ 
#
# Auto-Generated Plugin Configuration file
# for MediaKeys
#
#\**********************************************************/

set(PLUGIN_NAME "MediaKeys")
set(PLUGIN_PREFIX "MKE")
set(COMPANY_NAME "SYSU")

# ActiveX constants:
set(FBTYPELIB_NAME MediaKeysLib)
set(FBTYPELIB_DESC "MediaKeys 1.0 Type Library")
set(IFBControl_DESC "MediaKeys Control Interface")
set(FBControl_DESC "MediaKeys Control Class")
set(IFBComJavascriptObject_DESC "MediaKeys IComJavascriptObject Interface")
set(FBComJavascriptObject_DESC "MediaKeys ComJavascriptObject Class")
set(IFBComEventSource_DESC "MediaKeys IFBComEventSource Interface")
set(AXVERSION_NUM "1")

# NOTE: THESE GUIDS *MUST* BE UNIQUE TO YOUR PLUGIN/ACTIVEX CONTROL!  YES, ALL OF THEM!
set(FBTYPELIB_GUID e61a4eba-1ebf-57af-a5c5-da9f08b33d6f)
set(IFBControl_GUID 734f9756-706d-54e4-9fb9-75f58e7e6338)
set(FBControl_GUID 6399b426-d8e7-5e9b-8da6-5b4290895ff8)
set(IFBComJavascriptObject_GUID 22c8de15-b5b0-58d7-b2ec-deca952a0ff2)
set(FBComJavascriptObject_GUID 7efc09e7-cebc-5c32-80b9-862cca9de80f)
set(IFBComEventSource_GUID 0340adba-96e8-5c57-ab17-f9d615dcc918)
if ( FB_PLATFORM_ARCH_32 )
    set(FBControl_WixUpgradeCode_GUID eaa00082-d05a-5217-8cee-073fba273a3b)
else ( FB_PLATFORM_ARCH_32 )
    set(FBControl_WixUpgradeCode_GUID ba806c80-6917-5579-8b14-81e72fe2efd9)
endif ( FB_PLATFORM_ARCH_32 )

# these are the pieces that are relevant to using it from Javascript
set(ACTIVEX_PROGID "SYSU.MediaKeys")
set(MOZILLA_PLUGINID "zhchbin.github.io/MediaKeys")

# strings
set(FBSTRING_CompanyName "SYSU")
set(FBSTRING_PluginDescription "Grab media keys.")
set(FBSTRING_PLUGIN_VERSION "1.0.0.0")
set(FBSTRING_LegalCopyright "Copyright 2013 SYSU")
set(FBSTRING_PluginFileName "np${PLUGIN_NAME}.dll")
set(FBSTRING_ProductName "MediaKeys")
set(FBSTRING_FileExtents "")
if ( FB_PLATFORM_ARCH_32 )
    set(FBSTRING_PluginName "MediaKeys")  # No 32bit postfix to maintain backward compatability.
else ( FB_PLATFORM_ARCH_32 )
    set(FBSTRING_PluginName "MediaKeys_${FB_PLATFORM_ARCH_NAME}")
endif ( FB_PLATFORM_ARCH_32 )
set(FBSTRING_MIMEType "application/x-mediakeys")

# Uncomment this next line if you're not planning on your plugin doing
# any drawing:

#set (FB_GUI_DISABLED 1)

# Mac plugin settings. If your plugin does not draw, set these all to 0
set(FBMAC_USE_QUICKDRAW 0)
set(FBMAC_USE_CARBON 1)
set(FBMAC_USE_COCOA 1)
set(FBMAC_USE_COREGRAPHICS 1)
set(FBMAC_USE_COREANIMATION 0)
set(FBMAC_USE_INVALIDATINGCOREANIMATION 0)

# If you want to register per-machine on Windows, uncomment this line
#set (FB_ATLREG_MACHINEWIDE 1)
