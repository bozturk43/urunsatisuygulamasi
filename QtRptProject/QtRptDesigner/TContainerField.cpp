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

#include "TContainerField.h"
#include "mainwindow.h"

TContainerField::TContainerField(QWidget *parent, QPoint p, QWidget *cWidget) : RptContainer(parent,p,cWidget) {
    m_label = new QLabel(tr("New Label"), this);
    m_label->setVisible(true);
    m_label->setObjectName("lbl");
    m_label->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    QString stl = "QLabel#lbl {;"
                  "border-width:1px;"
                  "border-style:solid;"
                  "border-color:rgba(0,0,0,255);"
                  "border-top-color:rgba(0,0,0,255);"
                  "border-left-color:rgba(0,0,0,255);"
                  "border-right-color:rgba(0,0,0,255);"
                  "border-bottom-color:rgba(0,0,0,255);"
                  "color:rgba(0,0,0,255);"
                  "background-color:rgba(255,255,255,0);"
            "}";
    this->setStyleSheet(stl);
    this->setChildWidget(m_label);
    this->resize(m_label->width()+40,m_label->height());
    this->setBaseSize(width(),height());
    m_label->releaseMouse();
    m_highlighting = "";
    m_formatString = "";
    m_xmlDoc = 0;
    m_barcode = 0;
    m_autoHeight = false;
    radius = 6;
    m_textWrap = true;

    if (QApplication::layoutDirection() == Qt::RightToLeft) {
        m_textDirection = true;
        m_label->setAlignment(Qt::AlignRight);
    } else {
        m_textDirection = false;
        m_label->setAlignment(Qt::AlignLeft);
    }
}

void TContainerField::setTextWrap(bool value) {
    m_textWrap = value;
    m_label->setWordWrap(value);
}

void TContainerField::setMenu(QMenu *menu_) {
    QIcon icon;
    QAction *actContEdit = new QAction(tr("Edit"),this);
    actContEdit->setObjectName("actContEdit");
    QObject::connect(actContEdit, SIGNAL(triggered()), this, SLOT(edit()));

    QAction *actContDel = new QAction(tr("Delete"),this);
    icon.addPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/delete.png")), QIcon::Normal, QIcon::On);
    actContDel->setObjectName("actContDel");
    actContDel->setIcon(icon);
    QObject::connect(actContDel, SIGNAL(triggered()), this, SIGNAL(deleteByUser()));
    QObject::connect(actContDel, SIGNAL(triggered()), this, SLOT(deleteLater()));

    QAction *actContMoveForward = new QAction(tr("Move forward"),this);
    actContMoveForward->setObjectName("actContMoveForward");
    icon.addPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/moveForward.png")), QIcon::Normal, QIcon::On);
    actContMoveForward->setIcon(icon);
    QObject::connect(actContMoveForward, SIGNAL(triggered()), this, SLOT(moveForward()));

    QAction *actContMoveBack = new QAction(tr("Move back"),this);
    actContMoveBack->setObjectName("actContMoveBack");
    icon.addPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/moveBack.png")), QIcon::Normal, QIcon::On);
    actContMoveBack->setIcon(icon);
    QObject::connect(actContMoveBack, SIGNAL(triggered()), this, SLOT(moveBack()));

    menu->clear();
    menu->insertActions(0,menu_->actions());
    menu->addAction(actContEdit);
    menu->addAction(actContDel);
    menu->addSeparator();
    menu->addAction(actContMoveForward);
    menu->addAction(actContMoveBack);
}

void TContainerField::moveForward() {
    this->raise();
}

void TContainerField::moveBack() {
    this->lower();
}

