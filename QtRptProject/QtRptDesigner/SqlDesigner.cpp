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

#include "SqlDesigner.h"
#include "ui_SqlDesigner.h"
#include <QMessageBox>
#include <QDrag>
#include <QGraphicsSceneDragDropEvent>
#include <QGraphicsTextItem>
#include <QGraphicsProxyWidget>
#include <QFileDialog>
#include "SQLHighlighter.h"
#include "XmlViewModel.h"

SqlDesigner::SqlDesigner(QWidget *parent) : QWidget(parent), ui(new Ui::SqlDesigner) {
    ui->setupUi(this);
    QSettings settings(QCoreApplication::applicationDirPath()+"/setting.ini",QSettings::IniFormat);
    settings.setIniCodec("UTF-8");

    newDiagramDocument();

    ui->sqlEditor->setAcceptDrops(true);
    ui->graphicsView->setAcceptDrops(true);
    ui->sqlEditor->installEventFilter(this);
    ui->treeWidget->viewport()->installEventFilter(this);

    QActionGroup *actGroup = new QActionGroup(this);
    actGroup->addAction(ui->actAddRelationship);
    actGroup->addAction(ui->actSelect);

    new SQLHighlighter(ui->sqlEditor->document(), &settings);
    QObject::connect(ui->rbCustom, SIGNAL(clicked()), this, SLOT(rbChecked()));
    QObject::connect(ui->rbSql, SIGNAL(clicked()), this, SLOT(rbChecked()));
    QObject::connect(ui->rbXml, SIGNAL(clicked()), this, SLOT(rbChecked()));
    QObject::connect(ui->btnCheck, SIGNAL(clicked()), this, SLOT(connectDB()));
    QObject::connect(ui->btnClose, SIGNAL(clicked()), this, SLOT(btnClose()));
    QObject::connect(ui->actAddRelationship, SIGNAL(triggered()), this, SLOT(addRelation()));
    QObject::connect(ui->actClearDiagram, SIGNAL(triggered()), this, SLOT(clearDiagram()));
    QObject::connect(ui->actSelect, SIGNAL(triggered()), this, SLOT(select()));
    QObject::connect(ui->actUndo, SIGNAL(triggered()), this, SLOT(undo()));
    QObject::connect(ui->actRedo, SIGNAL(triggered()), this, SLOT(redo()));
    QObject::connect(ui->actDelete, SIGNAL(triggered()), this, SLOT(deleteSelected()));
    QObject::connect(ui->btnSelectXML, SIGNAL(clicked()), this, SLOT(selectXMLFile()));
    QObject::connect(scene, SIGNAL(sqlChanged(QString)), this, SLOT(sqlChanged(QString)));
}

void SqlDesigner::showDataSource(QDomElement e) {
    ui->cmbType->clear();
    ui->cmbType->addItems(QSqlDatabase::drivers());
    if (!e.isNull() && e.attribute("type") == "SQL") {
        ui->stackedWidget->setCurrentIndex(1);
        ui->rbSql->setChecked(true);
        ui->sqlEditor->setText(e.text().trimmed());
        ui->edtDBName->setText(e.attribute("dbName"));
        ui->edtHost->setText(e.attribute("dbHost"));
        ui->edtUserName->setText(e.attribute("dbUser"));
        ui->edtPassword->setText(e.attribute("dbPassword"));
        ui->edtConnectionCoding->setText(e.attribute("dbCoding"));
        ui->edtCharsetCoding->setText(e.attribute("charsetCoding"));
        ui->cmbType->setCurrentIndex(ui->cmbType->findText(e.attribute("dbType")));
        ui->edtConName->setText(e.attribute("dbConnectionName"));
        ui->edtPort->setText(e.attribute("dbPort"));

        scene->load(e);
    } else if (!e.isNull() && e.attribute("type") == "XML") {
        ui->stackedWidget->setCurrentIndex(2);


    } else {
        ui->stackedWidget->setCurrentIndex(0);
        ui->rbCustom->setChecked(true);
    }
}

