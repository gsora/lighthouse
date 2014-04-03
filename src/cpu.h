/*
    Copyright (C) 2014 Ales Katona.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CPU_H
#define CPU_H

#include <QObject>
#include <QAbstractListModel>
#include "types.h"

namespace Lighthouse {

    class CPU : public QAbstractListModel
    {
        Q_OBJECT
        Q_PROPERTY(int summaryValue READ getSummaryValue NOTIFY summaryValueChanged)
    public:
        enum ProcessRoles {
            CPUUsageRole = Qt::UserRole + 1
        };

        explicit CPU(QObject *parent = 0);

        QHash<int, QByteArray> roleNames() const;
        Qt::ItemFlags flags(const QModelIndex & index) const;
        QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
        QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
        int rowCount(const QModelIndex & parent = QModelIndex()) const;

        int getSummaryValue();
    private:
        IntList* fUsage;
        int fTotalUsage;
    public slots:
        void setUsage(IntList* usage);
    signals:
        void usageChanged();
        void summaryValueChanged();
    };

}

#endif // CPU_H