TContainerField *TContainerField::clone() {    
    QPoint newPos(this->x(),this->y());
    newPos.setY(newPos.y()+5);
    newPos.setX(newPos.x()+5);

    TContainerField *newContField  = new TContainerField(this->parentWidget(),QPoint(0,0),0);
    newContField->setType(this->getType(),m_xmlDoc);
    newContField->setStyleSheet(this->styleSheet());
    newContField->setText(m_label->text());
    newContField->m_label->setFont(m_label->font());
    newContField->m_label->setAlignment(m_label->alignment());
    newContField->setFontSize(this->getFontSize());
    newContField->setGeometry(this->geometry());
    newContField->setBaseSize(this->baseSize());    
    newContField->m_formatString = this->m_formatString;
    newContField->m_textWrap = this->m_textWrap;
    if (newContField->getType() == Image) {
        newContField->setImgFromat(this->getImgFormat());
        newContField->setIgnoreAspectRatio(this->getIgnoreAspectRatio());
        newContField->setImage(this->getImage());
    }
    if (newContField->getType() == Barcode) {
        newContField->setBarcodeType(this->getBarcodeType());
        newContField->setBarcodeFrameType(this->getBarcodeFrameType());
    }
    newContField->setVisible(true);
    newContField->move(newPos);
    return newContField;
}

void TContainerField::setText(QString text) {
    m_label->setText(text);
}

QString TContainerField::getText() {
    return m_label->text();
}

void TContainerField::setImage(QPixmap p) {
    m_pixmap = p;
    if (m_ignoreAspectRatio) {
        m_label->setPixmap(p);
    }else {
        m_label->setPixmap(p.scaled(m_label->width(),m_label->height(),Qt::KeepAspectRatio));
    }
}

QPixmap TContainerField::getImage() {
    return m_pixmap;
}

void TContainerField::setIgnoreAspectRatio(bool value) {
    m_label->setScaledContents(value);
    m_ignoreAspectRatio = value;
    resizeEvent(0);
}

bool TContainerField::getIgnoreAspectRatio() {
    return m_ignoreAspectRatio;
}

void TContainerField::resizeEvent(QResizeEvent *e) {
    RptContainer::resizeEvent(e);
    if (this->m_type == Image) {
        if (!m_ignoreAspectRatio) {
            if (!m_pixmap.isNull())
                m_label->setPixmap(m_pixmap.scaled(m_label->width(),m_label->height(),Qt::KeepAspectRatio));
        }
    }
}

QString TContainerField::getImgFormat() {
    return m_imgFormat;
}

void TContainerField::setImgFromat(QString value) {
    m_imgFormat = value;
}

TContainerField::~TContainerField() {
}

#include "UndoCommands.h"
void TContainerField::edit() {
    RptContainerList selContList;
    selContList.append(this);
    //before changing params gets params
    BArrayList oldList = ParamsContainerCommand::getBArrayFromContList(selContList);

    EditFldDlg *dlg = new EditFldDlg(this);
    switch(m_type) {
        case Text:
        case TextImage: {
            if (dlg->showText(this) == QDialog::Accepted)
                emit contChanged(true);
            break;
        }
        case TextRich: {
            if (dlg->showTextRich(this) == QDialog::Accepted)
                emit contChanged(true);
            break;
        }
        case Image: {
            if (dlg->showImage(this) == QDialog::Accepted)
                emit contChanged(true);
                emit inFocus(true);
            break;
        }
        case Diagram: {
            if (dlg->showDiagram(this) == QDialog::Accepted)
                emit contChanged(true);
            break;
        }
        case Barcode: {
            if (dlg->showBarcode(this) == QDialog::Accepted)
                emit contChanged(true);
            break;
        }
        default: return;
    }
    if (dlg->result() == QDialog::Accepted) {
        //gets new params
        BArrayList newList = ParamsContainerCommand::getBArrayFromContList(selContList);
        QList<PairCont> lst = ParamsContainerCommand::compoundArrays(oldList,newList);
        getMW()->m_undoStack->push(new ParamsContainerCommand( lst ));
    }

    delete dlg;    
    this->setSelected(true);
    emit this->inFocus(true);
}

void TContainerField::mouseDoubleClickEvent (QMouseEvent * event) {
    Q_UNUSED(event);
    edit();
}

