// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// JeVois Smart Embedded Machine Vision Toolkit - Copyright (C) 2018 by Laurent Itti, the University of Southern
// California (USC), and iLab at USC. See http://iLab.usc.edu and http://jevois.org for information about this project.
//
// This file is part of the JeVois Smart Embedded Machine Vision Toolkit.  This program is free software; you can
// redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software
// Foundation, version 2.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
// without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
// License for more details.  You should have received a copy of the GNU General Public License along with this program;
// if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
//
// Contact information: Laurent Itti - 3641 Watt Way, HNB-07A - Los Angeles, CA 90089-2520 - USA.
// Tel: +1 213 740 3527 - itti@pollux.usc.edu - http://iLab.usc.edu - http://jevois.org
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Config.H"

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QComboBox>
#include <QTimer>

#include "HistoryLineEdit.H"

class Serial;

class Console : public QWidget
{
    Q_OBJECT
    
  public:
    explicit Console(Serial * serport, QWidget * parent = 0);
    ~Console();
    void updateUI(QStringList const & data);
    void tabselected();
    void tabunselected();
    void updateCmdInfo(std::map<QString /* command */, QString /* description */> cmd,
                       std::map<QString /* command */, QString /* description */> modcmd);

  private slots:
    void enterPressed();
    void lineExecuted(QString str);
    void readDataReady();
    
  private:
    Serial * m_serial;
    QPushButton m_serlogusb;
    QPushButton m_serloghard;
    QPushButton m_seroutusb;
    QPushButton m_serouthard;
    QComboBox m_serstyle;
    QPlainTextEdit m_log;
    HistoryLineEdit m_input;
    QPushButton m_enter;
    QLabel m_cmdinfo;
    QTextCharFormat cf_cmd;
    QTextCharFormat cf_serout;
    QTextCharFormat cf_ok;
    QTextCharFormat cf_dbg;
    QTextCharFormat cf_inf;
    QTextCharFormat cf_err;
    QTextCharFormat cf_ftl;

    QTimer m_timer;
};
