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
#include "entropychart.h"
#include <QDebug>
EntropyChart::EntropyChart(QWidget *parent):
    QChartView(parent)
{

}

// The chart QChartView creates for itself is empty, and it stays empty until
// EntropyDialog::calculate() installs the first real one at the end of a scan.
// calculate() pumps the event loop while it runs, so these handlers do get
// called with no series attached: series().at(0) would then index an empty
// QList, which is a crash and not a warning in a release build.
bool EntropyChart::valueAt(const QPoint &pos, QPointF &value) const
{
    QChart *c = this->chart();
    if (!c || c->series().isEmpty())
        return false;
    value = c->mapToValue(pos, c->series().at(0));
    return true;
}

void EntropyChart::mousePressEvent(QMouseEvent * event){
    QPointF pickVal;
    if (valueAt(this->mapFromGlobal(QCursor::pos()), pickVal)) {
        emit rubberBandEvent();
        emit mousePressed(qint64(pickVal.x()));
    }

    QChartView::mousePressEvent(event);

}
void EntropyChart::resizeEvent(QResizeEvent *event){

    emit rubberBandEvent();
    QChartView::resizeEvent(event);
}
void EntropyChart::mouseReleaseEvent(QMouseEvent *event){
    emit rubberBandEvent();
    QChartView::mouseReleaseEvent(event);
}

void EntropyChart::mouseMoveEvent(QMouseEvent * event){
    QPointF pickVal;
    if (valueAt(this->mapFromGlobal(QCursor::pos()), pickVal))
        emit mouseMoved(qint64(pickVal.x()));

    QChartView::mouseMoveEvent(event);
}