void TContainerField::setType(FieldType value, QDomDocument *xmlDoc) {
    RptContainer::setType(value);
    switch(value) {
        case TextRich: {
            setAligment(Qt::AlignTop);
            break;
        }
        case Reactangle:
        case RoundedReactangle:
        case Rhombus:
        case Triangle:
        case Circle: {
            setStyleSheet("/**/" );
            setText("");
            break;
        }
        case Image: {
            setText(tr("New image"));
            setIgnoreAspectRatio(true);
            setImage(QPixmap(QString::fromUtf8(":/new/prefix1/images/picture.png")));
            setStyleSheet("/**/");
            break;
        }
        case Diagram: {
            setText(tr("New diagram"));
            setIgnoreAspectRatio(true);
            setImage(QPixmap(QString::fromUtf8(":/new/prefix1/images/diagram.png")));
            m_label->setVisible(false);

            if (this->parentWidget()->objectName() == "MainWindow") {
                this->resize(300+40,300);
                this->setBaseSize(300,300);
            }

            m_chart = new Chart(this);
            m_chart->setObjectName("chart");
            m_chart->setVisible(true);
            m_chart->setAttribute(Qt::WA_TransparentForMouseEvents, true);
            if (xmlDoc != 0)
                m_chart->loadXML(xmlDoc->createElement("TContainerField"));

            this->setStyleSheet(this->styleSheet().replace("QLabel","Chart") );
            this->setSheetValue(BackgroundColor, "rgba(255,255,255,255)");

            vLayout->addWidget(m_chart);
            vLayout->setContentsMargins(0,0,0,0);
            break;
        }
        case Barcode: {
            m_barcode = new BarCode(this);
            m_label->setVisible(false);
            if (this->parentWidget()->objectName() == "MainWindow") {
                this->resize(200,100);
                this->setBaseSize(200,100);
            }
            break;
        }
        default:
            break;
    }
}

void TContainerField::loadParamFromXML(QDomElement e) {
    RptContainer::loadParamFromXML(e);
    this->setType(m_type,0);

    if (this->m_type == Text) {
        this->m_formatString = e.attribute("format","");
        this->m_highlighting = e.attribute("highlighting","");
        setTextWrap( e.attribute("textWrap","1").toInt() );
    } else if (this->m_type == Image || e.attribute("picture","text") != "text") {
        //load picture into lable
        QByteArray byteArray;
        byteArray = QByteArray::fromBase64(e.attribute("picture","text").toLatin1());
        m_imgFormat = e.attribute("imgFormat","PNG");
        m_pixmap = QPixmap::fromImage(QImage::fromData(byteArray, m_imgFormat.toLatin1().data()));
        m_label->setPixmap(m_pixmap);
        m_ignoreAspectRatio = e.attribute("ignoreAspectRatio","1").toInt();
        m_label->setScaledContents( m_ignoreAspectRatio );
        resizeEvent(0);
    } else if (this->m_type == Diagram) {
        m_chart->setParams(e.attribute("showGrid","1").toInt(),
                         e.attribute("showLegend","1").toInt(),
                         e.attribute("showCaption","1").toInt(),
                         e.attribute("showGraphCaption","1").toInt(),
                         e.attribute("showPercent","1").toInt(),
                         e.attribute("caption","Example"),
                         e.attribute("autoFillData","0").toInt()
                         );
        m_chart->loadXML(e);
    } else if (this->m_type == Barcode) {
        setBarcodeType( (BarCode::BarcodeTypes)e.attribute("barcodeType","13").toInt() );
        setBarcodeFrameType( (BarCode::FrameTypes)e.attribute("barcodeFrameType","0").toInt() );
    }
    this->setText(e.attribute("value"));

    this->setSheetValue(BackgroundColor,e.attribute("backgroundColor","rgba(255,255,255,0)"));
    this->setSheetValue(FontColor,e.attribute("fontColor","rgba(0,0,0,255)"));
    this->setSheetValue(BorderColor,e.attribute("borderColor","rgba(0,0,0,255)"));
    this->setSheetValue(FrameTop,e.attribute("borderTop","rgba(0,0,0,255)"));
    this->setSheetValue(FrameBottom,e.attribute("borderBottom","rgba(0,0,0,255)"));
    this->setSheetValue(FrameLeft,e.attribute("borderLeft","rgba(0,0,0,255)"));
    this->setSheetValue(FrameRight,e.attribute("borderRight","rgba(0,0,0,255)"));

    QFont fnt = this->childWidget->font();
    fnt.setBold(e.attribute("fontBold").toInt());
    fnt.setItalic(e.attribute("fontItalic").toInt());
    fnt.setUnderline(e.attribute("fontUnderline").toInt());
    fnt.setStrikeOut(e.attribute("fontStrikeout").toInt());
    fnt.setFamily(e.attribute("fontFamily"));
    //fnt.setPointSize(e.attribute("fontSize").toInt());
    this->childWidget->setFont(fnt);
    this->setFontSize(e.attribute("fontSize").toInt());
    this->m_autoHeight = e.attribute("autoHeight","0").toInt();

    Qt::Alignment hAl, vAl;
    if (e.attribute("aligmentH")== "hLeft")
        hAl = Qt::AlignLeft;
    else if (e.attribute("aligmentH")== "hRight")
        hAl = Qt::AlignRight;
    else if (e.attribute("aligmentH")== "hCenter")
        hAl = Qt::AlignHCenter;
    else if (e.attribute("aligmentH") == "hJustify")
        hAl = Qt::AlignJustify;
    else
        hAl = Qt::AlignLeft;

    if (e.attribute("aligmentV") == "vTop")
        vAl = Qt::AlignTop;
    else if (e.attribute("aligmentV") == "vBottom")
        vAl = Qt::AlignBottom;
    else if (e.attribute("aligmentV") == "vCenter")
        vAl = Qt::AlignVCenter;
    else
        vAl = Qt::AlignVCenter;

    m_label->setAlignment(hAl | vAl);
}

