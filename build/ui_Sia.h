/********************************************************************************
** Form generated from reading UI file 'Sia.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIA_H
#define UI_SIA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_Sia
{
public:
    QAction *actionOpenFile;
    QAction *actionExit;
    QAction *actionPrint;
    QAction *actionHelp;
    QAction *actionSave;
    QWidget *centralwidget;
    QVTKWidget *qvtkWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_23;
    QLabel *label_22;
    QLabel *label_11;
    QDoubleSpinBox *plate_d;
    QLabel *label_12;
    QDoubleSpinBox *plate_h;
    QLabel *label_13;
    QDoubleSpinBox *plate_i;
    QLabel *label_14;
    QLabel *label_8;
    QLabel *label_10;
    QDoubleSpinBox *plate_a;
    QDoubleSpinBox *plate_r;
    QLabel *label_9;
    QLabel *label_21;
    QLabel *label_19;
    QLabel *label_20;
    QDoubleSpinBox *plate_k;
    QLabel *label_15;
    QDoubleSpinBox *plate_l;
    QLabel *label_18;
    QDoubleSpinBox *plate_n;
    QLabel *label_17;
    QDoubleSpinBox *plate_m;
    QLabel *label_16;
    QLabel *label_24;
    QDoubleSpinBox *plate_actor_origin_x;
    QDoubleSpinBox *plate_actor_origin_y;
    QDoubleSpinBox *plate_actor_origin_z;
    QDoubleSpinBox *plate_actor_angle_x;
    QDoubleSpinBox *plate_actor_angle_y;
    QDoubleSpinBox *plate_actor_angle_z;
    QCheckBox *plate_visibility;
    QPushButton *make_plate;
    QCheckBox *is_plate_right_side;
    QCheckBox *lower_jaw_visibility;
    QPushButton *open_lower_jaw;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_35;
    QLabel *label_36;
    QLabel *label_37;
    QLabel *label_38;
    QLabel *label_29;
    QLabel *label_25;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_33;
    QDoubleSpinBox *head_s;
    QDoubleSpinBox *head_t;
    QDoubleSpinBox *head_u;
    QDoubleSpinBox *head_v;
    QDoubleSpinBox *head_w;
    QDoubleSpinBox *head_x;
    QDoubleSpinBox *head_y;
    QLabel *label_34;
    QLabel *label_30;
    QLabel *label_28;
    QLabel *label_27;
    QLabel *label_39;
    QDoubleSpinBox *head_actor_origin_x;
    QDoubleSpinBox *head_actor_origin_y;
    QDoubleSpinBox *head_actor_origin_z;
    QDoubleSpinBox *head_actor_angle_x;
    QDoubleSpinBox *head_actor_angle_y;
    QDoubleSpinBox *head_actor_angle_z;
    QLabel *label_26;
    QPushButton *make_head;
    QPushButton *make_junction;
    QPushButton *adhering;

    void setupUi(QMainWindow *Sia)
    {
        if (Sia->objectName().isEmpty())
            Sia->setObjectName(QStringLiteral("Sia"));
        Sia->resize(1029, 522);
        Sia->setStyleSheet(QStringLiteral("background-color: white;"));
        actionOpenFile = new QAction(Sia);
        actionOpenFile->setObjectName(QStringLiteral("actionOpenFile"));
        actionOpenFile->setEnabled(true);
        actionExit = new QAction(Sia);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionPrint = new QAction(Sia);
        actionPrint->setObjectName(QStringLiteral("actionPrint"));
        actionHelp = new QAction(Sia);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionSave = new QAction(Sia);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        centralwidget = new QWidget(Sia);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setStyleSheet(QStringLiteral(""));
        qvtkWidget = new QVTKWidget(centralwidget);
        qvtkWidget->setObjectName(QStringLiteral("qvtkWidget"));
        qvtkWidget->setGeometry(QRect(449, 10, 571, 501));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(qvtkWidget->sizePolicy().hasHeightForWidth());
        qvtkWidget->setSizePolicy(sizePolicy);
        qvtkWidget->setMinimumSize(QSize(400, 400));
        qvtkWidget->setAutoFillBackground(false);
        qvtkWidget->setStyleSheet(QStringLiteral("background-color: #B2DFDB;"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 220, 496));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_23 = new QLabel(gridLayoutWidget);
        label_23->setObjectName(QStringLiteral("label_23"));

        gridLayout->addWidget(label_23, 16, 0, 1, 1);

        label_22 = new QLabel(gridLayoutWidget);
        label_22->setObjectName(QStringLiteral("label_22"));

        gridLayout->addWidget(label_22, 15, 0, 1, 1);

        label_11 = new QLabel(gridLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout->addWidget(label_11, 4, 0, 1, 1);

        plate_d = new QDoubleSpinBox(gridLayoutWidget);
        plate_d->setObjectName(QStringLiteral("plate_d"));

        gridLayout->addWidget(plate_d, 4, 1, 1, 1);

        label_12 = new QLabel(gridLayoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout->addWidget(label_12, 5, 0, 1, 1);

        plate_h = new QDoubleSpinBox(gridLayoutWidget);
        plate_h->setObjectName(QStringLiteral("plate_h"));

        gridLayout->addWidget(plate_h, 5, 1, 1, 1);

        label_13 = new QLabel(gridLayoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout->addWidget(label_13, 6, 0, 1, 1);

        plate_i = new QDoubleSpinBox(gridLayoutWidget);
        plate_i->setObjectName(QStringLiteral("plate_i"));

        gridLayout->addWidget(plate_i, 6, 1, 1, 1);

        label_14 = new QLabel(gridLayoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout->addWidget(label_14, 7, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 2, 0, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 3, 0, 1, 1);

        plate_a = new QDoubleSpinBox(gridLayoutWidget);
        plate_a->setObjectName(QStringLiteral("plate_a"));

        gridLayout->addWidget(plate_a, 3, 1, 1, 1);

        plate_r = new QDoubleSpinBox(gridLayoutWidget);
        plate_r->setObjectName(QStringLiteral("plate_r"));

        gridLayout->addWidget(plate_r, 11, 1, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 2, 1, 1, 1);

        label_21 = new QLabel(gridLayoutWidget);
        label_21->setObjectName(QStringLiteral("label_21"));

        gridLayout->addWidget(label_21, 14, 0, 1, 1);

        label_19 = new QLabel(gridLayoutWidget);
        label_19->setObjectName(QStringLiteral("label_19"));

        gridLayout->addWidget(label_19, 12, 0, 1, 1);

        label_20 = new QLabel(gridLayoutWidget);
        label_20->setObjectName(QStringLiteral("label_20"));

        gridLayout->addWidget(label_20, 13, 0, 1, 1);

        plate_k = new QDoubleSpinBox(gridLayoutWidget);
        plate_k->setObjectName(QStringLiteral("plate_k"));

        gridLayout->addWidget(plate_k, 7, 1, 1, 1);

        label_15 = new QLabel(gridLayoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout->addWidget(label_15, 8, 0, 1, 1);

        plate_l = new QDoubleSpinBox(gridLayoutWidget);
        plate_l->setObjectName(QStringLiteral("plate_l"));

        gridLayout->addWidget(plate_l, 8, 1, 1, 1);

        label_18 = new QLabel(gridLayoutWidget);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout->addWidget(label_18, 11, 0, 1, 1);

        plate_n = new QDoubleSpinBox(gridLayoutWidget);
        plate_n->setObjectName(QStringLiteral("plate_n"));

        gridLayout->addWidget(plate_n, 10, 1, 1, 1);

        label_17 = new QLabel(gridLayoutWidget);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout->addWidget(label_17, 10, 0, 1, 1);

        plate_m = new QDoubleSpinBox(gridLayoutWidget);
        plate_m->setObjectName(QStringLiteral("plate_m"));

        gridLayout->addWidget(plate_m, 9, 1, 1, 1);

        label_16 = new QLabel(gridLayoutWidget);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout->addWidget(label_16, 9, 0, 1, 1);

        label_24 = new QLabel(gridLayoutWidget);
        label_24->setObjectName(QStringLiteral("label_24"));

        gridLayout->addWidget(label_24, 17, 0, 1, 1);

        plate_actor_origin_x = new QDoubleSpinBox(gridLayoutWidget);
        plate_actor_origin_x->setObjectName(QStringLiteral("plate_actor_origin_x"));
        plate_actor_origin_x->setMinimum(-100);
        plate_actor_origin_x->setMaximum(100);

        gridLayout->addWidget(plate_actor_origin_x, 12, 1, 1, 1);

        plate_actor_origin_y = new QDoubleSpinBox(gridLayoutWidget);
        plate_actor_origin_y->setObjectName(QStringLiteral("plate_actor_origin_y"));
        plate_actor_origin_y->setMinimum(-100);
        plate_actor_origin_y->setMaximum(100);

        gridLayout->addWidget(plate_actor_origin_y, 13, 1, 1, 1);

        plate_actor_origin_z = new QDoubleSpinBox(gridLayoutWidget);
        plate_actor_origin_z->setObjectName(QStringLiteral("plate_actor_origin_z"));
        plate_actor_origin_z->setMinimum(-100);
        plate_actor_origin_z->setMaximum(100);

        gridLayout->addWidget(plate_actor_origin_z, 14, 1, 1, 1);

        plate_actor_angle_x = new QDoubleSpinBox(gridLayoutWidget);
        plate_actor_angle_x->setObjectName(QStringLiteral("plate_actor_angle_x"));
        plate_actor_angle_x->setMinimum(-360);
        plate_actor_angle_x->setMaximum(360);

        gridLayout->addWidget(plate_actor_angle_x, 15, 1, 1, 1);

        plate_actor_angle_y = new QDoubleSpinBox(gridLayoutWidget);
        plate_actor_angle_y->setObjectName(QStringLiteral("plate_actor_angle_y"));
        plate_actor_angle_y->setMinimum(-360);
        plate_actor_angle_y->setMaximum(360);

        gridLayout->addWidget(plate_actor_angle_y, 16, 1, 1, 1);

        plate_actor_angle_z = new QDoubleSpinBox(gridLayoutWidget);
        plate_actor_angle_z->setObjectName(QStringLiteral("plate_actor_angle_z"));
        plate_actor_angle_z->setMinimum(-360);
        plate_actor_angle_z->setMaximum(360);

        gridLayout->addWidget(plate_actor_angle_z, 17, 1, 1, 1);

        plate_visibility = new QCheckBox(gridLayoutWidget);
        plate_visibility->setObjectName(QStringLiteral("plate_visibility"));
        plate_visibility->setChecked(true);

        gridLayout->addWidget(plate_visibility, 1, 1, 1, 1);

        make_plate = new QPushButton(gridLayoutWidget);
        make_plate->setObjectName(QStringLiteral("make_plate"));

        gridLayout->addWidget(make_plate, 1, 0, 1, 1);

        is_plate_right_side = new QCheckBox(gridLayoutWidget);
        is_plate_right_side->setObjectName(QStringLiteral("is_plate_right_side"));

        gridLayout->addWidget(is_plate_right_side, 18, 0, 1, 1);

        lower_jaw_visibility = new QCheckBox(gridLayoutWidget);
        lower_jaw_visibility->setObjectName(QStringLiteral("lower_jaw_visibility"));
        lower_jaw_visibility->setChecked(true);

        gridLayout->addWidget(lower_jaw_visibility, 0, 1, 1, 1);

        open_lower_jaw = new QPushButton(gridLayoutWidget);
        open_lower_jaw->setObjectName(QStringLiteral("open_lower_jaw"));

        gridLayout->addWidget(open_lower_jaw, 0, 0, 1, 1);

        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(240, 10, 189, 385));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_35 = new QLabel(gridLayoutWidget_2);
        label_35->setObjectName(QStringLiteral("label_35"));

        gridLayout_2->addWidget(label_35, 10, 0, 1, 1);

        label_36 = new QLabel(gridLayoutWidget_2);
        label_36->setObjectName(QStringLiteral("label_36"));

        gridLayout_2->addWidget(label_36, 11, 0, 1, 1);

        label_37 = new QLabel(gridLayoutWidget_2);
        label_37->setObjectName(QStringLiteral("label_37"));

        gridLayout_2->addWidget(label_37, 12, 0, 1, 1);

        label_38 = new QLabel(gridLayoutWidget_2);
        label_38->setObjectName(QStringLiteral("label_38"));

        gridLayout_2->addWidget(label_38, 13, 0, 1, 1);

        label_29 = new QLabel(gridLayoutWidget_2);
        label_29->setObjectName(QStringLiteral("label_29"));

        gridLayout_2->addWidget(label_29, 4, 0, 1, 1);

        label_25 = new QLabel(gridLayoutWidget_2);
        label_25->setObjectName(QStringLiteral("label_25"));

        gridLayout_2->addWidget(label_25, 1, 0, 1, 1);

        label_31 = new QLabel(gridLayoutWidget_2);
        label_31->setObjectName(QStringLiteral("label_31"));

        gridLayout_2->addWidget(label_31, 6, 0, 1, 1);

        label_32 = new QLabel(gridLayoutWidget_2);
        label_32->setObjectName(QStringLiteral("label_32"));

        gridLayout_2->addWidget(label_32, 7, 0, 1, 1);

        label_33 = new QLabel(gridLayoutWidget_2);
        label_33->setObjectName(QStringLiteral("label_33"));

        gridLayout_2->addWidget(label_33, 8, 0, 1, 1);

        head_s = new QDoubleSpinBox(gridLayoutWidget_2);
        head_s->setObjectName(QStringLiteral("head_s"));

        gridLayout_2->addWidget(head_s, 2, 1, 1, 1);

        head_t = new QDoubleSpinBox(gridLayoutWidget_2);
        head_t->setObjectName(QStringLiteral("head_t"));

        gridLayout_2->addWidget(head_t, 3, 1, 1, 1);

        head_u = new QDoubleSpinBox(gridLayoutWidget_2);
        head_u->setObjectName(QStringLiteral("head_u"));

        gridLayout_2->addWidget(head_u, 4, 1, 1, 1);

        head_v = new QDoubleSpinBox(gridLayoutWidget_2);
        head_v->setObjectName(QStringLiteral("head_v"));

        gridLayout_2->addWidget(head_v, 5, 1, 1, 1);

        head_w = new QDoubleSpinBox(gridLayoutWidget_2);
        head_w->setObjectName(QStringLiteral("head_w"));

        gridLayout_2->addWidget(head_w, 6, 1, 1, 1);

        head_x = new QDoubleSpinBox(gridLayoutWidget_2);
        head_x->setObjectName(QStringLiteral("head_x"));

        gridLayout_2->addWidget(head_x, 7, 1, 1, 1);

        head_y = new QDoubleSpinBox(gridLayoutWidget_2);
        head_y->setObjectName(QStringLiteral("head_y"));

        gridLayout_2->addWidget(head_y, 8, 1, 1, 1);

        label_34 = new QLabel(gridLayoutWidget_2);
        label_34->setObjectName(QStringLiteral("label_34"));

        gridLayout_2->addWidget(label_34, 9, 0, 1, 1);

        label_30 = new QLabel(gridLayoutWidget_2);
        label_30->setObjectName(QStringLiteral("label_30"));

        gridLayout_2->addWidget(label_30, 5, 0, 1, 1);

        label_28 = new QLabel(gridLayoutWidget_2);
        label_28->setObjectName(QStringLiteral("label_28"));

        gridLayout_2->addWidget(label_28, 3, 0, 1, 1);

        label_27 = new QLabel(gridLayoutWidget_2);
        label_27->setObjectName(QStringLiteral("label_27"));

        gridLayout_2->addWidget(label_27, 2, 0, 1, 1);

        label_39 = new QLabel(gridLayoutWidget_2);
        label_39->setObjectName(QStringLiteral("label_39"));

        gridLayout_2->addWidget(label_39, 14, 0, 1, 1);

        head_actor_origin_x = new QDoubleSpinBox(gridLayoutWidget_2);
        head_actor_origin_x->setObjectName(QStringLiteral("head_actor_origin_x"));
        head_actor_origin_x->setMinimum(-100);
        head_actor_origin_x->setMaximum(100);

        gridLayout_2->addWidget(head_actor_origin_x, 9, 1, 1, 1);

        head_actor_origin_y = new QDoubleSpinBox(gridLayoutWidget_2);
        head_actor_origin_y->setObjectName(QStringLiteral("head_actor_origin_y"));
        head_actor_origin_y->setMinimum(-100);
        head_actor_origin_y->setMaximum(100);

        gridLayout_2->addWidget(head_actor_origin_y, 10, 1, 1, 1);

        head_actor_origin_z = new QDoubleSpinBox(gridLayoutWidget_2);
        head_actor_origin_z->setObjectName(QStringLiteral("head_actor_origin_z"));
        head_actor_origin_z->setMinimum(-100);
        head_actor_origin_z->setMaximum(100);

        gridLayout_2->addWidget(head_actor_origin_z, 11, 1, 1, 1);

        head_actor_angle_x = new QDoubleSpinBox(gridLayoutWidget_2);
        head_actor_angle_x->setObjectName(QStringLiteral("head_actor_angle_x"));
        head_actor_angle_x->setMinimum(-360);
        head_actor_angle_x->setMaximum(360);

        gridLayout_2->addWidget(head_actor_angle_x, 12, 1, 1, 1);

        head_actor_angle_y = new QDoubleSpinBox(gridLayoutWidget_2);
        head_actor_angle_y->setObjectName(QStringLiteral("head_actor_angle_y"));
        head_actor_angle_y->setMinimum(-360);
        head_actor_angle_y->setMaximum(360);

        gridLayout_2->addWidget(head_actor_angle_y, 13, 1, 1, 1);

        head_actor_angle_z = new QDoubleSpinBox(gridLayoutWidget_2);
        head_actor_angle_z->setObjectName(QStringLiteral("head_actor_angle_z"));
        head_actor_angle_z->setMinimum(-360);
        head_actor_angle_z->setMaximum(360);

        gridLayout_2->addWidget(head_actor_angle_z, 14, 1, 1, 1);

        label_26 = new QLabel(gridLayoutWidget_2);
        label_26->setObjectName(QStringLiteral("label_26"));

        gridLayout_2->addWidget(label_26, 1, 1, 1, 1);

        make_head = new QPushButton(gridLayoutWidget_2);
        make_head->setObjectName(QStringLiteral("make_head"));

        gridLayout_2->addWidget(make_head, 0, 0, 1, 1);

        make_junction = new QPushButton(gridLayoutWidget_2);
        make_junction->setObjectName(QStringLiteral("make_junction"));

        gridLayout_2->addWidget(make_junction, 15, 0, 1, 1);

        adhering = new QPushButton(gridLayoutWidget_2);
        adhering->setObjectName(QStringLiteral("adhering"));

        gridLayout_2->addWidget(adhering, 15, 1, 1, 1);

        Sia->setCentralWidget(centralwidget);

        retranslateUi(Sia);

        QMetaObject::connectSlotsByName(Sia);
    } // setupUi

    void retranslateUi(QMainWindow *Sia)
    {
        Sia->setWindowTitle(QApplication::translate("Sia", "Sia", 0));
        actionOpenFile->setText(QApplication::translate("Sia", "Open File...", 0));
        actionExit->setText(QApplication::translate("Sia", "Exit", 0));
        actionPrint->setText(QApplication::translate("Sia", "Print", 0));
        actionHelp->setText(QApplication::translate("Sia", "Help", 0));
        actionSave->setText(QApplication::translate("Sia", "Save", 0));
        label_23->setText(QApplication::translate("Sia", "angle_y", 0));
        label_22->setText(QApplication::translate("Sia", "angle_x", 0));
        label_11->setText(QApplication::translate("Sia", "d", 0));
        label_12->setText(QApplication::translate("Sia", "h", 0));
        label_13->setText(QApplication::translate("Sia", "i", 0));
        label_14->setText(QApplication::translate("Sia", "k", 0));
        label_8->setText(QApplication::translate("Sia", "\320\230\320\274\321\217 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\260", 0));
        label_10->setText(QApplication::translate("Sia", "a", 0));
        label_9->setText(QApplication::translate("Sia", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\260", 0));
        label_21->setText(QApplication::translate("Sia", "dz", 0));
        label_19->setText(QApplication::translate("Sia", "dx", 0));
        label_20->setText(QApplication::translate("Sia", "dy", 0));
        label_15->setText(QApplication::translate("Sia", "l", 0));
        label_18->setText(QApplication::translate("Sia", "r", 0));
        label_17->setText(QApplication::translate("Sia", "n", 0));
        label_16->setText(QApplication::translate("Sia", "m", 0));
        label_24->setText(QApplication::translate("Sia", "angle_z", 0));
        plate_visibility->setText(QApplication::translate("Sia", "\320\222\320\270\320\264\320\270\320\274\320\276\321\201\321\202\321\214", 0));
        make_plate->setText(QApplication::translate("Sia", "MakePlate", 0));
        is_plate_right_side->setText(QApplication::translate("Sia", "\320\237\321\200\320\260\320\262\320\276\321\201\321\202\320\276\321\200\320\276\320\275\320\275\320\270\320\271", 0));
        lower_jaw_visibility->setText(QApplication::translate("Sia", "\320\222\320\270\320\264\320\270\320\274\320\276\321\201\321\202\321\214", 0));
        open_lower_jaw->setText(QApplication::translate("Sia", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\275\320\270\320\266\320\275\321\216\321\216\n"
" \321\207\320\265\320\273\321\216\321\201\321\202\321\214", 0));
        label_35->setText(QApplication::translate("Sia", "dy", 0));
        label_36->setText(QApplication::translate("Sia", "dz", 0));
        label_37->setText(QApplication::translate("Sia", "angle_x", 0));
        label_38->setText(QApplication::translate("Sia", "angle_y", 0));
        label_29->setText(QApplication::translate("Sia", "u", 0));
        label_25->setText(QApplication::translate("Sia", "\320\230\320\274\321\217 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\260", 0));
        label_31->setText(QApplication::translate("Sia", "w", 0));
        label_32->setText(QApplication::translate("Sia", "x", 0));
        label_33->setText(QApplication::translate("Sia", "y", 0));
        label_34->setText(QApplication::translate("Sia", "dx", 0));
        label_30->setText(QApplication::translate("Sia", "v", 0));
        label_28->setText(QApplication::translate("Sia", "t", 0));
        label_27->setText(QApplication::translate("Sia", "s", 0));
        label_39->setText(QApplication::translate("Sia", "angle_z", 0));
        label_26->setText(QApplication::translate("Sia", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\260", 0));
        make_head->setText(QApplication::translate("Sia", "MakeHead", 0));
        make_junction->setText(QApplication::translate("Sia", "MakeJunction", 0));
        adhering->setText(QApplication::translate("Sia", "Adhering", 0));
    } // retranslateUi

};

namespace Ui {
    class Sia: public Ui_Sia {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIA_H
