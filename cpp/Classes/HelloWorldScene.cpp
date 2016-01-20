
#include "HelloWorldScene.h"
#include "PluginGoogleAnalytics/PluginGoogleAnalytics.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    CCLOG("Sample Startup");

    // add logo
    auto winsize = Director::getInstance()->getWinSize();
    auto logo = Sprite::create("Logo.png");
    auto logoSize = logo->getContentSize();
    logo->setPosition(Vec2(logoSize.width / 2,
                           winsize.height - logoSize.height / 2));
    addChild(logo);

    // add quit button
    auto label = Label::createWithSystemFont("QUIT", "sans", 32);
    auto quit = MenuItemLabel::create(label, [](Ref*){
        exit(0);
    });
    auto labelSize = label->getContentSize();
    quit->setPosition(Vec2(winsize.width / 2 - labelSize.width / 2 - 16,
                           -winsize.height / 2 + labelSize.height / 2 + 16));
    addChild(Menu::create(quit, NULL));

    // add test menu
    createTestMenu();

    return true;
}

void HelloWorld::createTestMenu()
{
    MenuItemFont::setFontName("sans");
    Size size = Director::getInstance()->getWinSize();
    
    auto menu = Menu::create(MenuItemFont::create("log event", CC_CALLBACK_1(HelloWorld::onLogEvent, this)),
                             MenuItemFont::create("log exception", CC_CALLBACK_1(HelloWorld::onLogException, this)),
                             MenuItemFont::create("log social", CC_CALLBACK_1(HelloWorld::onLogSocial, this)),
                             NULL);
    
    menu->alignItemsVerticallyWithPadding(5);
    menu->setPosition(Vec2(size.width/2, size.height/2));
    addChild(menu);
}

void HelloWorld::onLogEvent(cocos2d::Ref* sender)
{
    sdkbox::PluginGoogleAnalytics::logEvent("Test", "Click", "", 1);
    sdkbox::PluginGoogleAnalytics::dispatchHits();
    CCLOG("sdkbox::PluginGoogleAnalytics::logEvent(\"Test\", \"Click\", \"\", 1);");
}

void HelloWorld::onLogException(cocos2d::Ref* sender)
{
    sdkbox::PluginGoogleAnalytics::logException("Test Exception", true);
    sdkbox::PluginGoogleAnalytics::dispatchHits();
    CCLOG("sdkbox::PluginGoogleAnalytics::logException(\"Test Exception\", true);");
}

void HelloWorld::onLogSocial(cocos2d::Ref* sender)
{
    sdkbox::PluginGoogleAnalytics::logSocial("facebook", "share", "sdkbox");
    sdkbox::PluginGoogleAnalytics::dispatchHits();
    CCLOG("sdkbox::PluginGoogleAnalytics::logSocial(\"facebook\", \"share\", \"sdkbox\");");
}