QDomElement TContainerField::saveParamToXML(QDomDocument *xmlDoc) {
    QDomElement elem = RptContainer::saveParamToXML(xmlDoc);

    if (this->m_type == Text) {
        elem.setAttribute("format",this->m_formatString);
        elem.setAttribute("highlighting",this->m_highlighting);
        elem.setAttribute("textWrap",this->m_textWrap);
    }
    if (this->m_type == Image) {
        //Saving picture
        QByteArray byteArray;
        QBuffer buffer(&byteArray);
        buffer.open(QIODevice::WriteOnly);

        if (m_imgFormat.isEmpty() || m_imgFormat.isNull())
            m_pixmap.save(&buffer, "PNG");
        else
            m_pixmap.save(&buffer, m_imgFormat.toLatin1().data());
        QString s = byteArray.toBase64();
        elem.setAttribute("picture",s);
        elem.setAttribute("imgFormat",m_imgFormat);
        elem.setAttribute("ignoreAspectRatio",m_ignoreAspectRatio);
    }
    if (this->m_type == Diagram) {
        elem.setAttribute("showGrid",m_chart->getParam(DrawGrid).toBool());
        elem.setAttribute("showLegend",m_chart->getParam(ShowLegend).toBool());
        elem.setAttribute("showCaption",m_chart->getParam(ShowCaption).toBool());
        elem.setAttribute("showGraphCaption",m_chart->getParam(ShowGraphCaption).toBool());
        elem.setAttribute("showPercent",m_chart->getParam(ShowPercent).toBool());
        elem.setAttribute("caption",m_chart->getParam(Caption).toString());
        elem.setAttribute("autoFillData",m_chart->getParam(AutoFillData).toBool());

        if (m_chart->getParam(AutoFillData).toBool()) {
            //get info about graphs
            foreach (GraphParam graphParam, getChart()->getGraphParamList()) {
                QDomElement graph = xmlDoc->createElement("graph");
                graph.setAttribute("caption",graphParam.caption);
                graph.setAttribute("value",graphParam.valueString);
                graph.setAttribute("color",colorToString(graphParam.color));
                elem.appendChild(graph);
            }
        }
    }
    if (this->m_type == Barcode) {
        elem.setAttribute("barcodeType",m_barcode->getBarcodeType() );
        elem.setAttribute("barcodeFrameType",m_barcode->getFrameType() );
    }

    QString hAl, vAl;
    if (m_label->alignment() & Qt::AlignLeft)
        hAl = "hLeft";
    else if (m_label->alignment() & Qt::AlignRight)
        hAl = "hRight";
    else if (m_label->alignment() & Qt::AlignHCenter)
        hAl = "hCenter";
    else if (m_label->alignment() & Qt::AlignJustify)
        hAl = "hJustify";
    else
        hAl = "hLeft";

    if (m_label->alignment() & Qt::AlignTop)
        vAl = "vTop";
    else if (m_label->alignment() & Qt::AlignBottom)
        vAl = "vBottom";
    else if (m_label->alignment() & Qt::AlignVCenter)
        vAl = "vCenter";
    else
        vAl = "vCenter";

    elem.setAttribute("aligmentH",hAl);
    elem.setAttribute("aligmentV",vAl);

    elem.setAttribute("value",m_label->text());

    elem.setAttribute("fontBold",m_label->font().bold());
    elem.setAttribute("fontItalic",m_label->font().italic());
    elem.setAttribute("fontUnderline",m_label->font().underline());
    elem.setAttribute("fontStrikeout",m_label->font().strikeOut());
    if (m_label->font().family().isEmpty()) elem.setAttribute("fontFamily","Arial");
    else elem.setAttribute("fontFamily",m_label->font().family());
    elem.setAttribute("fontSize",fontSizeNoScale);

    QString fontColor = colorToString(getColorValue(FontColor));
    QString backgroundColor = colorToString(getColorValue(BackgroundColor));
    QString borderColor = colorToString(getColorValue(BorderColor));
    QString top = this->getColorValueStr(FrameTop);
    QString bottom = this->getColorValueStr(FrameBottom);
    QString left = this->getColorValueStr(FrameLeft);
    QString right = this->getColorValueStr(FrameRight);

    elem.setAttribute("fontColor",fontColor);
    elem.setAttribute("backgroundColor",backgroundColor);
    elem.setAttribute("borderColor",borderColor);
    elem.setAttribute("borderTop",top);
    elem.setAttribute("borderBottom",bottom);
    elem.setAttribute("borderLeft",left);
    elem.setAttribute("borderRight",right);

    elem.setAttribute("autoHeight",this->m_autoHeight);
    elem.setAttribute("borderStyle",getBorderStyleStr());

    return elem;
}