void SqlDesigner::connectDB() {
    if (db.isOpen()) {
        QString connection = db.connectionName();
        db.close();
        db = QSqlDatabase();
        db.removeDatabase(connection);
    }
    db = QSqlDatabase::addDatabase(ui->cmbType->currentText(),"DB1");
    db.setDatabaseName(ui->edtDBName->text());
    db.setHostName(ui->edtHost->text());
    db.setUserName(ui->edtUserName->text());
    db.setPassword(ui->edtPassword->text());
    if(!ui->edtPort->text().isEmpty())
        db.setPort(ui->edtPort->text().toInt());

    db.open();
    if (!db.isOpen()) {
        QMessageBox::warning(this, tr("Error"), db.lastError().text(), QMessageBox::Ok);
    } else {
        refreshTable(&db);
        QMessageBox::information(this, tr("Info"), tr("Connected"), QMessageBox::Ok);        
    }
}

void SqlDesigner::refreshTable(QSqlDatabase *db) {
    ui->treeWidget->clear();
    QIcon icon;
    QStringList lst = db->tables(QSql::Tables);
    for (int i=0; i<lst.size(); i++) {
        QTreeWidgetItem *tableItem = new QTreeWidgetItem(ui->treeWidget);
        tableItem->setText(0,lst.at(i));
        icon.addPixmap(QPixmap(":/new/prefix1/images/table.png"), QIcon::Normal, QIcon::On);
        tableItem->setIcon(0, icon);
        tableItem->setData(0,Qt::UserRole,3);  //Table
    }    
}

QDomElement SqlDesigner::saveParamToXML(QDomDocument *xmlDoc) {
    QDomElement elem;
    if (ui->rbSql->isChecked()) {
        elem = xmlDoc->createElement("DataSource");
        elem.setAttribute("name","DB1");
        elem.setAttribute("type","SQL");
        elem.setAttribute("dbType",ui->cmbType->currentText());
        elem.setAttribute("dbName",ui->edtDBName->text());
        elem.setAttribute("dbHost",ui->edtHost->text());
        elem.setAttribute("dbUser",ui->edtUserName->text());
        elem.setAttribute("dbPassword",ui->edtPassword->text());
        elem.setAttribute("dbCoding",ui->edtConnectionCoding->text());
        elem.setAttribute("charsetCoding",ui->edtCharsetCoding->text());
        elem.setAttribute("dbConnectionName",ui->edtConName->text());
        elem.setAttribute("dbPort",ui->edtPort->text());
        QDomText t = xmlDoc->createTextNode(ui->sqlEditor->toPlainText());
        elem.appendChild(t);
        scene->save(xmlDoc,elem);
    }
    return elem;
}

void SqlDesigner::selectXMLFile() {
    QString folderPath = QApplication::applicationDirPath();
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select File"), folderPath, "XML (*.xml);;User Interface files (*.ui)");
    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly)) {
        QDomDocument document;
        if (document.setContent(&file)) {
            XMLViewModel *model = new XMLViewModel(&document, this);
            ui->treeView->setModel(model);

        } else qDebug()<<"not set";
        file.close();
    } else qDebug()<<"not found";
}

void SqlDesigner::showXMLStuct() {
    QFile file("11.xml");
    if (file.open(QIODevice::ReadOnly)) {
        QDomDocument document;
        if (document.setContent(&file)) {
            XMLViewModel *model = new XMLViewModel(&document, this);
            ui->treeView->setModel(model);

        } else qDebug()<<"not set";
        file.close();
    } else qDebug()<<"not found";
}

void SqlDesigner::rbChecked() {
    if (ui->rbCustom->isChecked()) ui->stackedWidget->setCurrentIndex(0);
    if (ui->rbSql->isChecked()) ui->stackedWidget->setCurrentIndex(1);
    if (ui->rbXml->isChecked()) {
        ui->stackedWidget->setCurrentIndex(2);
        //showXMLStuct();
    }
    emit changed(true);
}

void SqlDesigner::btnClose() {
    this->setVisible(false);
    QAction *act1 = this->parentWidget()->parentWidget()->findChild<QAction *>("actDataSource");
    QAction *act2 = this->parentWidget()->parentWidget()->findChild<QAction *>("actSaveReport");
    if (act1 != 0) {
        act1->setChecked(false);
        act2->setEnabled(true);
    }
}

