#ifndef USERMODEL_H
#define USERMODEL_H

#include <QString>
#include <QCryptographicHash>
#include <QAbstractItemModel>
#include <QList>

struct User{
    long unsigned int _accountID;
    QString _userName;
    QCryptographicHash _passwordHash;
    QString _address;
    QString _email;
    unsigned short _age;
    unsigned int _resortNumber;
    bool _isMale;

    // bool operator overload to check if another User object is equal to this one
};

class UserModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    UserModel(QObject *parent = 0);
    UserModel(User user, QObject *parent = 0);

    int rowCount(const QModelIndex &parent)const override;
    int columnCount(const QModelIndex &parent)const override;
    QVariant data(const QModelIndex &index, int role)const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;
    bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;
    QList<User> getUsers() const;

private:
    QList<User> _users;
};

#endif // USERMODEL_H