Chart *TContainerField::getChart() {
    return m_chart;
}

void TContainerField::paintEvent( QPaintEvent * event) {
    Q_UNUSED(event);

    if (!QtRPT::getDrawingFields().contains(m_type) && m_type != Barcode) {
        QWidget::paintEvent(event);
        return;
    }

    //label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QBrush brush( getColorValue(BackgroundColor) );
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing,true);
    p.setPen(QPen( getColorValue(BorderColor), getBorderWidth(), Qt::SolidLine, Qt::RoundCap));

    switch(m_type) {
        case Circle: {
            p.setBrush(brush);
            p.drawEllipse(0, 0, width() - 1, height() - 1);
            break;
        }
        case Triangle: {
            qreal pointX1 = 0;
            qreal pointY1 = height()-1;

            qreal pointX2 = width();
            qreal pointY2 = height()-1;

            qreal pointX3 = width()/2;
            qreal pointY3 = 0;

            QPainterPath path;
            path.moveTo (pointX1, pointY1);
            path.lineTo (pointX2, pointY2);
            path.lineTo (pointX3, pointY3);
            path.lineTo (pointX1, pointY1);
            p.drawPath(path);
            p.fillPath (path, brush);
            break;
        }
        case Rhombus: {
            qreal pointX1 = width()/2;
            qreal pointY1 = height()-1;

            qreal pointX2 = width();
            qreal pointY2 = height()/2;

            qreal pointX3 = width()/2;
            qreal pointY3 = 1;

            qreal pointX4 = 1;
            qreal pointY4 = height()/2;

            QPainterPath path;
            path.moveTo (pointX1, pointY1);
            path.lineTo (pointX2, pointY2);
            path.lineTo (pointX3, pointY3);
            path.lineTo (pointX4, pointY4);
            path.lineTo (pointX1, pointY1);
            p.drawPath(path);
            p.fillPath (path, brush);
            break;
        }
        case RoundedReactangle: {
            QRectF rect(1,1,width()-2,height()-2);
            p.setBrush(brush);
            p.drawRoundedRect(rect, radius, radius);
            break;
        }
        case Reactangle: {
            QRectF rect(1,1,width()-2,height()-2);
            p.setBrush(brush);
            p.drawRect(rect);
            break;
        }
        case Barcode: {
            if (m_barcode != 0) {
                m_barcode->setValue(m_label->text());
                m_barcode->drawBarcode(&p,0,0,this->width(),this->height());
            }
            break;
        }
    default: QWidget::paintEvent(event);
    }
}

