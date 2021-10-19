/*
Name: QtRpt
Version: 1.5.2
Web-site: http://www.qtrpt.tk
Programmer: Aleksey Osipov
E-mail: aliks-os@ukr.net
Web-site: http://www.aliks-os.tk

Copyright 2012-2015 Aleksey Osipov

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#ifndef XMLVIEWMODEL_H
#define XMLVIEWMODEL_H

#include <QStandardItemModel>
#include <QDomDocument>

class XMLViewModel : public QStandardItemModel
{
    Q_OBJECT
public:
    XMLViewModel(QDomDocument *xmlDoc, QObject *parent = 0);

private:
    void insertChilds(QDomNode node, QStandardItem *parent);
};

#endif // XMLVIEWMODEL_H
