/***************************************************************************
 *   Copyright (C) 2011 by Glad Deschrijver                                *
 *     <glad.deschrijver@gmail.com>                                        *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, see <http://www.gnu.org/licenses/>.  *
 ***************************************************************************/

#include <QGuiApplication>
#include <QQuickView>
#include <qqml.h> // for qmlRegisterType

#include "orientation.h"

int main(int argc, char *argv[])
{
QGuiApplication app( argc, argv );

// Expose the Orientation class
qmlRegisterType<Orientation>( "GameComponents", 1, 0, "Orientation" );

QQuickView viewer;
viewer.setSource( QUrl( "qrc:///main.qml" ) );
viewer.show();

return app.exec();
}
