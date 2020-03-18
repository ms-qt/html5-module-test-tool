//
// Created by 毛华伟 on 2020/3/17.
//

#include "WebDataComponent.h"

namespace bdlbsc
{

    WebDataComponent::WebDataComponent() {}

    WebDataComponent::~WebDataComponent() {}

    QString WebDataComponent::get_app_access_token()
    {
        qDebug() << "bdlbsc::WebDataComponent::get_app_access_token";
        return "bdlbsc::test::app_access_token";
        //return _app_access_token;
    }

    QString WebDataComponent::get_user_access_token()
    {
        return "bdlbsc::test::user_access_token";
        //return _user_access_token;
    }

    QString WebDataComponent::get_user_id()
    {
        return _user_id;
    }

    void WebDataComponent::send_app_access_token(QString values)
    {

        emit app_access_token_change(values);
    }

    void WebDataComponent::send_user_access_token(QString values)
    {

        emit user_access_token_change(values);
    }

    void WebDataComponent::send_user_id(QString values)
    {

        emit user_id_change(values);
    }

} // namespace bdlbsc