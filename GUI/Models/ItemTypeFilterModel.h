#ifndef ITEMTYPEFILTERMODEL_H
#define ITEMTYPEFILTERMODEL_H

#include <QAbstractListModel>
#include <QStringList>

class Character;


class ItemFilter
{
public:
    explicit ItemFilter(const int index, const QString name) :
        index(index), name(name), active(false)
    {}

    int index;
    QString name;
    bool active;
};


class ItemTypeFilterModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum ItemTypeFilterRoles {
        IndexRole = Qt::UserRole + 1,
        DescriptionRole,
        ActiveRole
    };

    ItemTypeFilterModel(QObject *parent = 0);

    bool get_filter_active(const int filter) const;
    void toggle_single_filter(const int filter);
    Q_INVOKABLE void clearCurrentFiltersAndSelectSingleFilter(const int);
    void set_item_slot(const int item_slot);

    void set_character(Character* pchar);

    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    int item_slot;
    QList<ItemFilter> item_type_filters;
    Character* pchar;

    void add_item_type_filters();
    void add_armor_item_type_filters();
    void add_weapon_item_type_filters();
};

#endif // ITEMTYPEFILTERMODEL_H
