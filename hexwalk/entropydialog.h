/*
 * Copyright (C) 2025 Carmix <carmixdev@gmail.com>
 *
 * This file is part of HexWalk.
 *
 * HexWalk is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * HexWalk is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
#ifndef ENTROPYDIALOG_H
#define ENTROPYDIALOG_H

#include <QDialog>
#include <QtCharts>
#include <QProgressDialog>
#include "../qhexedit/qhexedit.h"
#include "entropychart.h"

namespace Ui {
class EntropyDialog;
}

class EntropyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EntropyDialog(QHexEdit * hexedit,QWidget *parent = nullptr);
    ~EntropyDialog();
    void calculate();
public slots:
    void mousePressed(qint64 value);
    void mouseMoved(qint64 address);
    void limitZoomOut();
    void refresh();
private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

    void on_entropyChart_mousePressed(qint64 );

private:
    Ui::EntropyDialog *ui;
    QHexEdit * _hexed;
    double blockEntropy(QByteArray * data);
    EntropyChart *entropyView;
    // series is owned by the chart currently set on ui->entropyChart; it stays
    // a member only because mouseMoved() reads it.
    QLineSeries *series = NULL;
    // calculate() pumps the event loop, so the action that starts it can be
    // triggered again while it runs. Re-entering used to overwrite series and
    // hand the same QLineSeries to two QCharts, which double-freed on close.
    bool _calculating = false;
    QPointF findClosestPoint(QLineSeries* lineSeries, qreal x);
};

#endif // ENTROPYDIALOG_H
