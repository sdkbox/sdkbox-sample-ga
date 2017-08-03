#ifndef __PluginGoogleAnalyticsJS_h__
#define __PluginGoogleAnalyticsJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginGoogleAnalyticsJS_PluginGoogleAnalytics(JSContext *cx, JS::HandleObject global);
void register_all_PluginGoogleAnalyticsJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginGoogleAnalyticsJS_PluginGoogleAnalytics(JSContext *cx, JSObject* global);
void register_all_PluginGoogleAnalyticsJS(JSContext* cx, JSObject* obj);
#endif
#endif

