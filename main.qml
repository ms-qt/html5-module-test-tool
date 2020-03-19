import QtQuick 2.0
import QtQuick.Window 2.0
import QtWebEngine 1.7
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11
import QtWebChannel 1.0

import WebDataComponent 1.0

Window {
    visible: true
    width: 880
    height: 660
    title: qsTr("Html 插件模块测试工具")


    TextField{
        id:_TextField
        width: parent.width
        text: "http://localhost:3000"
        height: 30
    }

    Button{
        anchors.top: _TextField.bottom
        id:_Button
        text: "打开"
        onClicked: {
            _WebEngineView.url=   _TextField.text
        }
    }



    WebEngineView {
        id: _WebEngineView

        url:"file:///Users/maohuawei/src/qt/module-js-example/index.html"
        // anchors.fill: parent

        anchors.top: _Button.bottom
        
        width: parent.width
        height: parent.height

        settings.pluginsEnabled: true
        settings.screenCaptureEnabled: true
        settings.allowRunningInsecureContent: true

        settings.javascriptEnabled: true
        webChannel: _WebChannel

        onJavaScriptConsoleMessage: {
            console.log(message)
        }
        onLoadProgressChanged:
        {

        }

        onSmoothChanged: {

        }


        onCertificateError: {
            console.log(error)
        }

        onFeaturePermissionRequested: {
            if(feature  == WebEngineView.MediaAudioCapture
                    || feature == WebEngineView.MediaAudioVideoCapture
                    || feature ==  WebEngineView.MediaVideoCapture){

                grantFeaturePermission(securityOrigin,feature,true)

            } else{
                grantFeaturePermission(securityOrigin,feature,false)

            }
        }
        onUrlChanged: {
            console.log("url : "+url)
        }



    }
    WebChannel {
        id: _WebChannel
        registeredObjects: [_WebDataComponent]
    }
    WebDataComponent{
        id:_WebDataComponent
        WebChannel.id:"bdlbscWebDataComponent"
    }
}
