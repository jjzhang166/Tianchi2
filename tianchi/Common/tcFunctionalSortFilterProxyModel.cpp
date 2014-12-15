#include "tcFunctionalSortFilterProxyModel.h"

class TcFunctionalSortFilterProxyModelPrivate
{
    Q_DECLARE_PUBLIC(TcFunctionalSortFilterProxyModel)
public:
    explicit TcFunctionalSortFilterProxyModelPrivate(
            TcFunctionalSortFilterProxyModel *qptr) : 
    func(NULL) // func(nullptr) // TODO C++11
    , q_ptr(qptr)
    {}
    ~TcFunctionalSortFilterProxyModelPrivate(){}

    QVariantMap param;
    // TODO C++11
    //std::function<bool(const QVariantMap &, const QModelIndex &)> func;
    TcFunctionalSortFilterProxyModelFilterFunction func;

    TcFunctionalSortFilterProxyModel* const q_ptr;
};

TcFunctionalSortFilterProxyModel::TcFunctionalSortFilterProxyModel(
        QObject * parent)
    : QSortFilterProxyModel(parent), 
    d_ptr(new TcFunctionalSortFilterProxyModelPrivate(this))
{
}

TcFunctionalSortFilterProxyModel::~TcFunctionalSortFilterProxyModel()
{
    delete d_ptr;
}

void TcFunctionalSortFilterProxyModel::setFilterFunction(
        TcFunctionalSortFilterProxyModelFilterFunction func)
        //std::function<bool(const QVariantMap &, const QModelIndex &)> func)
        // TODO C++11
{
    Q_D(TcFunctionalSortFilterProxyModel);
    d->func = func;
    invalidateFilter();
}

void TcFunctionalSortFilterProxyModel::setFilterParam(const QVariantMap &param)
{
    Q_D(TcFunctionalSortFilterProxyModel);
    d->param = param;
    invalidateFilter();
}

bool TcFunctionalSortFilterProxyModel::filterAcceptsRow(int source_row, 
        const QModelIndex &source_parent) const
{
    bool bOk = QSortFilterProxyModel::filterAcceptsRow(source_row, 
            source_parent);
    if (!bOk)
    {
        return bOk;
    }
    Q_D(const TcFunctionalSortFilterProxyModel);
    if (d->func)
    {
        bOk = d->func(d->param, 
                sourceModel()->index(source_row, 0, source_parent));
    }
    return bOk;
}

//#include "moc_tcFunctionalSortFilterProxyModel.cpp"
