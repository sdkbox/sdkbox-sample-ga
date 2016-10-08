/****************************************************************************

 Copyright (c) 2014-2016 SDKBOX Inc

 ****************************************************************************/
#ifndef __PLUGIN_GA_WRAPPER__
#define __PLUGIN_GA_WRAPPER__

#include <string>
#include <vector>
#include "CocosMacros.h"

namespace sdkbox {

#define TAG        "GoogleAnalytics"
#define VERSION    "3.12"
#define IOS_VERSION     "ios: 3.12"
#define ANDROID_VERSION "android: none"

    class GoogleAnalyticsWrapper {
    public:
        static GoogleAnalyticsWrapper* getInstance();

        virtual void init(const char* jsonconfig) = 0;
        virtual void startSession() = 0;
        virtual void stopSession() = 0;
        virtual void dispatchHits() = 0;
        virtual void dispatchPeriodically( int seconds ) = 0;
        virtual void stopPeriodicalDispatch() = 0;
        virtual void setUser(const std::string& userID) = 0;
        virtual void setDimension(int index, const std::string& value) = 0;
        virtual void setMetric(int index, const std::string& value) = 0;
        virtual void logScreen(const std::string& title) = 0;
        virtual void logEvent(const std::string& eventCategory, const std::string& eventAction, const std::string& eventLabel, int value) = 0;
        virtual void logException(const std::string& exceptionDescription, bool isFatal) = 0;
        virtual void logTiming(const std::string& timingCategory, int timingInterval, const std::string& timingName, const std::string& timingLabel) = 0;
        virtual void logSocial(const std::string& socialNetwork, const std::string& socialAction, const std::string& socialTarget) = 0;
        virtual void setDryRun( bool dr ) = 0;
        virtual void enableAdvertisingTracking( bool e ) = 0;
        virtual void createTracker( const std::string& trackerId ) = 0;
        virtual void enableTracker( const std::string& trackerId ) = 0;
    };

    class GoogleAnalyticsWrapperEnabled : public GoogleAnalyticsWrapper {
    public:
        GoogleAnalyticsWrapperEnabled();
        ~GoogleAnalyticsWrapperEnabled();
        void init(const char* jsonconfig);
        void startSession();
        void stopSession();
        void dispatchHits();
        void dispatchPeriodically( int seconds );
        void stopPeriodicalDispatch();
        void setUser(const std::string& userID);
        void setDimension(int index, const std::string& value);
        void setMetric(int index, const std::string& value);
        void logScreen(const std::string& title);
        void logEvent(const std::string& eventCategory, const std::string& eventAction, const std::string& eventLabel, int value);
        void logException(const std::string& exceptionDescription, bool isFatal);
        void logTiming(const std::string& timingCategory, int timingInterval, const std::string& timingName, const std::string& timingLabel);
        void logSocial(const std::string& socialNetwork, const std::string& socialAction, const std::string& socialTarget);
        void setDryRun( bool dr );
        void enableAdvertisingTracking( bool e );
        void createTracker( const std::string& trackerId );
        void enableTracker( const std::string& trackerId );

    protected:
        bool nativeInit(const std::string& trackerId);
        const char* nativeSDKVersion();
        bool _initialized;
        bool _trackingInitializationScreen;
    };

    class GoogleAnalyticsWrapperDisabled : public GoogleAnalyticsWrapper {
    public:
        void init(const char* jsonconfig) {}
        void startSession() {}
        void stopSession() {}
        void dispatchHits() {}
        void dispatchPeriodically( int seconds ) {}
        void stopPeriodicalDispatch() {}
        void setUser(const std::string& userID) {}
        void setDimension(int index, const std::string& value) {}
        void setMetric(int index, const std::string& value) {}
        void logScreen(const std::string& title) {}
        void logEvent(const std::string& eventCategory, const std::string& eventAction, const std::string& eventLabel, int value) {}
        void logException(const std::string& exceptionDescription, bool isFatal) {}
        void logTiming(const std::string& timingCategory, int timingInterval, const std::string& timingName, const std::string& timingLabel) {}
        void logSocial(const std::string& socialNetwork, const std::string& socialAction, const std::string& socialTarget) {}
        void setDryRun( bool dr ) {}
        void enableAdvertisingTracking( bool e ) {}
        void createTracker( const std::string& trackerId ) {}
        void enableTracker( const std::string& trackerId ) {}
    };


}

#endif
