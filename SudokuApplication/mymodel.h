#ifndef MYMODEL_H
#define MYMODEL_H
#include <QAbstractTableModel>


struct SimpleData {
    bool enable;
    QString m_one;
    QString m_two;

    SimpleData() {
        enable = true;
        m_one = "1";
        m_two = "2";
    }

    SimpleData(bool enable, const QString m_one, const QString m_two) :
    enable(enable), m_one(m_one), m_two(m_two) {}
};


class MyModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    MyModel(QObject *parent = 0);
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::EditRole) const;
    //bool setData(const QModelIndex & index, const QVariant &value, int role = Qt::EditRole);
    QHash<int, QByteArray> roleNames() const;

    QList<SimpleData*> m_data_list;

    enum MyRoles {
        RoleOne = Qt::UserRole + 1,
        RoleTwo,
        RoleThree
    };
private slots:
   bool setData(const QModelIndex & index, const QVariant &value, int role = Qt::EditRole);
};

#endif // MYMODEL_H


//public:
//    explicit QAbstractTableModel(QObject *parent = nullptr);
//    ~QAbstractTableModel();
//
//    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
//    QModelIndex sibling(int row, int column, const QModelIndex &idx) const override;
//    bool dropMimeData(const QMimeData *data, Qt::DropAction action,
//                      int row, int column, const QModelIndex &parent) override;
//
//    Qt::ItemFlags flags(const QModelIndex &index) const override;
//
//    using QObject::parent;
//
//protected:
//    QAbstractTableModel(QAbstractItemModelPrivate &dd, QObject *parent);
//
//private:
//    Q_DISABLE_COPY(QAbstractTableModel)
//    QModelIndex parent(const QModelIndex &child) const override;
//    bool hasChildren(const QModelIndex &parent) const override;





