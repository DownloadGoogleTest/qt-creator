/****************************************************************************
**
** Copyright (C) 2016 BogDan Vatra <bog_dan_ro@yahoo.com>
** Contact: https://www.qt.io/licensing/
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
****************************************************************************/

#pragma once

#include "androidextralibrarylistmodel.h"

#include <projectexplorer/buildstep.h>
#include <android/androidbuildapkstep.h>

#include <QWidget>

namespace QmakeAndroidSupport {
namespace Internal {

namespace Ui { class QmakeAndroidBuildApkWidget; }

class QmakeAndroidBuildApkWidget : public ProjectExplorer::BuildStepConfigWidget
{
    Q_OBJECT

public:
    explicit QmakeAndroidBuildApkWidget(Android::AndroidBuildApkStep *step);
    ~QmakeAndroidBuildApkWidget();

private:
    void createAndroidTemplatesButton();
    void addAndroidExtraLib();
    void removeAndroidExtraLib();
    void checkEnableRemoveButton();

private:
    Ui::QmakeAndroidBuildApkWidget *m_ui = nullptr;
    Android::AndroidBuildApkStep *m_step = nullptr;
    AndroidExtraLibraryListModel *m_extraLibraryListModel = nullptr;
    bool m_ignoreChange = false;

    // BuildStepConfigWidget interface
    QString summaryText() const final;
    QString displayName() const final;
};

} // namespace Internal
} // namespace QmakeAndroidSupport
