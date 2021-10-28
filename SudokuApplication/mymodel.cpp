#include "mymodel.h"

MyModel::MyModel(QObject * parent) : QAbstractTableModel(parent)
{
    SimpleData *m_simpledata;

    // Create junk model data
    m_simpledata = new SimpleData(true, "a1", "b1");
    m_data_list.append(m_simpledata);
    m_simpledata = new SimpleData(false, "a2", "b2");
    m_data_list.append(m_simpledata);
    data(index(0,0));
    connect(this, SIGNAL (clicked()), this, SLOT(setData(index, text)));
    //bool setData(const QModelIndex & index, const QVariant &value, int role = Qt::EditRole);
}
int MyModel::rowCount(const QModelIndex & /*parent*/) const {
   return 9;
}

int MyModel::columnCount(const QModelIndex & /*parent*/) const {
    return 9;
}
QVariant MyModel::data(const QModelIndex &index, int role) const {
    switch(role)
        {
            case RoleOne:
                return m_data_list.at(index.row())->enable;
            case RoleTwo:
                return m_data_list.at(index.row())->m_one;
            case RoleThree:
                return m_data_list.at(index.row())->m_two;
        }
    return QVariant();
}

bool MyModel::setData(const QModelIndex & index, const QVariant & value, int role) {
    switch(role)
       {
           case RoleOne:
               m_data_list[index.row()]->enable = value.toBool();
           case RoleTwo:
               m_data_list[index.row()]->m_one = value.toString();

           case RoleThree:
               m_data_list[index.row()]->m_two = value.toString();
       }
    return true;
}

QHash<int, QByteArray> MyModel::roleNames() const {

    QHash<int, QByteArray> roles;
    roles[RoleOne] = "role_enable";
    roles[RoleTwo] = "role_m_one";
    roles[RoleThree] = "role_m_two";
    return roles;
}
