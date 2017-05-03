
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
        end),

        cc.MenuItemFont:create("log ecommerce"):onClicked(function()
            local ecommerceInfo = {
                -- transaction info
                action = 'purchase',
                transaction = 'T12345',
                affiliation = 'Google Store - Online',
                transactionCouponCode = 'SUMMER2017',
                revenue = '37.39',
                tax = '2.85',
                shipping = '5.34',

                -- product info
                productID = 'P12345',
                productName = 'Android Warhol T-Shirt',
                category = 'Apparel/T-Shirts',
                brand = 'SDKBox',
                productVariant = 'black',
                productCouponCode = 'APPARELSALE',
                price = '29.20',
                quantity = '1',

                -- currency code
                -- https://support.google.com/analytics/answer/6205902?#supported-currencies
                currencyCode = 'EUR'
            }

            sdkbox.PluginGoogleAnalytics:logECommerce(ecommerceInfo)
            sdkbox.PluginGoogleAnalytics:dispatchHits()
            print("sdkbox.PluginGoogleAnalytics:logECommerce")
            dump(ecommerceInfo, "ecommerceInfo:")
        end))

    menu:alignItemsVerticallyWithPadding(5)
    menu:setPosition(size.width/2, size.height/2)
    self:addChild(menu)
end

return MainScene
