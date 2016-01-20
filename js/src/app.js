
var HelloWorldLayer = cc.Layer.extend({
    sprite:null,
    ctor:function () {
        //////////////////////////////
        // 1. super init first
        this._super();

        cc.log("Sample Startup")

        this.createTestMenu();

        var winsize = cc.winSize;

        var logo = new cc.Sprite("res/Logo.png");
        var logoSize = logo.getContentSize();
        logo.x = logoSize.width / 2;
        logo.y = winsize.height - logoSize.height / 2;
        this.addChild(logo);

        var quit = new cc.MenuItemLabel(new cc.LabelTTF("QUIT", "sans", 32), function() {
            cc.log("QUIT");
        });
        var menu = new cc.Menu(quit);
        var size = quit.getContentSize();
        menu.x = winsize.width - size.width / 2 - 16;
        menu.y = size.height / 2 + 16;
        this.addChild(menu);

        return true;
    },

    createTestMenu:function() {
        cc.MenuItemFont.setFontName("sans");
        var size = cc.Director.getInstance().getWinSize();

        sdkbox.PluginGoogleAnalytics.init();
        var menu = new cc.Menu(
            new cc.MenuItemFont("log event", function() {
                sdkbox.PluginGoogleAnalytics.logEvent("Test", "Click", "", 1);
                sdkbox.PluginGoogleAnalytics.dispatchHits();
                cc.log("sdkbox.PluginGoogleAnalytics.logEvent(\"Test\", \"Click\", \"\", 1);");
            }),

            new cc.MenuItemFont("log exception", function() {
                sdkbox.PluginGoogleAnalytics.logException("Test Exception", true);
                sdkbox.PluginGoogleAnalytics.dispatchHits();
                cc.log("sdkbox.PluginGoogleAnalytics.logException(\"Test Exception\", true);");
            }),

            new cc.MenuItemFont("log social", function() {
                sdkbox.PluginGoogleAnalytics.logSocial("facebook", "share", "sdkbox");
                sdkbox.PluginGoogleAnalytics.dispatchHits();
                cc.log("sdkbox.PluginGoogleAnalytics.logSocial(\"facebook\", \"share\", \"sdkbox\");");
            }));

        menu.alignItemsVerticallyWithPadding(5);
        menu.x = size.width/2;
        menu.y = size.height/2;
        this.addChild(menu);
    }
});

var HelloWorldScene = cc.Scene.extend({
    onEnter:function () {
        this._super();
        var layer = new HelloWorldLayer();
        this.addChild(layer);
    }
});

