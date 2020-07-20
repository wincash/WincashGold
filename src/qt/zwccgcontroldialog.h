// Copyright (c) 2017-2018 The WINCASHGOLD developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZWCCGCONTROLDIALOG_H
#define ZWCCGCONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "zwccg/zerocoin.h"
#include "privacydialog.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class ZWccgControlDialog;
}

class CZWccgControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CZWccgControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CZWccgControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CZWccgControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class ZWccgControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZWccgControlDialog(QWidget *parent);
    ~ZWccgControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::ZWccgControlDialog *ui;
    WalletModel* model;
    PrivacyDialog* privacyDialog;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_PRECOMPUTE,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CZWccgControlWidgetItem;

private slots:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // ZWCCGCONTROLDIALOG_H