#include "CommonClasses.h"
#include "column.h"
#include "columnlist.h"
bool SqlDesigner::eventFilter(QObject *obj, QEvent *e) {
    if (obj == ui->treeWidget->viewport()) {
        if (e->type() == QEvent::MouseButtonPress) {
            QMouseEvent  *me = static_cast<QMouseEvent *>(e);
            if (me->buttons() & Qt::LeftButton) {
                QTreeWidgetItem *item = ui->treeWidget->itemAt(me->pos());

                if (item) {
                    ColumnList *colLst = new ColumnList(NULL);

                    QSqlQuery q("select * from "+item->text(0)+" LIMIT 0, 0",db);
                    QSqlRecord rec = q.record();
                    for (int i=0; i<rec.count(); i++) {
                        Column *col =new Column(colLst);
                        col->setName(rec.fieldName(i));
                        col->setDataType( QVariant::typeToName(rec.field(i).type()) );
                        colLst->appendColumn(col);
                    }
                    scene->passColumnsForDroping(colLst);
                }
            }
        }
    }
    if (obj == ui->sqlEditor) {
        if (e->type() == QEvent::DragEnter) {
            QDragEnterEvent *de = static_cast<QDragEnterEvent*>(e);
            de->accept();
            return true;
        }
        if (e->type() == QEvent::Drop) {
            QDropEvent *de = static_cast<QDropEvent*>(e);
            const QMimeData *mimeData = de->mimeData();
            QByteArray encoded = mimeData->data("application/x-qabstractitemmodeldatalist");
            QDataStream stream(&encoded, QIODevice::ReadOnly);
            while (!stream.atEnd()) {
                 int row, col;
                 QMap<int,  QVariant> roleDataMap;
                 stream >> row >> col >> roleDataMap;
                 QString dropped = roleDataMap[0].toString();
                 ui->sqlEditor->textCursor().insertText(dropped);

             }
        }
    }
    return QWidget::eventFilter(obj,e);
}

void SqlDesigner::addRelation() {
    scene->setMode(DiagramDocument::AddRelation);
}

void SqlDesigner::newDiagramDocument() {
    scene = new DiagramDocument(this);
    QRectF sceneRect = scene->sceneRect().united(QRectF(QPointF(0, 0), QPointF(100, 100)));
    scene->setSceneRect(sceneRect);
    QObject::connect(scene, SIGNAL(modeChanged(DiagramDocument::Mode)),
                     SLOT(updateMode(DiagramDocument::Mode)));
    QUndoStack *undoStack = scene->undoStack();
    QObject::connect(undoStack, SIGNAL(canUndoChanged(bool)), ui->actUndo, SLOT(setEnabled(bool)));
    QObject::connect(undoStack, SIGNAL(canRedoChanged(bool)), ui->actRedo, SLOT(setEnabled(bool)));
    ui->actUndo->setEnabled(undoStack->canUndo());
    ui->actRedo->setEnabled(undoStack->canRedo());
    ui->graphicsView->setScene(scene);
}

void SqlDesigner::clearDiagram() {
    newDiagramDocument();
}

void SqlDesigner::undo() {
    QUndoStack *undoStack = scene->undoStack();
    undoStack->undo();
}

void SqlDesigner::redo() {
    QUndoStack *undoStack = scene->undoStack();
    undoStack->redo();
}

void SqlDesigner::select() {
    scene->setMode(DiagramDocument::Select);
}

void SqlDesigner::deleteSelected() {
    scene->deleteSelectedItems();
    emit changed(true);
}

void SqlDesigner::updateMode(DiagramDocument::Mode mode) {
    if (mode == DiagramDocument::Select) ui->actSelect->setChecked(true);
}

void SqlDesigner::sqlChanged(const QString value) {
    ui->sqlEditor->clear();
    ui->sqlEditor->setText(value);
    emit changed(true);
}

SqlDesigner::~SqlDesigner() {
    delete ui;
}
