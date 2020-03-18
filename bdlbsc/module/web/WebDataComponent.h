//
// Created by 毛华伟 on 2020/3/17.
//

#ifndef APP_WEBDATACOMPONENT_H
#define APP_WEBDATACOMPONENT_H

#include <QObject>
#include <QDebug>

namespace bdlbsc
{

    class WebDataComponent : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QString app_access_token READ get_app_access_token NOTIFY app_access_token_change)
        Q_PROPERTY(QString user_access_token READ get_user_access_token NOTIFY user_access_token_change)
        Q_PROPERTY(QString user_id READ get_user_id NOTIFY user_id_change)
    public:
        WebDataComponent();
        ~WebDataComponent();

        QString get_app_access_token();
        QString get_user_access_token();
        QString get_user_id();

        Q_INVOKABLE void send_app_access_token(QString values);
        Q_INVOKABLE void send_user_access_token(QString values);
        Q_INVOKABLE void send_user_id(QString values);

    signals:
        void app_access_token_change(QString value);
        void user_access_token_change(QString value);
        void user_id_change(QString value);

    private:
        QString _app_access_token;
        QString _user_access_token;
        QString _user_id;
    };
} // namespace bdlbsc

#endif //APP_WEBDATACOMPONENT_H
