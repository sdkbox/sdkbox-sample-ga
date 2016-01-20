
local MainScene = class("MainScene", cc.load("mvc").ViewBase)

function MainScene:onCreate()
    print("Sample Startup")

    local label = cc.Label:createWithSystemFont("QUIT", "sans", 32)
    local quit = cc.MenuItemLabel:create(label)
    quit:onClicked(function()
        os.exit(0)
    end)
    local size = label:getContentSize()
    local menu = cc.Menu:create(quit)
    menu:setPosition(display.right - size.width / 2 - 16, display.bottom + size.height / 2 + 16)
    self:addChild(menu)

    self:setupTestMenu()
end

function MainScene:setupTestMenu()
    cc.MenuItemFont:setFontName("sans")
    local size = cc.Director:getInstance():getWinSize()

    sdkbox.PluginGoogleAnalytics:init()
    local menu = cc.Menu:create(
        cc.MenuItemFont:create("log event"):onClicked(function()
            sdkbox.PluginGoogleAnalytics:logEvent("Test", "Click", "", 1)
            sdkbox.PluginGoogleAnalytics:dispatchHits()
            print("sdkbox.PluginGoogleAnalytics:logEvent(\"Test\", \"Click\", \"\", 1);")
        end),

        cc.MenuItemFont:create("log exception"):onClicked(function()
            sdkbox.PluginGoogleAnalytics:logException("Test Exception", true);
            sdkbox.PluginGoogleAnalytics:dispatchHits();
            print("sdkbox.PluginGoogleAnalytics:logException(\"Test Exception\", true);");
        end),

        cc.MenuItemFont:create("log social"):onClicked(function()
            sdkbox.PluginGoogleAnalytics:logSocial("facebook", "share", "sdkbox");
            sdkbox.PluginGoogleAnalytics:dispatchHits();
            print("sdkbox.PluginGoogleAnalytics:logSocial(\"facebook\", \"share\", \"sdkbox\");");
        end))

    menu:alignItemsVerticallyWithPadding(5)
    menu:setPosition(size.width/2, size.height/2)
    self:addChild(menu)
end

return MainScene