void TContainerField::setFontSize(int value) {
    if (value == 0) return;
    QFont fnt = childWidget->font();
    fnt.setPointSizeF(value+8*(scale-1));
    childWidget->setFont(fnt);
    fontSizeNoScale = value;
}

int TContainerField::getFontSize() {
    return fontSizeNoScale;
}

BarCode::BarcodeTypes TContainerField::getBarcodeType() {
    return m_barcode->getBarcodeType();
}

void TContainerField::setBarcodeType(BarCode::BarcodeTypes value) {
    m_barcode->setBarcodeType(value);
    this->repaint();
}

BarCode::FrameTypes TContainerField::getBarcodeFrameType() {
    return m_barcode->getFrameType();
}

void TContainerField::setBarcodeFrameType(BarCode::FrameTypes value) {
    m_barcode->setFrameType(value);
    this->repaint();
}

void TContainerField::setProperties() {
    this->setProperty("FieldType",m_type);
    this->setProperty("LabelVisibility",m_label->isVisible());
}

//Restore fields from properties
void TContainerField::setParamFromProperties() {
    m_type = (FieldType)this->property("FieldType").toInt();
    m_label->setVisible( this->property("LabelVisibility").toBool() );
}

QDataStream &operator<<(QDataStream &stream, const TContainerField &obj) {
    for(int i=0; i<obj.metaObject()->propertyCount(); ++i) {
        if(obj.metaObject()->property(i).isStored(&obj)) {
            stream << obj.metaObject()->property(i).read(&obj);
        }
    }
    QList<QByteArray> list = obj.dynamicPropertyNames();
    for (int i=0; i<list.size(); i++) {
        stream << obj.property(list.at(i));
    }
    if (obj.m_type == Diagram) {
        obj.m_chart->setProperties();
        stream << *obj.m_chart;
    }
    if (obj.m_type == Barcode) {
        obj.m_barcode->setProperties();
        stream << *obj.m_barcode;
    }
    return stream;
}

QDataStream &operator>>(QDataStream &stream, TContainerField &obj) {
    QVariant var;
    for(int i=0; i<obj.metaObject()->propertyCount(); ++i) {
        if(obj.metaObject()->property(i).isStored(&obj)) {
            stream >> var;
            if (!var.isNull())
                obj.metaObject()->property(i).write(&obj, var);
        }
    }
    obj.setProperties();
    QList<QByteArray> list = obj.dynamicPropertyNames();
    for (int i=0; i<list.size(); i++) {
        stream >> var;
        obj.setProperty(list.at(i),QVariant(var));
    }


    obj.setParamFromProperties();
    if (obj.m_type == Diagram) {
        obj.m_chart = new Chart(&obj);
        stream >> *obj.m_chart;
    }
    if (obj.m_type == Barcode) {
        obj.m_barcode = new BarCode(&obj);
        stream >> *obj.m_barcode;
    }
    return stream;
}
