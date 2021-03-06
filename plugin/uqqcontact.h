#ifndef UQQCONTACT_H
#define UQQCONTACT_H

#include <QtQml>
#include "uqqcategory.h"
#include "uqqmember.h"

class UQQContact : public QObject
{
    Q_OBJECT
public:

    explicit UQQContact(QObject *parent = 0);
    ~UQQContact();

    void setContactData(const QVariantMap &map);
    void setOnlineBuddies(const QVariantList &list);
    QList<UQQCategory *> &categories();
    UQQCategory * getCategory(quint64 id);
    QHash<QString, UQQMember*> &members();
    UQQMember *member(const QString &uin);
    QList<UQQMember *> membersInCategory(quint64 id, bool sorted = false);
    void addMember(UQQMember *member);
    void setBuddyStatus(QString uin, int status, int clientType);

    void addSessMessage(UQQMessage *sessMessage);
    QList<UQQMessage *> getSessMessage(const QString &uin);

private:
    void setCategories(const QVariantList &list);
    void setMembers(const QVariantList &list);
    void setMarknames(const QVariantList &list);
    void setVipInfo(const QVariantList &list);
    void setNickname(const QVariantList &list);
    void addMemberToCategory(quint64 id, UQQMember *member);
signals:

public slots:

private:
    QList<UQQCategory *> m_categories;
    QHash<QString, UQQMember*> m_members;
    QList<UQQMessage *> m_sessMessages;
};

#endif // UQQCONTACT_H
