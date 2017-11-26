#ifndef GAME_H
#define GAME_H

#include <QObject>

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = nullptr);
    void createBoard();

private:
    QObject *game_view;
    QObject *game_canvas;

signals:

public slots:
};

#endif // GAME_H
